#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR_lab_12.2.rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL, * last = NULL;
			Input(first, last, 1);
			Assert::AreEqual(first->info, 1); 

			Input(first, last, 2);
			Assert::AreEqual(last->info, 2); 

			Input(first, last, 3);
			Assert::AreEqual(last->info, 3); 

			Delete(first, last);
		}
	};
}
