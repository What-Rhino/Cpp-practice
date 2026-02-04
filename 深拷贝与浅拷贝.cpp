#include<iostream>
using namespace std;
class Person
{
	public:
		Person()
		{
			cout<<"Person默认构造函数调用"<<endl;
		}
		//有参构造 
		Person(int age,int height)
		{
			m_Age=age;
			m_Height=new int(height);//创建在堆区 ，new的返回值是int* 
			//如果属性有开辟在堆区的数据，就要使用深拷贝 
			cout<<"Person有参构造函数的调用"<<endl;
		}
		//自己实现一个深拷贝构造，来解决浅拷贝带来的问题
		Person(const Person &p)	
		{
			cout<<"Person的拷贝构造函数的调用："<<endl;
			m_Age=p.m_Age;
			//m_Height=p.m_Height;编译器默认实现这行代码，会导致浅拷贝出现错误
			//深拷贝操作：
			m_Height=new int(*p.m_Height);//重新申请一块堆区空间 ,解决浅拷贝导致的堆区内存重复释放 
		}
		~Person()
		{
			//析构代码，可以将堆区开辟的数据释放
			//如果使用浅拷贝（编译器提供的）会导致堆区的内存被重复释放 
			if(m_Height!=NULL)
			{
				delete m_Height;
				m_Height=NULL;
			} 
			cout<<"Person析构函数的调用"<<endl;
		}
		int m_Age;//年龄 
		int *m_Height;//身高 
};
void test01()
{
	Person p1(18,160);
	cout<<"p1的年龄为："<<p1.m_Age<<"身高为："<<*p1.m_Height<<endl;
	Person p2(p1);//浅拷贝 
	cout<<"p2的年龄为："<<p2.m_Age<<"身高为："<<*p2.m_Height<<endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
