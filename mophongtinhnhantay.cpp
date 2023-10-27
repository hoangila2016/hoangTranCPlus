#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int d,c,e,f;
	cout<<"nhap gia tri dau tien:";
	cin>>a;
	cout<<"\nnhap gia tri thu hai:";
	cin>>b;
	cout<<"\ntruong trinh mo phong phep nhan tay la";
	cout<<"\n    "<<a;
	cout<<"\n  X "<<b;
	c=b%100%10;d=(b%100-c)/10;f=b%100;e=(b-f)/100;
	cout<<"\n-----------";
	cout<<"\n   "<<c*a;
	cout<<"\n  "<<d*a;
	cout<<"\n "<<e*a;
	cout<<"\n-----------";
	cout<<"\n "<<a*b;
	cout<<"\n    ";
	system("pause");
	
	
}
