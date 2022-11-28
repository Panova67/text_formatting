#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MaxSizeOfInputText = 2000;
const int MaxSizeOfOutputStrings = 134;
const int MaxLengthOfOutputStrings = 21;

//Получить текст из входного файла
string getInputData() {
    string textFile = "input.txt"; //Название текстового файла
    ifstream file;      //Файл, которого мы будем открывать
    string inputData;   //Данные от входного файла

    //Открываем файл
    file.open(textFile);

    //Выдать код ошибки, если введено не корректное имя файла
    if (!file.is_open()) {
        throw 1;
    }
    //Иначе проверить есть ли в файле текст
    else {
        //Выдать код ошибки, если в файле нет текста
        if (textFile.empty()) {
            throw 2;
        }
        //Иначе получить текст из файла
        else {
            while (!file.eof()) {
                getline(file, inputData);
            }
        }
    }

    //Закрываем файл
    file.close();

    //Вернуть текст, полученный из файла
    return inputData;
}


//Проверить содержимое строки на корректность
int checkingStringForCorrectness(string inputData) {
    int incorrectСharacter = -1; //Позиция некорректного символа

    //Поддерживаемые символы: кириллица, латиница, знаки препинания, арифметические знаки, цифры
    string correctСharacters = { "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюяABCDEFGHIKLMNOPQRSTVXYZabcdefghijklmnopqrstuvwxyz .,!?…«»()-:;'\"+-*=/><%[]{}≈№1234567890" };

    //Для каждого символа строки проверить, является ли тот кириллицей, латиницей, цифрой, знаком препинания и арифметическим знаком
    for (int i = 0; inputData[i] != '\0'; i++)
    {
        //Если найден некорректный символ, сохранить его позицию и прервать работу
        if (correctСharacters.find(inputData[i]) == string::npos) {
            incorrectСharacter = i;
            break;
        }
    }

    //Вернуть позицию некорректного символа
    return incorrectСharacter;
}


//Проверить текст из входного файла на наличие ошибок
int checkTextInputData(string inputData, int& incorrectСharacter) {
    //Выдать код ошибки, если размер текста не соответствует разрешенному диапазону
    if (inputData.length() > MaxSizeOfInputText) { throw 3; }

    //Выдать код ошибки, если содержимое текста не корректно...
    incorrectСharacter = checkingStringForCorrectness(inputData);
    if (incorrectСharacter != -1) { throw 4; }

}


//Найти позиции пробелов и знаков препинания
int* findPositionOfSeparatingCharacters(string inputData, char* search, int& size) {
    int arrayOfSeparatingCharacters[MaxSizeOfInputText]; //Массив позиций пробелов или знаков препинания
    size = 0;

    //Для каждого символа строки
    for (int i = 0; inputData[i] != '\0'; i++)
    {
        //Если текущий символ — знак препинания или пробел, или последний символ строки
        if (strchr(search, inputData[i]) != NULL || i == inputData.length() - 1)
        {
            //Добавить в массив индекс текущего символа
            arrayOfSeparatingCharacters[size] = i;
            size++;
        }
    }

    //Вернуть массив разделителей
    return arrayOfSeparatingCharacters;
}


//Копировать и сохранить подстроку в текст для выхода
string copySubstring(string inputData, int length, int begin, int& nextPosition) {
    //Скорпировать часть текста конкретной длины
    char substring[MaxLengthOfOutputStrings];
    size_t size = inputData.copy(substring, length, begin);
    substring[size] = '\0';

    nextPosition = begin + length; //Сохраняем следующую начальную позицию

    //Сохранить подстроку в текст для выхода
    string outputData = substring;

    //Вернуть часть строки из текста
    return outputData;
}


//Разбить текст на строки с переносами
string* splitText(string inputData, int& sizeStrings) {
    int* arrayOfSeparatingCharacters = {}, sizeArray; //Массив позиции каждого разделителя и его размер
    char separatingCharacters[] = { ".,!?…»)-:; " }; //Разделительные символы

    //Находить позиции для разделения строки по группам...
    arrayOfSeparatingCharacters = findPositionOfSeparatingCharacters(inputData, separatingCharacters, sizeArray);

    string* outputData = new string[MaxSizeOfOutputStrings]; //Текст с переносами
    sizeStrings = 0;

    //Для каждой позиции разделителей из массива...
    for (int i = 0, begin = 0; i < sizeArray; i++) {
        //Если разделитель является последним в тексте,
        if (i == sizeArray - 1) {
            //Скорпировать последную подстроку до конца в текст последней строки...
            outputData[sizeStrings] = copySubstring(inputData, arrayOfSeparatingCharacters[i] - begin + 1, begin, begin);
            sizeStrings++;
        }
        else
            //Иначе проверить попадает ли этот разделитель по требованию диапазона, чтобы следующий разделитель не находился совместно с ним в одном диапазоне
            if (arrayOfSeparatingCharacters[i] - begin >= 14 && arrayOfSeparatingCharacters[i] - begin <= 19 && arrayOfSeparatingCharacters[i + 1] - begin > 19) {
                //Скорпировать подстроку до данного разделителя включительно и вставить отдельную строку...
                outputData[sizeStrings] = copySubstring(inputData, arrayOfSeparatingCharacters[i] - begin + 1, begin, begin);
                sizeStrings++;
            }
            else
                //Иначе если данный разделитель не попадает в данном диапазоне, т.е меньше, чем требуется, при этом следующий находится за пределом диапазона,
                if (arrayOfSeparatingCharacters[i] - begin < 14 && arrayOfSeparatingCharacters[i + 1] - begin > 19) {
                    //То скорпировать подстроку до длины максимального диапазона в отдельную строку...
                    outputData[sizeStrings] = copySubstring(inputData, 20, begin, begin);
                    sizeStrings++;
                }
    }

    //Вернуть перенесенные строки
    return outputData;
}


//Сортировать по ширине
string sortingByWidth(string String, int length, int* positionsOfSpaces, int numberOfSpaces) {
    string newString,	//Отформатированная по ширине строка
        spaces,         //Пробелы
        substringBegin, //Правая часть строки
        substringEnd;	//Левая часть строки

    //Пока длина данной строки не достигнет до максимального диапазона
    for (int i = 0, next; length < MaxLengthOfOutputStrings - 1; i++) {
        //Если позиции пробелов закончены, то возращаемся к первому позиции
        if (i > numberOfSpaces - 1) { i = 0; }

        //Сохраняем первую и вторую часть строки, где их отделяет пробел...
        substringBegin = copySubstring(String, positionsOfSpaces[i] + 1, 0, next);
        substringEnd = copySubstring(String, length - next, next, next);

        //Ставим между ними дополнительный пробел, увеличивая длину
        if (i == 0) { spaces = spaces + ' '; }
        length++;
        newString = substringBegin + spaces + substringEnd;
    }

    //Вернуть форматированную по ширине строку
    return newString;
}


//Обрабатывать текст с переносами по ширине
string* textProcessing(string inputData, int& sizeStrings) {
    string* outputData; //Текст с переносами

    //Разбить текст на строки с переносами...
    outputData = splitText(inputData, sizeStrings);

    int* arrayOfSpaces = {}, sizeArray; //Массив пробелов и его размер
    char space[] = { ' ' };

    //Для каждой строки, не являющейся последней (т.к. мы оставляем последную строку неизменяемым),
    for (int i = 0; i < sizeStrings - 1; i++) {
        //Находить позиции пробелов каждой строки...
        arrayOfSpaces = findPositionOfSeparatingCharacters(outputData[i], space, sizeArray);

        //Если последний символ строки не является пробелом,
        if (outputData[i][arrayOfSpaces[sizeArray - 1]] != ' ') {
            //Удалить эту позицию из массива, уменьшив его размер
            arrayOfSpaces[sizeArray - 1] = '\0';
            sizeArray--;
        }

        int lengthData = outputData[i].length(); //Длина данной строки

        //Если последний символ является пробелом,
        if (outputData[i][arrayOfSpaces[sizeArray - 1]] == ' ') {
            //Удалить эту позицию из массива, уменьшив его размер, и сократить длину строки
            arrayOfSpaces[sizeArray - 1] = '\0';
            sizeArray--;
            lengthData--;
        }

        //Если в строке, которая меньше максимального диапазона, стоит не одно слово, и между ними разделяют пробелы,
        if (sizeArray > 0 && lengthData < MaxLengthOfOutputStrings - 1) {
            //Сортировать по ширине...
            outputData[i] = sortingByWidth(outputData[i], lengthData, arrayOfSpaces, sizeArray);
        }
    }

    //Вернуть отформатированные по ширине строки с перносами
    return outputData;
}


//Записать массив строк в выходной файл
int writeOutputData(string* outputData, int sizeStrings) {
    //Вывести результирующий текст в консоль
    for (int i = 0; i < sizeStrings; i++) {
        cout << "|" << outputData[i] << "|\n";
    }

    //Завершить работу программы
    return 0;
}


int main(const int argc, char** argv) {
    setlocale(LC_ALL, "rus"); //Русский язык в консоль

    string inputData,   //Данные от входного файла
        * outputData;   //Текст для выходного файла
    int sizeStrings;    //Размер строк текста с переносами
    int incorrectСharacter; //Позиция некорректного символа

    try {
        //Получить текст из входного файла...
        inputData = getInputData();

        //Проверить текст из входного файла на наличие ошибок...
        checkTextInputData(inputData, incorrectСharacter);
    }
    //Если есть ошибка, распечатать её в консоль ошибок и завершить работу программы
    catch (int error) {
        //Выдать ошибку, если входной файл невозможно открыть
        if (error == 1) { cout << "Ошибка: Файл не может быть открыт!" << endl; }

        //Выдать ошибку, если в входном тексте нет текста
        if (error == 2) { cout << "Ошибка: В файле нет текста" << endl; }

        //Выдать ошибку, если размер текста не соответствует разрешенному диапазону
        if (error == 3) { cout << "Ошибка: Размер строки не соответствует разрешенному диапазону (2000)" << endl; }

        //Выдать ошибку, если содержимое текста не корректно
        if (error == 4) { cout << "Ошибка: Некорректный символ \"" << inputData[incorrectСharacter] << "\"\n"; }

        return 0;
    }

    //Обрабатывать текст с переносами по ширине...
    outputData = textProcessing(inputData, sizeStrings);

    //Записать массив строк в выходной файл...
    writeOutputData(outputData, sizeStrings);

    return 0;
}
