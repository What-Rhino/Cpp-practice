#include<iostream>
using namespace std;
class Base
{
	public:
		static int m_A; 
		static void func()
		{
			cout<<"Base-static void func()"<<endl;
		} 
		static void func(int a)
		{
			cout<<"Base-static void func(int a)"<<endl;
		} 
};
int Base::m_A=100;
class Son:public Base 
{
	public:
		static int m_A;
		static void func()
		{
			cout<<"Son-static void func()"<<endl;
		} 
};
int Son::m_A=200;
//同名静态成员属性
/*void test01()
{
	//1、通过对象访问数据 
	cout<<"通过对象的访问："<<endl; 
	Son s;
	cout<<"Son 下的 m_A="<<s.m_A<<endl;
	cout<<"Base 下的m_A="<<s.Base::m_A<<endl;
	//2、通过类名来访问数据
	cout<<"通过类名的访问："<<endl;
	cout<<"Son下的m_A="<<Son::m_A<<endl;
	cout<<"Base 下的m_A="<<Son::Base::m_A<<endl; 
}*/
//同名静态成员函数 
void test02()
{
	//1、通过对象访问 
	cout<<"通过对象访问"<<endl;
	Son s;
	s.func();
	s.Base::func();
	//2、通过类名访问
	cout<<"通过类名访问"<<endl;
	Son::func(); 
	Son::Base::func();
	//如果子类中出现了一个重名的静态成员函数，就会把父类中所有的同名函数隐藏掉 包括重载函数 
	Son::Base::func(100); 
	//如果想要访问父类中隐藏的成员函数 则需要加作用域 
}
int main()
{
	//test01(); 
	test02();
	system("pause");
	return 0;
}
