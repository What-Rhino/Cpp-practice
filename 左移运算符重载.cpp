#include<iostream>
using namespace std;
//左移运算符<<作用:输出打印 cout<<a<<endl;
//左移运算符重载
class Person
{
	//若有成员为私有，如果想访问，则需将运算符重载函数设置为友元函数
	friend ostream & operator<<( ostream &cout,Person &p);
	//1、利用成员函数重载左移运算符 调用时p.operator<<(cout)简化为p<<cout,不是我们想要的
	//所以通常不利用成员函数重载，因为无法实现cout在左侧 
	//void operator<<(cout) 
	public:
		Person():m_C(100){}
		int m_A;
		int m_B;
	private:
		int m_C; 
};
//只能利用全局函数重载左移运算符
//可理解为cout<<是ostream实例化出的一个对象,out属于ostream（输出流）类型，程序中只能有一个，所以必须用引用传递 
ostream & operator<<( ostream &cout,Person &p)//本质：operator<<(cout,p) 简化为：cout<<p
//要想返回的可以在后面继续写endl；则需要返回cout的类型(链式编程思想) 
{
	cout<<"m_A= "<<p.m_A<<"m_B= "<<p.m_B;
	cout<<"m_C="<<p.m_C;//因为是友元函数，所以可以访问私有成员 
	return cout;
} 
void test01()
{
	Person p;
	p.m_A=10;
	p.m_B=10;
	//cout<<p.m_A<<endl;
	//想直接写cout<<p<<endl;就能输出类内所有属性
	cout<<p<<"Hello World"<<endl; 
} 
int main()
{
	test01();
	system("pause");
	return 0;
}
