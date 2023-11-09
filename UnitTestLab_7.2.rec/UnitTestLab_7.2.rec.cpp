#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2.rec/LAB.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab72rec
{
	TEST_CLASS(UnitTestLab72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 2;
			const int colCount = 2;
			int S = 0, k = 0;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i) {
				a[i] = new int[colCount];
			}

			a[0][0] = 1;
			a[0][1] = 9;
			a[1][0] = 7;
			a[1][1] = 5;

			int z = sumDiagonal(a, rowCount, colCount, 0 ); // Fix the function call

			Assert::AreEqual(z, 6);


		}
	};
}
