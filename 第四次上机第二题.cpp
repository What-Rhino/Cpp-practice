#include<iostream>
#include<cstring>
using namespace std;
class Goods
{
	private:
		char id[6];//商品编号 
		char *name;//商品名称
		double price;//商品价格 
	public:
		Goods(const char id[]="000000",const char *pname="Goods",double d=0)
		{
			strcpy(this->id,id);
			name=new char[strlen(pname)+1];
			strcpy(name,pname);
			price=d;
		}
		Goods(const Goods &goods)
		{
			if(goods.id!=NULL&&goods.name!=NULL)
			{
				strcpy(id,goods.id);
				name=new char[strlen(goods.name)+1];
				strcpy(name,goods.name);
				price=goods.price;
			}
			else 
			{
				strcpy(id,"000000");
				name=new char[sizeof("Goods")+1];
				strcpy(name,"Goods");
				price=0;
			}
		}
		void setPrice(double p)
		{
			price=p;
		}
		double getPrice()const
		{
			return price;
		}
		const char *getID()
		{
			return id;
		}
		void show()const
		{
			cout<<"["<<id<<"]"<<name<<": "<<price<<"RMB 消费金额"<<price*0.8<<endl;
		}
		void copy(const Goods& goods)
		{
			strcpy(id,goods.id);
			name=new char[strlen(goods.name)+1];
			strcpy(name,goods.name);
			price=goods.price;
		}
		~Goods()
		{
			if(name!=NULL)
			{
				delete [] name;
			}
		}
};
class Record
{
	private:
		Goods goods;
		double cost;//消费金额=商品价格*统一折扣率
		static double discount;//默认0.8
	public:
		Record()//:goods(goods)
		{
			//Goods goods(goods);
			//cost=goods.getPrice()*discount;
		}
		Record(const Goods &Good)//:goods(Good)
		{
			goods.copy(Good);
			cost=goods.getPrice()*discount;
		}
		double getDiscount()
		{
			return discount;
		}
		void show()
		{
			goods.show();
		}
};
double Record::discount=0.8;
int main()
{
	Goods food("200103","桃李面包",2.5);
	Goods dress("100415","T-shirt",129);
	Record r[3]={Record(food),Record(dress)};
	cout<<"折扣率："<<Record(food).getDiscount()<<endl;
	for(int i=0;i<3;i++)
	{
		r[i].Record::show();
	}
//	cout<<"damn";
	return 0;
}
