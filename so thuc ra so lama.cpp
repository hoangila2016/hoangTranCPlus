#include<iostream>
using namespace std;
int main()
{
    int a,b,c,max;
    cin>>a>>b>>c;
    max=a;
    if(a<b){ 
    max=b;
	cout<<"b lon hon a";}
    if(a<c) 
	max=c;
	if(b<c) 
	max=c;
	if(b>c) 
	max=b;

   
    cout<<max;
    system("pause");
    

    



	return 0;
	
}
