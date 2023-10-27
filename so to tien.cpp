#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cout<<"nhap gia tien:";
	cin>>e;
	a=e/100;b=e%100/20;c=e%100%20/5;d=e%100%20%5;
    cout<<"\nso to 100:"<<a;
    cout<<"\nso to 20:"<<b;
    cout<<"\nso to 5:"<<c;
    cout<<"\nso to 1:"<<d;
    cout<<"\nso to 100:"<<a+b+c+d;
    system("pause");
		
	
	
	
}
