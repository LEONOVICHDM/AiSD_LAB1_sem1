#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD_LAB1_sem1/AiSD_LAB1_sem1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(push_back)
		{
			Mylist testlist;
			int data;
			int length = 3;

			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			testlist.push_back(10);
			Assert::IsTrue(testlist.get_size() == 4);
		}
		TEST_METHOD(push_front)
		{
			Mylist testlist;
			int data;
			int length = 3;

			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			testlist.push_front(10);
			Assert::IsTrue(testlist.get_size() == 4);
		}
		TEST_METHOD(pop_front)
		{
			Mylist testlist;
			int data;
			int length = 3;

			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			testlist.pop_front();
			Assert::IsTrue(testlist.get_size() == 2);
		}
		TEST_METHOD(pop_back)
		{
			Mylist testlist;
			int data;
			int length = 3;

			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			testlist.pop_back();
			Assert::IsTrue(testlist.get_size() == 2);
		}
		TEST_METHOD(insert)
		{
			Mylist testlist;
			int data;
			int length = 3;

			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			testlist.insert(10,1);
			Assert::IsTrue(testlist.get_size() == 4);
		}
		TEST_METHOD(at)
		{
			Mylist testlist;
			int data;
			int length = 3;
			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			Assert::IsTrue(testlist.at(3) == data);
		}
		TEST_METHOD(remove)
		{
			Mylist testlist;
			int data;
			int length = 3;

			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			testlist.remove(1);
			Assert::IsTrue(testlist.get_size() == 2);
		}
		TEST_METHOD(get_size)
		{
			Mylist testlist;
			int data;
			int length = 3;
			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			Assert::IsTrue(testlist.get_size() == length);
		}
		TEST_METHOD(set)
		{
			Mylist testlist;
			int data;
			int length = 3;
			for (int i = 0; i < length; i++) {
				data = rand() % 10;
				testlist.push_back(data);
			}
			testlist.set(data, 2);
			Assert::IsTrue(testlist.at(2) == data);
		}
		TEST_METHOD(find_first)
		{
			Mylist firstlist, secondlist;
			int data = 0;
			int length = 3;
			int same;
			for (int i = 0; i < length; i++) {
				firstlist.push_back(data);
			}
			for (int i = 0; i < length; i++) {
				secondlist.push_back(data);
			}
			Assert::IsTrue(firstlist.find_first(&secondlist)==0);
		}
		TEST_METHOD(isEmpty)
		{
			Mylist firstlist;
			Assert::IsTrue(firstlist.isEmpty()==0);
		}
	};
}
