#include<iostream>
using namespace std;
//函数调用运算符()的重载
//由于重载后，使用方式非常像函数调用，所以称为仿函数
//函数调用运算符函数不能为全局函数 
class MyPrint
{
	public:
		//重载函数调用运算符
		void operator()(string test)
		{
			cout<<test<<endl;
		} 
};
//仿函数非常灵活 ，写法不固定
class MyAdd//加法类 
{
	public:
		int operator()(int num1,int num2)
		{
			return num1+num2; 
		}	
}; 
void MyPrint02(string test)
{
	cout<<test<<endl;
} 
void test01()
{
	MyPrint myPrint;//需要先创建该类的一个对象才可以 
	myPrint("hello world");//由于使用起来非常类似于函数调用，所以称为仿函数 
	MyPrint02("hello world"); 
}
void test02()
{
	MyAdd myadd;
	int ret=myadd(100,100);
	cout<<"ret= "<<ret<<endl;
	//匿名函数对象 使用格式 类名（），用完即被释放 
	cout<<MyAdd()(100,100)<<endl; 
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
