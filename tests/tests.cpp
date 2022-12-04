#include "pch.h"
#include "CppUnitTest.h"
#include "..\text_formatting\text_formatting.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(Test_getInputData)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			try {
				string text = getInputData("testhlugyg");
			}
			catch (int error) {
				Assert::AreEqual(1, error);
			}
		}

		TEST_METHOD(TestMethod2)
		{
			string text;
			try {
				text = getInputData("test1.txt");
			}
			catch (int error) {
				Assert::AreEqual(2, error);
			}
		}

		TEST_METHOD(TestMethod3)
		{
			string text;
			try {
				text = getInputData("test2.txt");
			}
			catch (int error) {}
			
			Assert::AreEqual((string)"VSTU_was founded in 1930", text);
		}
	};

	TEST_CLASS(Test_checkingStringForCorrectness)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(-1, checkingStringForCorrectness("It's VSTU"));
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(4, checkingStringForCorrectness("It's_VSTU"));
		}

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(0, checkingStringForCorrectness("_It's VSTU"));
		}

		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual(9, checkingStringForCorrectness("It's VSTU_"));
		}

		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual(-1, checkingStringForCorrectness("Это - Политех"));
		}

		TEST_METHOD(TestMethod6)
		{
			Assert::AreEqual(-1, checkingStringForCorrectness("Основан в 1930 году."));
		}

	};

	TEST_CLASS(Test_checkTextInputData)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int incorrectСharacter;

			try {
				checkTextInputData("It's_VSTU", incorrectСharacter);
			}
			catch (int error) {
				Assert::AreEqual(4, error);
			}
		}

		TEST_METHOD(TestMethod2)
		{
			string text = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu";
			int incorrectСharacter;

			try {
				checkTextInputData(text, incorrectСharacter);
			}
			catch (int error) {
				Assert::AreEqual(3, error);
			}
		}
	};

	TEST_CLASS(Test_findPositionOfSeparatingCharacters)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int* arr = {}, size;
			char search[] = { " .,!?…»)-—:;+-*=/><%]}" };
			arr = findPositionOfSeparatingCharacters("It's VSTU", search, size);

			int exc_arr[] = { 4, 8 };

			for (int i = 0; i < size; i++) {
				Assert::AreEqual(exc_arr[i], arr[i]);
			}
		}

		TEST_METHOD(TestMethod2)
		{
			int* arr = {}, size;
			char search[] = { " .,!?…»)-—:;+-*=/><%]}" };
			arr = findPositionOfSeparatingCharacters("hello", search, size);

			int exc_arr[] = { 4 };

			for (int i = 0; i < size; i++) {
				Assert::AreEqual(exc_arr[i], arr[i]);
			}
		}

		TEST_METHOD(TestMethod3)
		{
			int* arr = {}, size;
			char search[] = { " .,!?…»)-—:;+-*=/><%]}" };
			arr = findPositionOfSeparatingCharacters("!hello", search, size);

			int exc_arr[] = { 0, 5 };

			for (int i = 0; i < size; i++) {
				Assert::AreEqual(exc_arr[i], arr[i]);
			}
		}

		TEST_METHOD(TestMethod4)
		{
			int* arr = {}, size;
			char search[] = { " .,!?…»)-—:;+-*=/><%]}" };
			arr = findPositionOfSeparatingCharacters("VSTU was founded in 1930", search, size);

			int exc_arr[] = {4, 8, 16, 19};

			for (int i = 0; i < size; i++) {
				Assert::AreEqual(exc_arr[i], *(arr+i));
			}
		}
	};

	TEST_CLASS(Test_copySubstring)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int begin = 0;
			Assert::AreEqual((string)"VSTU", copySubstring("VSTU was founded in 1930", 4, begin, begin));
		}

		TEST_METHOD(TestMethod2)
		{
			int begin = 5;
			Assert::AreEqual((string)"was", copySubstring("VSTU was founded in 1930", 3, begin, begin));
		}

		TEST_METHOD(TestMethod3)
		{
			int begin = 20;
			Assert::AreEqual((string)"1930", copySubstring("VSTU was founded in 1930", 4, begin, begin));
		}
	};

	TEST_CLASS(Test_splitText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int sizeStrings;
			string* strings = splitText("VSTU was founded in 1930", sizeStrings);
			string exp_strings[2] = {"VSTU was founded in ", "1930"};

			for (int i = 0; i < sizeStrings; i++) {
				Assert::AreEqual(exp_strings[i], strings[i]);
			}
		}

		TEST_METHOD(TestMethod2)
		{
			int sizeStrings;
			string* strings = splitText("It's VSTU", sizeStrings);
			string exp_strings[1] = { "It's VSTU" };

			for (int i = 0; i < sizeStrings; i++) {
				Assert::AreEqual(exp_strings[i], strings[i]);
			}
		}

		TEST_METHOD(TestMethod3)
		{
			int sizeStrings;
			string* strings = splitText("0A human thought 1fixed on some 2material medium; 3in general, a 4coherent and comple5te sequence of 6symbols.", sizeStrings);
			string exp_strings[7] = { "0A human thought ", "1fixed on some ", "2material medium; ",
				"3in general, a " , "4coherent and comple" , "5te sequence of " , "6symbols." };

			for (int i = 0; i < sizeStrings; i++) {
				Assert::AreEqual(exp_strings[i], strings[i]);
			}
		}
	};

	TEST_CLASS(Test_sortingByWidth)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arrayOfSpaces[] = { 4 };
			string strings = sortingByWidth("It's VSTU", 9, arrayOfSpaces, 1);
			Assert::AreEqual((string)"It's            VSTU", strings);
		}

		TEST_METHOD(TestMethod2)
		{
			int arrayOfSpaces[] = { 2, 8 };
			string strings = sortingByWidth("0A human thought ", 16, arrayOfSpaces, 2);
			Assert::AreEqual((string)"0A   human   thought", strings);
		}

		TEST_METHOD(TestMethod3)
		{
			int arrayOfSpaces[] = { 9 };
			string strings = sortingByWidth("2material medium;", 17, arrayOfSpaces, 1);
			Assert::AreEqual((string)"2material    medium;", strings);
		}

		TEST_METHOD(TestMethod4)
		{
			int arrayOfSpaces[] = { 4, 8, 16 };
			string strings = sortingByWidth("VSTU was founded in", 19, arrayOfSpaces, 3);
			Assert::AreEqual((string)"VSTU  was founded in", strings);
		}
	};

	TEST_CLASS(Test_textProcessing)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int sizeStrings;
			string* strings = textProcessing("VSTU was founded in", sizeStrings);
			string exp_strings[1] = { "VSTU was founded in" };
			
			for (int i = 0; i < sizeStrings; i++) {
				Assert::AreEqual(exp_strings[i], strings[i]);
			}
		}

		TEST_METHOD(TestMethod2)
		{
			int sizeStrings;
			string* strings = textProcessing("VSTU was founded in 1930", sizeStrings);
			string exp_strings[2] = { "VSTU  was founded in", "1930" };
			
			for (int i = 0; i < sizeStrings; i++) {
				Assert::AreEqual(exp_strings[i], strings[i]);
			}
		}

		TEST_METHOD(TestMethod3)
		{
			int sizeStrings;
			string* strings = textProcessing("0A human thought 1fixed on some 2material medium; 3in general, a 4coherent and comple5te sequence of 6symbols.", sizeStrings);
			string exp_strings[7] = { "0A   human   thought", "1fixed    o n   some", "2material    medium;",
				"3in    general ,   a" , "4coherent and comple" , "5te    sequence   of" , "6symbols." }; 
			
			for (int i = 0; i < sizeStrings; i++) {
				Assert::AreEqual(exp_strings[i], strings[i]);
			}
		}
	};

}
