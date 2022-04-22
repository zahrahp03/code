#include <iostream>
using namespace std;
long int factorial(int);
int main()
{
    int n;
    cout<<"enter number\n";
    cin>>n;
    cout<<factorial(n);
    return 0;
}
long int factorial(int n){
    long int prod=1;
    int i=2;
    if(n>1){
        while (i<=n)
        {
           prod*=i;
           i++;
           
        }
        
       
    }
    return(prod);
}
