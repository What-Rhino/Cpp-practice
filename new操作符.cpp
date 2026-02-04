#include<iostream>
using namespace std;
int * func()
{
	int * p=new int(10);//把数字10存放在堆区 
	return p;
}
void test01()
{
	int * p=func();
	cout<<*p<<endl;
	cout<<*p<<endl;
	delete p;//利用delete关键字释放内存 
	cout<<*p<<endl;//内存已经被释放，会出现错误 
}
void test02()
{
	//创建10整型数据的数组，在堆区
	int *arr=new int[10]; 
	for(int i=0;i<10;i++)
	{
		arr[i]=i+100;//给数组赋值 
	}
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<endl;
	}
	delete [] arr;//释放数组的时候要加上[]才可以 
}
int main()
{
	test01();
	test02(); 
	system("pause");
	return 0;
}
