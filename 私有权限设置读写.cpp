#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
	public:
		//设置姓名
		void setName(string name)
		{
			m_Name=name;
		} 
		//获取姓名
		string getName()
		{
			return m_Name; 
		}
		//获取偶像
		string getIdol()
		{
			m_Idol="小明";
			return m_Idol;
		}
		//设置年龄(0-150)
		void setAge(int age)
		{
			if(age<0||age>150)
			{
				cout<<"年龄输入有误，赋值失败"<<endl;
				return;//退出该函数 
			}
			else
			{
				m_Age=age;
				cout<<"年龄："<<m_Age<<endl;
			}
		}
	private: 
		string m_Name;//姓名 可读可写
		string m_Idol;//只读 
		int m_Age;//年龄 只写 （必须在0-150之间） 
};
int main()
{
	Person p;
	p.setName("张三");//设置姓名 
	cout<<"姓名："<<p.getName()<<endl; //获取姓名 
	cout<<"偶像："<<p.getIdol()<<endl;//获取偶像 
	p.setAge(160);//超出范围无法赋值
	p.setAge(66); 
	system("pause");
	return 0;
}
