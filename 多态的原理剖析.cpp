#include<iostream>
using namespace std;
//多态
//动物类
class Animal
{
	public:
		//虚函数 
		virtual void speak()
		{
			cout<<"动物在说话"<<endl;
		}
}; 
//猫类 
class Cat:public Animal
{
	public:
		//函数重写：函数返回值类型 函数名 参数列表 完全相同 
		void speak()
		{
			cout<<"小猫在说话"<<endl;
		} 
};
//狗类
class Dog:public Animal
{
	public:
		//函数重写：函数返回值类型 函数名 参数列表 完全相同 
		void speak()
		{
			cout<<"小狗在说话"<<endl;
		}
}; 
//执行说话的函数
//地址早绑定 在编译阶段就确定了函数的地址
//如果想要执行让猫说话 那么函数地址就不能提前绑定，需要在运行时绑定，也就是地址晚绑定 
//动态多态满足条件
//1、有继承关系
//2、子类重写父类的虚函数 
//动态多态的使用
//父类的指针或引用 指向子类的对象 
void doSpeak(Animal &animal)//相当于Animal & animal=cat；因为父类的引用或指针可以指向子类对象 
{
	animal.speak();
} 
void test01()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}
void test02()
{
	//动物类中有一个虚函数指针vfptr,指向虚函数表vftable，vftable中存放Animal类中的speak
	cout<<"sizeof Animal= "<<sizeof(Animal)<<endl;
	//Cat类会继承父类的虚函数指针，但是当Cat类中发生函数重写时，该指针会指向Cat类中的speak 
	cout<<"sizeof Cat= "<<sizeof(Cat)<<endl; 
 } 
int main()
{
	test01();
	test02();
	system("pause"); 
	return 0;
}
