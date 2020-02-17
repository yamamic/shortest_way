#include<iostream>
<<<<<<< HEAD
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
=======
#include<iomanip>
#include<cmath>
using namespace std;
#define MAX_IN 10
 
class Tsp
{
	private:
		int city_number;		//城市个数
		int **distance;			//城市距离矩阵
		int **process;			//求最短路径的过程矩阵
	public:
		Tsp(int city_number);		//构造函数
		void correct();			//矫正输入的城市代价矩阵
		void printCity();		//打印城市的距离矩阵
		void getShoretstDistance();	//动态规划法求最短路径
		void printProcess();		//打印过程矩阵
 
};
 
//构造函数
Tsp::Tsp(int city_num)
{
	int i=0,j=0;
	city_number=city_num;
 
	//初始化城市距离矩阵
	distance=new int*[city_number];
	cout<<"请输入"<<city_number<<"个城市之间的距离"<<endl;
	for(i=0;i<city_number;i++)
	{
		distance[i]=new int[city_number];
		for(j=0;j<city_number;j++)
			cin>>distance[i][j];
	}
 
	//生成过程矩阵
	process=new int*[city_number];
	for(i=0;i<city_number;i++)
	{
		process[i]=new int[1<<(city_number-1)];
	}
	
 
}
 
//纠正用户输入的城市代价矩阵
void Tsp::correct()
{
	int i;
	for(i=0;i<city_number;i++)
	{
		distance[i][i]=0;
	}
}
 
//打印城市距离
void Tsp::printCity()
{
	int i,j;
	//打印代价矩阵
	cout<<"您输入的城市距离如下"<<endl;
	for(i=0;i<city_number;i++)
	{
		for(j=0;j<city_number;j++)
			cout<<setw(3)<<distance[i][j];
		cout<<endl;
	}
}
 
//动态规划法求最短路径
void Tsp::getShoretstDistance()
{
	int i,j,k;
	//初始化第一列
	for(i=0;i<city_number;i++)
	{
		process[i][0]=distance[i][0];
	}
	//初始化剩余列
	for(j=1;j<(1<<(city_number-1));j++)
	{
		for(i=0;i<city_number;i++)
		{
			process[i][j]=0x7ffff;//设0x7ffff为无穷大
 
			//对于数字x，要看它的第i位是不是1，通过判断布尔表达式 (((x >> (i - 1) ) & 1) == 1的真值来实现
 
			if(((j>>(i-1))&1)==1)
			{
				continue;
			}
			for(k=1;k<city_number;k++)
			{
				//不能达到k城市
				if(((j>>(k-1))&1)==0)
				{
					continue;
				}
				if(process[i][j]>distance[i][k]+process[k][j ^ (1 << (k - 1))])
				{
					process[i][j]=distance[i][k]+process[k][j ^ (1 << (k - 1))];				
					//cout<<i<<"行"<<j<<"列为："<<process[i][j]<<endl;
				}
			}
		}
	}
	cout<<"最短路径为"<<process[0][(1<<(city_number-1))-1]<<endl;
 
}
 
//打印过程矩阵
void Tsp::printProcess()
{
	int i,j;
	for(j=0;j<1<<(city_number-1);j++)
	{
		cout<<setw(3)<<j;
	}
	cout<<endl;
	for(i=0;i<city_number;i++)
	{
		for(j=0;j<1<<(city_number-1);j++)
		{
			if(process[i][j]==0x7ffff)
				process[i][j]=-1;
			cout<<setw(3)<<process[i][j];
		}
		cout<<endl;
		
	}
}
 
//主函数
int main(void)
{
	cout<<"欢迎来到动态规划求旅行商问题，请输入城市个数: ";
	int city_number;
	cin>>city_number;
    Tsp tsp(city_number);		
    tsp.correct();					
	tsp.printCity();				
	tsp.getShoretstDistance();	
	tsp.printProcess();			//打印计算矩阵
	return 0;
}
>>>>>>> 2b82b0e87726903c81a9024310d0c18b65b89509
