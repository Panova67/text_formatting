#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MaxSizeOfInputText = 2000;
const int MaxSizeOfOutputStrings = 134;
const int MaxLengthOfOutputStrings = 21;

//Получить текст из входного файла
string getInputData() {
    string textFile = "input.txt";
    ifstream file;
    string inputData; //данные от входного файла

    //Получить текст из файла
    file.open(textFile); // Открываем файл
    if (!file.is_open()) // Если введено не корректное имя файла
    {   cout << "Ошибка: Файл не может быть открыт!" << endl;
    }
    else {
        if (textFile.empty()) // Проверить есть ли в файле текст
        {   
            cout << "Ошибка: В файле нет текста" << endl;
        }
        else {
            while (!file.eof()) {
                getline(file, inputData);
            }
        }
    }
    file.close(); // Закрываем файл

    //Вернуть текст, полученный из файла
    return inputData;
}

//Проверить содержимое строки на корректность
int checkingStringForCorrectness(string inputData) {
    int error = 1; 
    // Поддерживаемые символы: кириллица, латиница, знаки препинания, арифметические знаки, цифры
    string correctСharacters = { "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюяABCDEFGHIKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvwxyz .,!?…«»()-:;'\"+-*=/><%[]{}≈№1234567890" };
    
    //Для каждого символа строки
    for (int i = 0; inputData[i] != '\0'; i++)
    {
        //Вернуть код ошибки типа "Некорректный символ", если найден символ, который
        //не является кириллицей, латиницей, цифрой, знаком препинания и арифметическим знаком
        if (correctСharacters.find(inputData[i]) == string::npos) {
            cout << "Ошибка: Некорректный символ " << inputData[i] << endl;
            error = 0;
            break;
        }
    }

    //Вернуть код без ошибки
    return error;
}

//Проверить текст из входного файла
int checkTextInputData(string inputData) {
    int error = 0;

    //Выдать ошибку, если размер строки не соответствует разрешенному диапазону
    if (inputData.length() > MaxSizeOfInputText) {
        cout << "Ошибка: Размер строки не соответствует разрешенному диапазону (2000)" << endl;
    }

    //Выдать ошибку, если содержимое строки не корректно…
    //if(!checkingStringForCorrectness(inputData)){ return 1;}

    return error;
}

//Найти позиции пробелов и знаков препинания
int* findPositionOfSeparatingCharacters(string inputData, int& size) {
    int arrayOfSeparatingCharacters[MaxSizeOfInputText]; //массив позиций пробелов или знаков препинания
    char search[] = { ".,!?…»)-:; " };
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
    nextPosition = length + begin;

    //Сохранить подстроку в текст для выхода
    string outputData = substring;

    //Вернуть часть строки из текста
    return outputData;
}

/*
//Разбить текст на строки с переносами
string splitText() {
    //Для каждой позиции разделителей из массива...
    {
        //Если разделитель является последним в тексте,
            //Скорпировать последную подстроку до конца в текст последней строки
            //Иначе проверить попадает ли этот разделитель по требованию диапазона, чтобы следующий разделитель не находился совместно с ним в одном диапазоне
                //Скорпировать подстроку до данного разделителя включительно и вставить отдельную строку
                //Иначе если данный разделитель не попадает в данном диапазоне, т.е меньше, чем требуется, при этом следующий находится за пределом диапазона,
                    //То скорпировать подстроку до длины максимального диапазона в отдельную строку
    }

    //Вернуть перенесенные строки
    return outputData;
}*/


//Расставить в строке переносы
string* stringProcessing(string inputData, int& sizeStrings) {
    //Находить позиции для разделения строки по группам...
    int* arrayOfSeparatingCharacters = {}, size;
    arrayOfSeparatingCharacters = findPositionOfSeparatingCharacters(inputData, size);

    string* outputData = new string[MaxSizeOfOutputStrings];
    sizeStrings = 0;

    //Для каждой позиции разделителей из массива...
    for (int i = 0, begin = 0; i < size; i++) {
        //Если разделитель является последним в тексте,
        if (i == size - 1) {
            //Скорпировать все символы до конца и завершить работу
            outputData[sizeStrings] = copySubstring(inputData, arrayOfSeparatingCharacters[i] - begin + 1, begin, begin);
            sizeStrings++;
        }

        //Проверить попадает ли этот разделитель по требованию диапазона, чтобы следующий разделитель не был совместно с ним находился в одном диапазоне
        if (arrayOfSeparatingCharacters[i] - begin >= 14 && arrayOfSeparatingCharacters[i] - begin <= 19 && arrayOfSeparatingCharacters[i + 1] - begin > 19) {
            //Скорпировать до данного разделителя, включительно, и вставить отдельную строку
            outputData[sizeStrings] = copySubstring(inputData, arrayOfSeparatingCharacters[i] - begin + 1, begin, begin);
            sizeStrings++;

        }
        //Иначе 
        else
            //Eсли данный разделитель не попадает в данном диапазоне, т.е меньше, чем требуется, при этом следующий находится за пределом диапазона,
            if (arrayOfSeparatingCharacters[i] - begin < 14 && arrayOfSeparatingCharacters[i + 1] - begin > 19) {
                //То скорпировать все до максимального диапазона в отдельную строку
                outputData[sizeStrings] = copySubstring(inputData, 20, begin, begin);
                sizeStrings++;
            }
    }

    //Вернуть перенесенные строки
    return outputData;
 }



/*
//Записать массив строк в выходной файл
int writeOutputData(string outputData) {
    //Вывести результирующий текст в консоль
    cout << outputData << endl;

    //Завершить работу программы
    return 0;
}*/


int main(const int argc, char** argv) {
    setlocale(LC_ALL, "rus");

    string inputData, //данные от входного файла
        *outputData; //текст для выходного файла

    //Получить текст из входного файла...
    inputData = getInputData();
    
//----------------------------    
    //Выдать ошибку, если входной файл не указан в аргументах командной строки
    //Выдать ошибку, если входной файл невозможно открыть
    
    //checkTextInputData(inputData);
    
    //Если есть ошибка
    //{
        //Распечатать её в консоль ошибок
        //Завершить работу программы
    //}
    
 //----------------------------
    int sizeStrings;
    outputData = stringProcessing(inputData, sizeStrings);

    cout << "\nКопирование строк:\n\n";
    for (int i = 0; i < sizeStrings; i++) {
        cout << outputData[i] << endl;
    }

//----------------------------
    /*
    //Записать массив строк в выходной файл...
    writeOutputData(outputData);
    */

    return 0;
}
