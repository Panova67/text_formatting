#pragma once

//Максимальный размер текста во входном файле
const int MaxSizeOfInputText = 2000;
//Максимальный размер строк для текста с переносами
const int MaxSizeOfOutputStrings = 134;
//Максимальная длина строки для текста с переносами
const int MaxLengthOfOutputStrings = 21;

using namespace std;


/*	Получить текст из входного файла
*	\return текст, полученный из файла
*/
string getInputData();


/*	Проверить содержимое строки на корректность
*	\param[in] inputData - текст входного файла
*	\return позиция некорректного символа
*/
int checkingStringForCorrectness(string inputData);


/*  Проверить текст из входного файла на наличие ошибок
*   \param[in] inputData - текст входного файла
*   \param[out] incorrectСharacter - позиция некорректного символа
*/
int checkTextInputData(string inputData, int& incorrectСharacter);


/*  Найти позиции пробелов и знаков препинания
*   \param[in] inputData - текст входного файла
*   \param[in] search - поиск конкретных символов-разделителей
*   \param[out] size - размер массива разделителей
*   \return массив разделителей
*/
int* findPositionOfSeparatingCharacters(string inputData, char* search, int& size);


/*  Копировать и сохранить подстроку в текст для выхода
*   \param[in] inputData - текст входного файла
*   \param[in] length - длина подстроки, часть текста которую собираемся скорпировать
*   \param[in] begin - начальная позиция подстроки для копирования
*   \param[out] nextPosition - следующая начальная позиция подстроки
*   \return часть строки из текста
*/
string copySubstring(string inputData, int length, int begin, int& nextPosition);


/*  Разбить текст на строки с переносами
*   \param[in] inputData - текст входного файла
*   \param[out] sizeStrings - размер строк для выхода
*   \return перенесенные строки
*/
string* splitText(string inputData, int& sizeStrings);


/*  Сортировать по ширине
*   \param[in] String - строка, которую собираемся форматировать по ширине максимального диапазона
*   \param[in] length - длина данной строки
*   \param[in] positionsOfSpaces - позиция пробелов данной строки
*   \param[in] numberOfSpaces - количество пробелов в данной строке
*   \return форматированная по ширине строка
*/
string sortingByWidth(string String, int length, int* positionsOfSpaces, int numberOfSpaces);


/*  Обрабатывать текст с переносами по ширине
*   \param[in] inputData - текст входного файла
*   \param[out] sizeStrings - размер строк для выхода
*   \return отформатированные по ширине строки с перносами
*/
string* textProcessing(string inputData, int& sizeStrings);


/*  Записать массив строк в выходной файл
*   \param[in] outputData - отформатированные по ширине строки с перносами
*   \param[in] sizeStrings - размер этих строк для выхода
*   \return завершение работы программы
*/
int writeOutputData(string* outputData, int sizeStrings);
