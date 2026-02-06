#include<iostream>
using namespace std;
//虚析构和纯虚析构
class Animal
{
	public:
		Animal()
		{
			cout<<"Animal构造函数调用"<<endl;
		}
		/*virtual ~Animal()//利用虚析构解决无法用父类指针或引用析构子类的问题 
		{
			cout<<"Animal虚析构函数调用"<<endl;
		} */
		//纯虚析构 
		virtual ~Animal()=0;//纯虚析构函数需要声明 也需要在类外进行具体的实现
		//有了纯虚析构之后这个类也属于抽象类 无法实例化对象 
		virtual void speak()=0;//纯虚函数，因为父类的speak函数一般用不到 
}; 
Animal::~Animal()//纯虚析构 
{
	cout<<"Animal纯虚函数调用"<<endl;
} 
class Cat:public Animal
{
	public:
		Cat(string name)
		{
			cout<<"Cat构造函数调用"<<endl;
			m_Name=new string(name);
		}
		virtual void speak()
		{
			cout<<*m_Name<<"小猫在说话"<<endl;
		}
		~Cat()
		{
			if(m_Name!=NULL)
			{
				cout<<"cat析构函数调用"<<endl;
				delete m_Name;
				m_Name=NULL;
			}
		}
		string*m_Name;
};
void test01()
{
	Animal *animal=new Cat("Tom");
	animal->speak();
	//父类指针在析构时 不会调用子类的析构函数 可以将父类析构函数改为虚析构 
	delete animal;
}
int main()
{
	test01();
	system("pause");
	return 0; 
}
