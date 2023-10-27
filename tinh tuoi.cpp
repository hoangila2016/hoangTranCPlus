#include<iostream>
using namespace std;
int main()
{
	int max,a,b,c;
	cout<<"nhap 3 so lien tiep la\n";
	cin>>a>>b>>c;
	max=a;
	if(max<b) max=b;
	if(max<c) max=c;
	cout<<"so max la:"<<max;
	

	

	system("pause");
}
