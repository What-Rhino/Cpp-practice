#include<iostream>
using namespace std;
class Student//封装一类对象，包括其属性和行为 ,属性和行为统称为成员 
{
	public://公共权限 
		//属性 ，也叫成员属性或成员变量 
		string m_Name;//姓名 
		int m_Id; //学号
		//行为（也叫成员函数或成员方法）：显示学生的姓名和学号
		void showStudent()
		{
			cout<<"姓名："<<m_Name<<"学号："<<m_Id<<endl; 
		} 	
		void setName(string name)//也可通过行为来对属性进行赋值操作 
		{
			m_Name=name;
		}
		void setId(int id)
		{
			m_Id=id;
		}
};//要有分号！ 
int main()
{
	//实例化：创建一个具体的学生对象
	Student s1;
	s1.m_Name="张三";
	s1.m_Id=1;
	s1.showStudent();
	Student s2;
	s2.setName("李四");
	s2.setId(2);
	s2.showStudent(); 
	system("pause");
	return 0;
}
