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
TSP::TSP(int citynum)//��ʼ��
{
	int i,j;
	city_num=citynum;
	distance=new int*[city_num+1];
	for(i=1;i<=city_num;i++)
	{
		distance[i]=new int[city_num+1];
		cout<<"�������"<<i<<"���ε��������еľ���:"<<endl;
		for(j=1;j<=city_num;j++)
		{
			cout<<"����"<<i<<"������"<<j<<": ";
			cin>>distance[i][j];
			cout<<endl;
		}
	}
	cout<<"�������"<<endl;
	sign=new int[city_num];
	for(i=1;i<=city_num;i++)
	{
		sign[i]=0;
	}
	TSPlength=0;
}
void TSP::correct_distance()//��ͬ���еľ����Ϊ0
{
	int i;
	for(i=1;i<=city_num;i++)
		distance[i][i]=0;
}
void TSP::printlength()//���������֮��ľ���
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
void TSP::tspleastn()//̰������·��,����
{
	int i,j,minlength,edgecount(0);
	int start_city;
	int next_city;
	cout<<"�����������:";
	cin>>start;
	sign[start]=1;
	start_city=start;
	cout<<"·��Ϊ:"<<start_city;
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
	cout<<endl<<"��·������: "<<TSPlength<<endl;
}
int main()
{
	int citynum;
	cout<<"�������������: ";
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
		int city_number;		//���и���
		int **distance;			//���о������
		int **process;			//�����·���Ĺ��̾���
	public:
		Tsp(int city_number);		//���캯��
		void correct();			//��������ĳ��д��۾���
		void printCity();		//��ӡ���еľ������
		void getShoretstDistance();	//��̬�滮�������·��
		void printProcess();		//��ӡ���̾���
 
};
 
//���캯��
Tsp::Tsp(int city_num)
{
	int i=0,j=0;
	city_number=city_num;
 
	//��ʼ�����о������
	distance=new int*[city_number];
	cout<<"������"<<city_number<<"������֮��ľ���"<<endl;
	for(i=0;i<city_number;i++)
	{
		distance[i]=new int[city_number];
		for(j=0;j<city_number;j++)
			cin>>distance[i][j];
	}
 
	//���ɹ��̾���
	process=new int*[city_number];
	for(i=0;i<city_number;i++)
	{
		process[i]=new int[1<<(city_number-1)];
	}
	
 
}
 
//�����û�����ĳ��д��۾���
void Tsp::correct()
{
	int i;
	for(i=0;i<city_number;i++)
	{
		distance[i][i]=0;
	}
}
 
//��ӡ���о���
void Tsp::printCity()
{
	int i,j;
	//��ӡ���۾���
	cout<<"������ĳ��о�������"<<endl;
	for(i=0;i<city_number;i++)
	{
		for(j=0;j<city_number;j++)
			cout<<setw(3)<<distance[i][j];
		cout<<endl;
	}
}
 
//��̬�滮�������·��
void Tsp::getShoretstDistance()
{
	int i,j,k;
	//��ʼ����һ��
	for(i=0;i<city_number;i++)
	{
		process[i][0]=distance[i][0];
	}
	//��ʼ��ʣ����
	for(j=1;j<(1<<(city_number-1));j++)
	{
		for(i=0;i<city_number;i++)
		{
			process[i][j]=0x7ffff;//��0x7ffffΪ�����
 
			//��������x��Ҫ�����ĵ�iλ�ǲ���1��ͨ���жϲ������ʽ (((x >> (i - 1) ) & 1) == 1����ֵ��ʵ��
 
			if(((j>>(i-1))&1)==1)
			{
				continue;
			}
			for(k=1;k<city_number;k++)
			{
				//���ܴﵽk����
				if(((j>>(k-1))&1)==0)
				{
					continue;
				}
				if(process[i][j]>distance[i][k]+process[k][j ^ (1 << (k - 1))])
				{
					process[i][j]=distance[i][k]+process[k][j ^ (1 << (k - 1))];				
					//cout<<i<<"��"<<j<<"��Ϊ��"<<process[i][j]<<endl;
				}
			}
		}
	}
	cout<<"���·��Ϊ"<<process[0][(1<<(city_number-1))-1]<<endl;
 
}
 
//��ӡ���̾���
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
 
//������
int main(void)
{
	cout<<"��ӭ������̬�滮�����������⣬��������и���: ";
	int city_number;
	cin>>city_number;
    Tsp tsp(city_number);		
    tsp.correct();					
	tsp.printCity();				
	tsp.getShoretstDistance();	
	tsp.printProcess();			//��ӡ�������
	return 0;
}
>>>>>>> 2b82b0e87726903c81a9024310d0c18b65b89509
