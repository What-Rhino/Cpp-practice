#include<iostream>
using namespace std;
//1、创建一个类，C++会给每个类至少添加三个函数
//默认构造（空实现） 
//析构函数（空实现） 
//拷贝构造 （值拷贝）
//2、如果写了有参构造函数，编译器就不会提供默认构造，依然提供拷贝构造 
//3、如果我们写了拷贝构造函数，编译器就不再提供其他的普通构造函数了 
class Person 
{
	public:
	Person()
	{
		cout<<"Person默认构造函数的调用"<<endl;
	}
	Person(int age)
	{
		cout<<"Person有参构造函数的调用"<<endl;
		m_Age=age;
	}
	//若注释掉拷贝构造函数，编译器会自动提供 
	Person(const Person &p)
	{
		cout<<"Person拷贝构造函数的调用"<<endl;
		m_Age=p.m_Age;
	}
	~Person()
	{
		cout<<"Person析构函数的调用"<<endl;
	}	
	int m_Age;
};
/*void test01()
{
	Person p;
	p.m_Age=18;
	Person p2(p);
	cout<<"P2的年龄为："<<p2.m_Age<<endl;
}*/
//注释掉43行验证规则2；注释掉44和45行验证规则3（报错） 
void test02()
{
	//Person p;//调用默认构造，但是已经存在有参构造，编译器不会提供默认构造 
	Person p(28);
	Person p2(p);
	cout<<"P2的年龄为："<<p2.m_Age<<endl; 
} 
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
