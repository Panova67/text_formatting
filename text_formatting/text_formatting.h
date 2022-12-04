#pragma once

//������������ ������ ������ �� ������� �����
const int MaxSizeOfInputText = 2000;
//������������ ������ ����� ��� ������ � ����������
const int MaxSizeOfOutputStrings = 134;
//������������ ����� ������ ��� ������ � ����������
const int MaxLengthOfOutputStrings = 21;

using namespace std;


/*	�������� ����� �� �������� �����
*	\param[in] textFile - �������� ���������� �����
*	\return �����, ���������� �� �����
*/
string getInputData(string textFile);


/*	��������� ���������� ������ �� ������������
*	\param[in] inputData - ����� �������� �����
*	\return ������� ������������� �������
*/
int checkingStringForCorrectness(string inputData);


/*  ��������� ����� �� �������� ����� �� ������� ������
*   \param[in] inputData - ����� �������� �����
*   \param[out] incorrect�haracter - ������� ������������� �������
*/
int checkTextInputData(string inputData, int& incorrect�haracter);


/*  ����� ������� �������� � ������ ����������
*   \param[in] inputData - ����� �������� �����
*   \param[in] search - ����� ���������� ��������-������������
*   \param[out] size - ������ ������� ������������
*   \return ������ ������������
*/
int* findPositionOfSeparatingCharacters(string inputData, char* search, int& size);


/*  ���������� � ��������� ��������� � ����� ��� ������
*   \param[in] inputData - ����� �������� �����
*   \param[in] lengthSubstring - ����� ���������, ����� ������ ������� ���������� �����������
*   \param[in] beginPosition - ��������� ������� ��������� ��� �����������
*   \param[out] nextPosition - ��������� ��������� ������� ���������
*   \return ����� ������ �� ������
*/
string copySubstring(string inputData, int lengthSubstring, int beginPosition, int& nextPosition);


/*  ������� ����� �� ������ � ����������
*   \param[in] inputData - ����� �������� �����
*   \param[out] sizeStrings - ������ ����� ��� ������
*   \return ������������ ������
*/
string* splitText(string inputData, int& sizeStrings);


/*  ����������� �� ������
*   \param[in] String - ������, ������� ���������� ������������� �� ������ ������������� ���������
*   \param[in] lengthString - ����� ������ ������
*   \param[in] positionsOfSpaces - ������� �������� ������ ������
*   \param[in] numberOfSpaces - ���������� �������� � ������ ������
*   \return ��������������� �� ������ ������
*/
string sortingByWidth(string String, int lengthString, int* positionsOfSpaces, int numberOfSpaces);


/*  ������������ ����� � ���������� �� ������
*   \param[in] inputData - ����� �������� �����
*   \param[out] sizeStrings - ������ ����� ��� ������
*   \return ����������������� �� ������ ������ � ����������
*/
string* textProcessing(string inputData, int& sizeStrings);


/*  �������� ������ ����� � �������� ����
*   \param[in] outputData - �����, ����������������� �� ������, � ����������
*   \param[in] sizeStrings - ������ ���� ����� ��� ������
*   \return ���������� ������ ���������
*/
int writeOutputData(string* outputData, int sizeStrings);
