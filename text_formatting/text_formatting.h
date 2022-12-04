#pragma once

//Максимальный размер текста во входном файле
const int MaxSizeOfInputText = 2000;
//Максимальный размер строк для текста с переносами
const int MaxSizeOfOutputStrings = 134;
//Максимальная длина строки для текста с переносами
const int MaxLengthOfOutputStrings = 21;

using namespace std;


/*	Получить текст из входного файла
*	\param[in] textFile - название текстового файла
*	\return текст, полученный из файла
*/
string getInputData(string textFile);


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
*   \param[in] lengthSubstring - длина подстроки, часть текста которую собираемся скопировать
*   \param[in] beginPosition - начальная позиция подстроки для копирования
*   \param[out] nextPosition - следующая начальная позиция подстроки
*   \return часть строки из текста
*/
string copySubstring(string inputData, int lengthSubstring, int beginPosition, int& nextPosition);


/*  Разбить текст на строки с переносами
*   \param[in] inputData - текст входного файла
*   \param[out] sizeStrings - размер строк для выхода
*   \return перенесенные строки
*/
string* splitText(string inputData, int& sizeStrings);


/*  Сортировать по ширине
*   \param[in] String - строка, которую собираемся форматировать по ширине максимального диапазона
*   \param[in] lengthString - длина данной строки
*   \param[in] positionsOfSpaces - позиция пробелов данной строки
*   \param[in] numberOfSpaces - количество пробелов в данной строке
*   \return форматированная по ширине строка
*/
string sortingByWidth(string String, int lengthString, int* positionsOfSpaces, int numberOfSpaces);


/*  Обрабатывать текст с переносами по ширине
*   \param[in] inputData - текст входного файла
*   \param[out] sizeStrings - размер строк для выхода
*   \return отформатированные по ширине строки с переносами
*/
string* textProcessing(string inputData, int& sizeStrings);


/*  Записать массив строк в выходной файл
*   \param[in] outputData - текст, отформатированный по ширине, с переносами
*   \param[in] sizeStrings - размер этих строк для выхода
*   \return завершение работы программы
*/
int writeOutputData(string* outputData, int sizeStrings);
