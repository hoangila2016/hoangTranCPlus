#include<iostream>
using namespace std;
int main()
{
	int soduong;
	cout<<"so uong cua ban la:";
	cin>>soduong;
	cout<<"\nso la ma duoc quy doi la:";
	if(soduong>=900&&soduong<1000)
	cout<<"CD";
	soduong=soduong-900;
 
	if(soduong>=800&&soduong<900)
	cout<<"DCCC";
	soduong=soduong-800;
	 
	if(soduong>=700&&soduong<800)
	cout<<"DCC";
	soduong=soduong-700;
	 if(soduong>=600&&soduong<700)
	cout<<"DC";
	soduong=soduong-600;
	 if(soduong>=500&&soduong<600)
	cout<<"D";
	soduong=soduong-500;
	 if(soduong>=400&&soduong<500)
	cout<<"CD";
	soduong=soduong-400;
	 if(soduong>=300&&soduong<400)
	cout<<"CCC";
	soduong=soduong-300;
	 if(soduong>=200&&soduong<300)
	cout<<"CC";
	soduong=soduong-200;
	 if(soduong>=100&&soduong<200)
	cout<<"C";
	soduong=soduong-100;
	 if(soduong>=90&&soduong<100)
	cout<<"XC";
	soduong=soduong-90;
	 if(soduong>=80&&soduong<90)
	cout<<"LXXX";
	soduong=soduong-80;
	 if(soduong>=70&&soduong<80)
	cout<<"LXX";
	soduong=soduong-70;
	 if(soduong>=60&&soduong<70)
	cout<<"LX";
	soduong=soduong-60;
	 if(soduong>=50&&soduong<60)
	cout<<"L";
	soduong=soduong-50;
	 if(soduong>=40&&soduong<50)
	cout<<"XL";
	soduong=soduong-40;
	 if(soduong>=30&&soduong<40)
	cout<<"XXX";
	soduong=soduong-30;
	 if(soduong>=20&&soduong<30)
	cout<<"XX";
	soduong=soduong-20;
	 if(soduong>=10&&soduong<20)
	cout<<"X";
	soduong=soduong-10;
	 if(soduong==9)
	cout<<"IX";
	soduong=soduong-9;
	 if(soduong==8)
	cout<<"VIII";
	soduong=soduong-8;
     if(soduong==7)
	cout<<"VII";
	soduong=soduong-7;
	 if(soduong==6)
	cout<<"VI";
	soduong=soduong-6;
	 if(soduong==5)
	cout<<"V";
	soduong=soduong-5;
	 if(soduong==4)
	cout<<"IV";
	soduong=soduong-4;
	 if(soduong==3)
	cout<<"III";
	soduong=soduong-3;
	 if(soduong==2)
	cout<<"II";
	soduong=soduong-2;
	 if(soduong==1)
	cout<<"I";
	soduong=soduong-1;
	

	
	system("pause");
}
