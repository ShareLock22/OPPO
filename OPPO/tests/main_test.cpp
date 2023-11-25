#include "pch.h"
#include "CppUnitTest.h"
#include "..\OPPO\Sea.h"
#include "..\OPPO\FIsh.h"
#include <sstream>
#include <vector>
using namespace Microsoft::VisualStudioCode::CppUnitTestFramework;


namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
    TEST_CLASS(UnitTest)
    {
    public:

		TEST_METHOD(ValidNameFormat)
		{
			std::vector<std::string> cases{
				"Black sea"
				"Dead sea"
				"Yellow sea"
			};
			for (int i = 0; i < cases.size(); i++) {
				istringstream ist(cases[i]);
				Sea sea;
				try {
					sea.load_txt(ist);
				}
				catch (runtime_error& e) {
					Assert::AreEqual(e.what(), "Invalid sea name format");
				}
			}
		};
		TEST_METHOD(InvalidNameFormat) 
		{
			std::vector<std::string> cases{
				"123243242 3243242"
			};
			for (int i = 0; i < cases.size(); i++) {
				istringstream ist(cases[i]);
				Sea sea;
				try {
					sea.load_txt(ist);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};
		TEST_METHOD(ValidSalty)
		{
			std::vector<std::int> cases{
				150
                50
                199
			};
			for (int i = 0; i < cases.size(); i++) {
				Sea sea;
				try {
					sea.ValidateSalty(cases[i]);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};
	};
 		TEST_METHOD(InvalidSalty)
		{
			std::vector<std::int> cases{
				-150
                -49
			};
			for (int i = 0; i < cases.size(); i++) {
				Sea sea;
				try {
					sea.ValidateSalty(cases[i]);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};
        TEST_METHOD(InvalidSalty)
		{
			std::vector<std::string> cases{
				"123"
                "-123"
			};
			for (int i = 0; i < cases.size(); i++) {
				Sea sea;
				try {
					sea.ValidateSalty(cases[i]);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};
        TEST_METHOD(ValidDeep)
		{
			std::vector<std::int> cases{
				150
                50
                199
			};
			for (int i = 0; i < cases.size(); i++) {
				Sea sea;
				try {
					sea.ValidateSalty(cases[i]);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};
	};
 		TEST_METHOD(InvalidDeep)
		{
			std::vector<std::int> cases{
				-150
                -49
			};
			for (int i = 0; i < cases.size(); i++) {
				Sea sea;
				try {
					sea.ValidateSalty(cases[i]);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};
        TEST_METHOD(InvalidDeep)
		{
			std::vector<std::string> cases{
				"123"
                "-123"
			};
			for (int i = 0; i < cases.size(); i++) {
				Sea sea;
				try {
					sea.ValidateSalty(cases[i]);
					Assert::Fail();
				}
				catch (runtime_error& e) {
					return;
				}
			}
		};

		TEST_METHOD(ValidNameFormat)
		{
			std::vector<std::string> cases{
				"Okun"
				"Som"
				"Plotva"
			};
			for (int i = 0; i < cases.size(); i++) {
				istringstream ist(cases[i]);
				Fish fish;
				try {
					fish.load(ist);
				}
				catch (runtime_error& e) {
					Assert::AreEqual(e.what(), "Invalid fis name format");
				}
			}
		};
		TEST_METHOD(InvalidNameFormat)
		{
			std::vector<std::string> cases{
				"Okun    "
				"Som "
				"Plo-tva"
			};
			for (int i = 0; i < cases.size(); i++) {
				istringstream ist(cases[i]);
				Fish fish;
				try {
					fish.load(ist);
				}
				catch (runtime_error& e) {
					Assert::AreEqual(e.what(), "Invalid fish name format");
				}
			}
		};
        TEST_METHOD(LoadValidName) {
            string valid = "Black Sea 150 10";
            istringstream iss(valid);

            Sea sea;
            sea.load_txt(iss);

            string str = "Black Sea";
            Assert::AreEqual(sea.nameOfSea, str);
            Assert::AreEqual(sea.deep, 150);
            Assert::AreEqual(sea.salty, 10);
        };
        TEST_METHOD(LoadInvalidName) {
            string invalid = "Black&Sea -10 -j";
            istringstream iss(invalid);

            Sea sea;

            try {
                sea.load_txt(iss);
                Assert::Fail();
            }
            catch (runtime_error&) {
            }
        };
        TEST_METHOD(LoadValidFish) {
            stringvalid = "Okun";
       
            istringstream iss(valid);

            Fish fish;
            fish.load(iss);

            string str = "Okun";
            Assert::AreEqual(fish.nameOfFish, str);
        };
        TEST_METHOD(LoadInvalidFish) {
            stringvalid = "Oku-n";
       
           stringstream iss(invalid);

            Fish fish;

            try {
                sea.load_txt(iss);
                Assert::Fail();
            }
            catch (runtime_error&) {
            }
        };
}