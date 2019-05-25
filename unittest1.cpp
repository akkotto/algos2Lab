#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project5/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest_Int_Int)
	{
	private:
		Tree<int, int> IntKeyTree;
	public:

		TEST_METHOD(insert_firstNode)
		{
			IntKeyTree.insert(2, 88);

			Assert::IsTrue(IntKeyTree.find(88)->data == 2 && IntKeyTree.find(88)->color == 0);
		}

		TEST_METHOD(insert_secondNode)
		{
			IntKeyTree.insert(7, 88);
			IntKeyTree.insert(8, 77);

			Assert::IsTrue(IntKeyTree.find(77)->parent == IntKeyTree.find(88) && IntKeyTree.find(77)->color == 1);
		}

		TEST_METHOD(find_oneNode)
		{
			IntKeyTree.insert(8, 88);

			Assert::IsTrue(IntKeyTree.find(88)->data == 8 && IntKeyTree.find(88)->color == 0);
		}

		TEST_METHOD(find_severalNodes)
		{
			IntKeyTree.insert(66, 6);
			IntKeyTree.insert(77, 7);
			IntKeyTree.insert(88, 8);
			IntKeyTree.insert(99, 9);

			Assert::IsTrue(IntKeyTree.find(8)->data == 88);
		}

		TEST_METHOD(revome_firstNode)
		{
			IntKeyTree.insert(8, 88);

			IntKeyTree.remove(88);

			Assert::IsTrue(IntKeyTree.GetRoot() == nullptr);
		}

		TEST_METHOD(remove_doesntExistNode)
		{
			IntKeyTree.insert(8, 88);

			IntKeyTree.remove(88);
			IntKeyTree.remove(77);

			Assert::IsTrue(IntKeyTree.GetRoot() == nullptr);
		}

		TEST_METHOD(remove_treeWithTwoNode)
		{
			IntKeyTree.insert(7, 77);
			IntKeyTree.insert(6, 66);

			IntKeyTree.remove(66);

			Assert::IsTrue(IntKeyTree.GetRoot() == IntKeyTree.find(77) && IntKeyTree.find(77)->left == nullptr && IntKeyTree.find(77)->right == nullptr);
		}

		TEST_METHOD(remove_nodeWithChild)
		{
			IntKeyTree.insert(4, 66);
			IntKeyTree.insert(5, 99);
			IntKeyTree.insert(6, 77);
			IntKeyTree.insert(7, 88);
			IntKeyTree.insert(8, 11);
			IntKeyTree.insert(9, 33);

			IntKeyTree.remove(77);

			Assert::IsTrue(IntKeyTree.GetRoot() == IntKeyTree.find(66) && IntKeyTree.find(66)->left == IntKeyTree.find(33) && IntKeyTree.find(66)->right == IntKeyTree.find(99));
		}

	};
}