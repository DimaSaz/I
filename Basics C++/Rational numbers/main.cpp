#include "Rational.h"

int main()
{
	using namespace std;
	Rational test1, test2(5, 2), test3(3, 6), test4(2, 6), test5(2, 6), test6(8);
	cout << "Input format - \"(1,2)\"" << endl;
	std::cin >> test1; // ���� � ������� "(1,2)"
	cout << "\nTest1 equals " << test1;
	cout << "\nTest2 equals " << test2;
	cout << "\nTest3 equals " << test3;
	cout << "\nTest4 equals " << test4;
	cout << "\nTest5 equals " << test5;
	cout << "\nTest6 equals " << test6;
	cout << "\n";
	cout << "\nTest1 * Test2 equals " <<  test1 * test2;
	cout << "\nTest2 / Test3 equals " << test1 / test3;
	cout << "\nTest2 + Test3 equals " << test2 + test3;
	cout << "\nTest3 - Test4 equals " << test3 - test4;
	cout << "\nTest1 + 5 equals " << test1 + 5;
	cout << "\nTest2 - 5 equals " << test2 - 5;
	cout << "\nTest3 * 5 equals " << test3 * 5;
	cout << "\nTest4 / 5 equals " << test4 / 5;
	cout << "\nTest1-- equals " << --test1;
	cout << "\nTest1++ equals " << ++test1;
	cout << "\n-Test2 equals " << -test2;
	cout << "\n";
	if (test4 == test5)
		cout << "\nTest4 is equal to Test5";
	if (test4 < test3)
		cout << "\nTest4 is less than Test3";
	if (test3 > test4)
		cout << "\nTest3 is more than Test4";
	cout << "\n";
	cout << "\nGetInteger Test1 equals " << test1.GetInteger();
	cout << "\nGetDouble Test2 equals " << test2.GetDouble();
	cout << "\nRotate Test3 equals " << test3.Rotate();
	cout << "\n";
	cout << "\n";
	system("pause");
	return 0;
}
