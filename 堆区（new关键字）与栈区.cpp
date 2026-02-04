#include<iostream>
using namespace std;
int * func()
{
	int * p=new int(10);//利用new关键字，在堆区开辟内存，返回值是指针 
	return p;
}
int * fun()
{
	int a=10;//局部变量保存在栈区，栈区的数据在函数执行完自动释放 
	return &a;//局部变量的地址千万不要返回，可能会出错 
} 
int main()
{
	int *p=func();
	cout<<"*p=: "<<*p<<endl;
	int *a=fun();
	cout<<"a=："<<*a<<endl;//第一次可以打印正确，是因为编译器会帮我们保留一次 
    cout<<"a=："<<*a<<endl;//打印第二次会出现错误 
	system("pause");
	return 0;
}
