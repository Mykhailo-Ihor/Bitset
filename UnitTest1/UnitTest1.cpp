#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project10\bitset.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitsetTests
{
    TEST_CLASS(BitsetTest)
    {
    public:

        TEST_METHOD(TestSet)
        {
            Bitset bs;
            bs.set(0);
            Assert::IsTrue(bs.test(0));
            bs.set(3);
            Assert::IsTrue(bs.test(3));
            bs.set(7);
            Assert::IsTrue(bs.test(7));
        }

        TEST_METHOD(TestReset)
        {
            Bitset bs;
            bs.set(0);
            bs.reset(0);
            Assert::IsFalse(bs.test(0));
            bs.set(3);
            bs.reset(3);
            Assert::IsFalse(bs.test(3));
            bs.set(7);
            bs.reset(7);
            Assert::IsFalse(bs.test(7));
        }

        TEST_METHOD(TestFlip)
        {
            Bitset bs;
            bs.set(0);
            bs.flip(0);
            Assert::IsFalse(bs.test(0));
            bs.flip(0);
            Assert::IsTrue(bs.test(0));

            bs.set(3);
            bs.flip(3);
            Assert::IsFalse(bs.test(3));
            bs.flip(3);
            Assert::IsTrue(bs.test(3));

            bs.set(7);
            bs.flip(7);
            Assert::IsFalse(bs.test(7));
            bs.flip(7);
            Assert::IsTrue(bs.test(7));
        }


        TEST_METHOD(TestOperatorSquareBrackets)
        {
            Bitset bs;
            bs[0] = true;
            Assert::IsTrue(bs[0]);
            bs[0] = false;
            Assert::IsFalse(bs[0]);
            bs.flip(0);
            Assert::IsTrue(bs[0]);
        }

        TEST_METHOD(TestPrint)
        {
            Bitset bs;
            bs.set(0);
            bs.set(3);
            bs.set(7);
            std::stringstream output;
            auto original = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            bs.print();
            std::cout.rdbuf(original);
            Assert::AreEqual("10001001\n", output.str().c_str());
        }
    };
}

