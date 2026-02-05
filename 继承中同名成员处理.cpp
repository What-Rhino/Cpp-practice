#include<iostream>
using namespace std;
class Base
{
	public:
		Base()
		{
			m_A=100;
		}
		void func()
		{
			cout<<"Base-func调用"<<endl;
		}
		void func(int a)
		{
			cout<<"Base-func(int a)调用"<<endl;
		}
		int m_A; 
};
class Son:public Base
{
	public:
		Son()
		{
			m_A=200;
		}
		void func()
		{
			cout<<"Son-func调用"<<endl;
		}
		int m_A;
};
//同名成员属性 
void test01()
{
	Son s;
	cout<<"Son 下的 m_A= "<<s.m_A<<endl;//如果直接调用 访问的是子类中的成员属性 
	cout<<"Base 下的m_A= "<<s.Base::m_A<<endl;//加上父类的作用域 就可以访问父类中的同名成员属性 
}
//同名成员函数
void test02()
{
	Son s;
	s.func();//直接调用 调用的是子类中的同名成员函数 
	s.Base::func();	//加上父类作用域 就可以调用父类中的同名成员函数 
	//如果子类中出现和父类同名的函数，子类的同名成员函数会隐藏掉父类中所有的同名成员函数，包括父类中重载的函数
	//如果想要访问 需要加上作用域 
	s.Base::func(100);
} 
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
