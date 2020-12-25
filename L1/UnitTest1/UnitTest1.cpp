#include "pch.h"
#include "CppUnitTest.h"
#include "../L1/L1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(push_back)
		{
			List L;
			L.push_back(1);
			size_t S = 1;
			Assert::AreEqual(S, L.get_size());
			L.push_back(2);
			S++;
			Assert::AreEqual(S, L.get_size());
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 2);
		}
		TEST_METHOD(push_front)
		{
			List L;
			L.push_front(1);
			size_t S = 1;
			Assert::AreEqual(S, L.get_size());
			L.push_front(2);
			S++;
			Assert::AreEqual(S, L.get_size());
			Assert::AreEqual(L.at(0), 2);
			Assert::AreEqual(L.at(1), 1);
		}
		TEST_METHOD(pop_back)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			size_t S = 1;
			L.pop_back();
			Assert::AreEqual(S, L.get_size());
			Assert::AreEqual(L.at(0), 1);
			L.pop_back();
			S--;
			Assert::AreEqual(S, L.get_size());
		}
		TEST_METHOD(pop_back_except)
		{
			List L;
			bool b = 0;
			try
			{
				L.pop_back();
			}
			catch (exception& exception)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
		TEST_METHOD(pop_front)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			size_t S = 1;
			L.pop_front();
			Assert::AreEqual(S, L.get_size());
			Assert::AreEqual(L.at(0), 2);
			L.pop_front();
			S--;
			Assert::AreEqual(S, L.get_size());
		}
		TEST_METHOD(pop_front_except)
		{
			List L;
			bool b = 0;
			try
			{
				L.pop_back();
			}
			catch (exception& exception)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
		TEST_METHOD(insert)
		{
			List L;
			L.push_back(1);
			L.push_back(3);
			L.insert(1, 2);
			size_t S = 3;
			Assert::AreEqual(S, L.get_size());
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 2);
			Assert::AreEqual(L.at(2), 3);
		}
		TEST_METHOD(insert_except)
		{
			List L;
			bool b = 0;
			try
			{
				L.insert(0, 0);
			}
			catch (exception& exception)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
		TEST_METHOD(at_except)
		{
			List L;
			bool b = 0;
			try
			{
				L.at(0);
			}
			catch (exception& exception)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
		TEST_METHOD(remove)
		{
			List L;
			L.push_back(1);
			L.push_back(3);
			L.insert(1, 2);
			size_t S = 2;
			L.remove(1);
			Assert::AreEqual(S, L.get_size());
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 3);
	
		}
		
		TEST_METHOD(remove_except)
		{
			List L;
			bool b = 0;
			try
			{
				L.remove(0);
			}
			catch (exception& exception)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
		TEST_METHOD(set)
		{
			List L;
			L.push_back(1);
			L.push_back(3);
			L.insert(1, 2);
			size_t S = 3;
			L.set(1, 4);
			Assert::AreEqual(S, L.get_size());
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 4);
			Assert::AreEqual(L.at(2), 3);
		}
		TEST_METHOD(set_except)
		{
			List L;
			bool b = 0;
			try
			{
				L.set(0, 0);
			}
			catch (exception& exception)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
		TEST_METHOD(reverse)
		{
			List L;
			L.push_back(1);
			L.push_back(3);
			L.insert(1, 2);
			L.reverse();
			Assert::AreEqual(L.at(0), 3);
			Assert::AreEqual(L.at(1), 2);
			Assert::AreEqual(L.at(2), 1);
		}
		TEST_METHOD(reverse_except)
		{
			List L;
			bool b = 0;
			try
			{
				L.reverse();
			}
			catch (exception& exception)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
	};
}
