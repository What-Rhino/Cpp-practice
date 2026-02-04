#include<iostream>
using namespace std;
#define Day 7//宏常量，不可修改 
int main()
{
	cout<<"一周共有："<<Day<<"天"<<endl; 
	const int month=12;//const修改的变量也称为常量，修改即报错 
	cout<<"一年共有："<<month<<"月"<<endl; 
	int a=10;
	cout<<"a="<<a<<endl;
	system("pause");
	return 0;
} 
