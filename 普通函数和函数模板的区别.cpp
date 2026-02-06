#include<iostream>
using namespace std;
//1、普通函数调用可以发生隐式类型转换
//2、函数模板 用自动类型推导 不可以发生隐式类型转换
//3、函数模板 用显示指定类型 可以发生隐式类型转换 

//普通函数
int myAdd01(int a,int b)
{
	return a+b;
}
//函数模板
template<class T>
T myAdd02(T a,T b)
{
	return a+b;
} 
void test01()
{
	int a=10;
	int b=20;
	char c='c';
	cout<<myAdd01(a,b)<<endl;
	//发生了隐式类型转换 c对应的码值为99 
	cout<<myAdd01(a,c)<<endl;
	
	//自动类型推导
	cout<<myAdd02(a,b)<<endl;
	//cout<<myAdd02(a,c)<<endl;错误！编译器无法推导出统一的数据类型 函数模板不会发生隐式类型转换
	
	//显示指定类型
	cout<<myAdd02<int>(a,c)<<endl;//显示指定类型可以发生隐式类型转换 
}
int main()
{
	test01();
	system("pause");
	return 0;
}
