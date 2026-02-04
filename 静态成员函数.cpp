#include<iostream>
using namespace std;
//静态成员函数
//1、所有对象共享同一个函数
//2、静态成员函数只能访问静态成员变量
//3、静态成员函数也是有访问权限的 
class Person
{
	public:
		static void func()
		{
			m_A=100;//静态成员函数可以访问静态成员变量
			//m_B=200;静态成员函数无法访问非静态成员变量 ,因为无法区分是哪个对象的m_B被更改 
			cout<<"static void func调用"<<endl;
		}
		static int m_A; 
		int m_B; 
	private:
		static void func2()
		{
			cout<<"static void func2的调用"<<endl;
		}
}; 
int Person::m_A=0;
//静态成员函数也有两种访问方式 
void test01()
{
	//1、通过对象访问 
	Person p;
	p.func();
	//2、通过类名进行访问
	Person ::func(); 
	//Person ::func2(); 类外访问不到私有的静态成员函数 
}
int main()
{
	test01();
	system("pause");
	return 0;
}
