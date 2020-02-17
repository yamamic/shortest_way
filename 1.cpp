#include<iostream>
using namespace std;
#include<string>
#include<iomanip>
class TSP
{
private:
	int start;
	int **distance;
	int *sign;
	int city_num;
	int TSPlength;
public:
	TSP(int citynum);
	void correct_distance();
	void printlength();
	void tspleastn();
};
TSP::TSP(int citynum)//初始化
{
	int i,j;
	city_num=citynum;
	distance=new int*[city_num+1];
	for(i=1;i<=city_num;i++)
	{
		distance[i]=new int[city_num+1];
		cout<<"输入城市"<<i<<"依次到其他城市的距离:"<<endl;
		for(j=1;j<=city_num;j++)
		{
			cout<<"城市"<<i<<"到城市"<<j<<": ";
			cin>>distance[i][j];
			cout<<endl;
		}
	}
	cout<<"输入完成"<<endl;
	sign=new int[city_num];
	for(i=1;i<=city_num;i++)
	{
		sign[i]=0;
	}
	TSPlength=0;
}
void TSP::correct_distance()//将同城市的距离改为0
{
	int i;
	for(i=1;i<=city_num;i++)
		distance[i][i]=0;
}
void TSP::printlength()//输出各城市之间的距离
{
	int i,j;
	for(i=1;i<=city_num;i++)
	{
		for(j=1;j<=city_num;j++)
		{
			if(i!=j)
				cout<<i<<"-"<<j<<":"<<distance[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void TSP::tspleastn()//贪婪法求路径,长度
{
	int i,j,minlength,edgecount(0);
	int start_city;
	int next_city;
	cout<<"输入出发城市:";
	cin>>start;
	sign[start]=1;
	start_city=start;
	cout<<"路径为:"<<start_city;
	while(edgecount<city_num-1)
	{
		minlength=100;
		for(i=1;i<=city_num;i++)
		{
			if(i!=start&&sign[i]==0&&distance[start][i]<minlength)
			{
				next_city=i;
				minlength=distance[start_city][i];
			}
		}
		sign[next_city]=1;
		TSPlength+=minlength;
		cout<<"-"<<next_city;
		start_city=next_city;
		edgecount++;
	}
	TSPlength+=distance[next_city][start];
	cout<<"-"<<start;
	cout<<endl<<"总路径长度: "<<TSPlength<<endl;
}
int main()
{
	int citynum;
	cout<<"请输入城市数量: ";
	cin>>citynum;
	TSP T(citynum);
	T.correct_distance();
	T.printlength();
	T.tspleastn();
}