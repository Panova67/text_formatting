﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MaxSize = 2000;

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
    string correctСharacters = { "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯбвгдеёжзийклмнопрстуфхцчшщъыьэюяABCDEFGHIKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvwxyz .,!?…«»()-:;'\"+-*=/><%[]{}≈№1234567890" };
    //а
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

//Найти позиции пробелов и знаков препинания
int  *findPositionOfSeparatingCharacters(string inputData, int& size) {
    int arrayOfSeparatingCharacters[MaxSize]; //массив позиций пробелов или знаков препинания
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

/*
//Разделить строку с переносами
string stringBreak(string inputData, int arrayOfSeparatingCharacters) {
    //Для каждой позиции разделителей из массива...
    {
        //Проверить позицию пробела и знака препинания, стоит ли перед буквенным символом
        {
            //Копировать все символы, стоящие слева до текущей позиции, в массив для строк
        }
        //Является ли позиция последним символом текущей строки
        {
            //Копировать все символы, стоящие слева до текущей позиции, в массив для строк
        }
    }
    //Вернуть перенесенные строки
    return inputData;
}*/

//Расставить в строке переносы
string stringProcessing(string inputData) {
    //Выдать ошибку, если размер строки не соответствует разрешенному диапазону
    if (inputData.length() > MaxSize) {
        cout << "Ошибка: Размер строки не соответствует разрешенному диапазону (2000)" << endl;
    } 
    
    //Выдать ошибку, если содержимое строки не корректно…
    //if(!checkingStringForCorrectness(inputData)){ return 1;}

    //Находить позиции для разделения строки по группам...
    int* arrayOfSeparatingCharacters = {}, size;
    arrayOfSeparatingCharacters = findPositionOfSeparatingCharacters(inputData, size);

    //Разделить строку с переносами...
    //inputData = stringBreak(inputData, *arrayOfSeparatingCharacters);

    //Вернуть перенесенные строки
    return inputData;
 }

/*
//Соединить перенесенные строки на массив строк по длине 15-20 символов
string groupStrings(string inputData) {
    //Создать результирующий массив строк
    //Для каждой строки и её следующие строки, длина которых удовлетворяет лимиту и которых n - следующая строка не равна лимиту
    {
        //Копировать из группы - строк той количество, которое при сложении символов строк удовлетворяет лимиту, в результирующий массив
    }
    //Добавить группу строк в результирующий массив, если она находится в конце строки и ее длина меньше лимита
    //Вернуть результирующий массив
}*/

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
        outputData; //текст для выходного файла

    //Получить текст из входного файла...
    inputData = getInputData();
    
//----------------------------    
    //Выдать ошибку, если входной файл не указан в аргументах командной строки
    //Выдать ошибку, если входной файл невозможно открыть
    
    //Расставить в строке переносы...
    inputData = stringProcessing(inputData);

    //Если есть ошибка
    //{
        //Распечатать её в консоль ошибок
        //Завершить работу программы
    //}
 //----------------------------
    
    /*
    //Соединить перенесенные строки на массив строк по длине 15 - 20 символов...
    outputData = groupStrings(inputData);
    
    //Записать массив строк в выходной файл...
    writeOutputData(outputData);
    */

    return 0;
}
