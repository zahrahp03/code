#include<iostream>
#include<conio.h>
using namespace std;
 
main()
{
long int n;
cout<<"please enter a number:";
cin>>n;
cout<<"\n\n";
while(n>0)
{
cout<<n%10;
n/=10;
}
cout<<"\n\n\n"<<"press any key to exit...";
getch();
return 0;
}
//>     sourceiran.com