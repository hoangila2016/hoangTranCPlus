#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout<<"starer programing\n";
	cout<<setw(5)<<left<<"ID";
	cout<<setw(5)<<right<<"NAME";
	cout<<setw(60)<<right<<"Address\n";
	cout<<setfill('-');
	cout<<setw(6)<<left<<"\n1";
	cout<<setw(5)<<right<<"Nguyen Doan Ngoc Giau";
	cout<<setw(30)<<right<<"SaiGon";
	
	system("pause");
}
