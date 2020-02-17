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