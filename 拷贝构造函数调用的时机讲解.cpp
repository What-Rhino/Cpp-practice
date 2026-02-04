#include<iostream>
using namespace std;
//拷贝构造函数调用的时机 
class Person
{
	public:
		Person()
		{
			cout<<"Person默认构造函数的调用"<<endl;
		}
		Person (int age)
		{
			cout<<"Person有参构造函数的调用"<<endl;
			m_Age=age;
		}
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
//1、使用一个已经创建完毕的对象来初始化一个新对象 
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout<<"p2的年龄为："<<p2.m_Age<<endl;	
}
//2、值传递的方式给函数参数传值
void doWork(Person p)//拷贝一个临时的副本传入 ,不影响原对象的值 
{
	p.m_Age=20;
	cout<<"doWork中p的年龄为："<<p.m_Age<<endl;
}
void test02()
{
	Person p;
	p.m_Age=10;
	doWork(p);
	cout<<"test02中p的年龄为："<<p.m_Age<<endl;
} 
//3、值方式返回局部对象
Person doWork2()
{
	Person p1;
	p1.m_Age=10;
	cout<<"doWork2中的年龄的地址为："<<(int*)&p1<<endl;
	return Person(p1);//根据p1创建一个新的对象传出去 
} 
void test03()
{
	Person p=doWork2();
	cout<<"test03中的年龄地址为："<<(int*)&p<<endl;//接收的地址和创建的地址不同 
}
int main()
{
//	test01();
//	test02();
	test03(); 
	system("pause");
	return 0;
}
