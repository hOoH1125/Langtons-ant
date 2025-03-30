#include<iostream>
#include<iomanip>
#include"Matrix.h"
using namespace std;
int main()
{
	int i;
	Matrix M1(1, 2, 3, 4), M2, M3(4, 3, 2, 1);
	cout << "M1: " << M1;
	cout << endl;
	cout << "请输入M2中的四个数字: ";
	cin >> M2;
	cout << "M1+M2: " << M1 + M2;
	cout << "M1-M2: " << M1 - M2;
	cout << "M1*M2: " << M1 * M2;
	cout << "M3: " << M3;
	cout << "M1+M2+M3: " << M1 + M2 + M3;
	cout << "M1*M2*M3: " << M1 * M2 * M3;
}