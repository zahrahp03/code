#include<iostream>
using namespace std;
int f(int,int[],int );
int main(){
    int number;
    cout<<"enter number";
    cin>>number;
    int arr[5]={1,2,5,10,50};
    int counter=0;
    int i=0;
    counter=f(number,arr,i);
    cout<<counter;
    return 0;

}
int f(int number,int arr[5],int i){
    if(number>0&& i==5){
     return 0;
    }
    if(number==0){
        return 1;
    }
    if(number<0){
        return 0;
    }
    return f(number - arr[i], arr, i) + f(number,arr, i + 1);
}