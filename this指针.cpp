#include<iostream>
using namespace std;
//1、解决名称冲突，当形参和成员变量重名时可以使用this指针来区分
//2、在类的非静态成员函数中返回对象本身时，可使用return*this
class Person
{
	public:
		Person(int age)
		{
			//this指针指向被调用成员函数所属的对象 
			this->age=age;//解决名称冲突 
		}
		Person& PersonAddAge(Person &p)//若用Person方式返回，相当于调用了拷贝构造函数，重新构造了一个新对象
		 							   //若用引用的方式返回，才相当于返回了该对象的本体	
		{
			this->age+=p.age;
			//返回对象本身 
			return *this;//this指向p2的指针，而*this指向的就是这个对象本体 
		}
		int age;
}; 
void test01()
{
	Person p1(18);
	cout<<"p1的年龄为："<<p1.age<<endl;
} 
void test02()
{
	Person p1(10);
	Person p2(10);
	//链式编程思想 
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//调用一次，需返回一个对象，才能继续调用 
	//若采用Person的方式返回，每次都构造了一个新对象，除第一次的调用作用到原对象p2上，其他的都作用到了新产生的对象上
	//并不会改变原对象p2的属性 
	cout<<"p2的年龄为："<<p2.age<<endl; 
} 
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
