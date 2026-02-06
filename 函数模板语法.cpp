#include<iostream>
using namespace std;
//交换两个整型的函数 
/*void swapInt(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
//交换两个浮点型的函数 
void swapDouble(double &a,double &b)
{
	double temp=a;
	a=b;
	b=temp;
}*/
//函数模板
template<typename T>//声明一个模板 告诉编译器T是通用的数据类型 
void mySwap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}
void test01()
{
	int a=10;
	int b=20;
	//swapInt(a,b);
	//1、自动类型推导 
	mySwap(a,b);
	cout<<"a= "<<a<<' '<<"b= "<<b<<endl;
	double c=1.1;
	double d=1.2;
	//swapDouble(c,d);
	//2、显示指定类型 
	mySwap<double>(c,d);
	cout<<"c= "<<c<<' '<<"d= "<<d<<endl;
}
int main()
{
	test01();
	system("pause"); 
	return 0;
}
