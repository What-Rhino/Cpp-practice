#include<iostream>
using namespace std;
//成员变量和成员函数是分开存储的 
//只有非静态的成员变量才属于类的对象上 
class Person01
{
	
};
class Person02
{
	int m_A;//非静态成员变量,属于类的对象上	
};
class Person03
{
	int m_A;
	static int m_B;//静态成员变量不属于类的对象上 
};
int Person03::m_B=0;
class Person04
{
	int m_A;
	static int m_B;
	void func(){}//非静态成员函数不属于类的对象上 
}; 
class Person05
{
	int m_A;
	static int m_B;
	void func(){}
	static void func2(){}//静态成员函数 不属于类的对象上 
};
void test01()
{
	Person01 p;
	//空对象占用的内存空间为：1
	//c++编译器会给每个空对象分配一个字节的空间，是为了区分空对象在内存的位置
	//每个空对象也应该有一个独一无二的内存的地址 
	cout<<"size of p="<<sizeof(p)<<endl;
} 
void test02()
{
	Person02 p;
	cout<<"size of p="<<sizeof(p)<<endl;
} 
void test03()
{
	Person03 p;
	cout<<"size of p="<<sizeof(p)<<endl;
} 
void test04()
{
	Person04 p;
	cout<<"size of p="<<sizeof(p)<<endl;
}
void test05()
{
	Person05 p;
	cout<<"size of p="<<sizeof(p)<<endl;
} 
int main()
{
	test01();
	test02();
	test03(); 
	test04();
	test05(); 
	system("pause");
	return 0;
}
