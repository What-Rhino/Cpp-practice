#include<iostream>
using namespace std;
//递增运算符++重载
//1、前置递增
//2、后置递增 
class MyInteger//自定义整型变量 
{
	//想用重载左移运算符函数访问私有，需要设置友元 
	friend ostream & operator<<(ostream &cout,MyInteger myint);
	public:
		MyInteger()
		{
			m_Num=0;
		}
		//1、重载前置递增运算符 
		MyInteger &operator++()//因为重载的<<只能输出MyInteger类型，所以需要返回该类型的对象
		//返回引用是为了防止系统调用拷贝构造函数创建新的一个对象，将无法实现对同一个对象的多次递增 
		{
			//先进行++运算 
			 m_Num++;
			 //再返回自身 
			 return *this;
		}
		//2、重载后置递增运算符
		//int 代表占位参数可以用于区分前置递增和后置递增，只能用int作占位参数，编译器会自行区分前置和后置 
		MyInteger operator++(int)//后置递增一定不能返回引用，因为返回的是局部对象的引用，因此后置递增不支持多次调用 
		{
			//先记录当时的结果
			MyInteger temp=*this; 
			//再递增
			m_Num++;
			//再将结果返回 
			return temp;
		} 
		private:
			int m_Num;
}; 
//重载左移运算符<<
ostream & operator<<(ostream &cout,MyInteger myint)
{
	cout<<myint.m_Num;
	return cout; 
}
void test01()
{
	MyInteger myint;
	//想要像对整型变量操作一样，实现递增运算，需要重载++
	//要想正常输出自定义类型，首先需要重载左移运算符<< 
	cout<<++(++myint)<<endl;//因为返回引用，所以可以多次递增
	cout<<myint<<endl; 
}
void test02()
{
	MyInteger myint;
	cout<<myint++<<endl;
	cout<<myint<<endl;
} 
int main()
{
	test01(); 
	test02();
	system("pause");
	return 0;
}
