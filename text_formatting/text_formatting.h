#pragma once

//������������ ������ ������ �� ������� �����
const int MaxSizeOfInputText = 2000;
//������������ ������ ����� ��� ������ � ����������
const int MaxSizeOfOutputStrings = 134;
//������������ ����� ������ ��� ������ � ����������
const int MaxLengthOfOutputStrings = 21;

using namespace std;


/*	�������� ����� �� �������� �����
*	\return �����, ���������� �� �����
*/
string getInputData();


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
*   \param[in] length - ����� ���������, ����� ������ ������� ���������� ������������
*   \param[in] begin - ��������� ������� ��������� ��� �����������
*   \param[out] nextPosition - ��������� ��������� ������� ���������
*   \return ����� ������ �� ������
*/
string copySubstring(string inputData, int length, int begin, int& nextPosition);


/*  ������� ����� �� ������ � ����������
*   \param[in] inputData - ����� �������� �����
*   \param[out] sizeStrings - ������ ����� ��� ������
*   \return ������������ ������
*/
string* splitText(string inputData, int& sizeStrings);


/*  ����������� �� ������
*   \param[in] String - ������, ������� ���������� ������������� �� ������ ������������� ���������
*   \param[in] length - ����� ������ ������
*   \param[in] positionsOfSpaces - ������� �������� ������ ������
*   \param[in] numberOfSpaces - ���������� �������� � ������ ������
*   \return ��������������� �� ������ ������
*/
string sortingByWidth(string String, int length, int* positionsOfSpaces, int numberOfSpaces);


/*  ������������ ����� � ���������� �� ������
*   \param[in] inputData - ����� �������� �����
*   \param[out] sizeStrings - ������ ����� ��� ������
*   \return ����������������� �� ������ ������ � ���������
*/
string* textProcessing(string inputData, int& sizeStrings);


/*  �������� ������ ����� � �������� ����
*   \param[in] outputData - ����������������� �� ������ ������ � ���������
*   \param[in] sizeStrings - ������ ���� ����� ��� ������
*   \return ���������� ������ ���������
*/
int writeOutputData(string* outputData, int sizeStrings);
