#include<iostream>
using namespace std;
//常函数： 
//1、成员函数后加const后我们称之为常函数
//2、常函数内不可以修改成员属性
//3、成员属性如果在声明时加关键字mutable后，在常函数中就可以修改 
class Person
{
	public:
		Person(){} //需要手动写一个构造函数才能添加常对象 
		void showPerson() const//这个const的本质是修饰this，让this指向的值也不可修改 
		{
			//m_A=100;错误 无法修改，因为编译器会补成this->m_A
			//this=NULL;错误 this指针的本质是指针常量，即Person* const this，指针指向不可修改 
			//要想让this指向的值也不可修改，则需要写成const Person*const this,将最前面的const放到函数后，即为常函数
			 m_B=100;
			 cout<<"m_B= "<<m_B<<endl; 
		}
		void func()
		{
			
		} 
		int m_A;
		mutable int m_B;//如果想在常函数中可以修改，就需在前加上mutable 
}; 
void test01() 
{
	Person p;
	p.showPerson();
}
//常对象：
//1、声明对象前加const，称之为常对象 
//2、常对象只能调用常函数 
void test02()
{
	const Person p;//常对象的定义 ,需要手动写一个构造函数才能添加常对象 
	//p.m_A=100;//常对象下不可修改 
	p.m_B=200; //有mutable可以修改
	//p.func();//错误，常对象不能修改属性，为了防止通过常函数以外的函数改变属性，所以不允许常对象调用普通成员函数 
}
int main()
{
	test01();
	system("pause");
	return 0;
}
