#include <iostream>
using namespace std;
void left_(int *arr,int *arr1,int i,int n,int s){
    if(i>=n){
        return ;
    }
    left_(arr,arr1,((2*i)+1),n,s+1);
    if(s%2==1){
        arr1[s]=arr[i];
    }

}
void right_(int *arr,int *arr1,int i,int n,int s){
    if(i>=n){
        return ;
    }
    right_(arr,arr1,((2*i)+2),n,s+1);
    if(s%2==0){
        arr1[s]=arr[i];
    }
}
int check(int a){
    int s=0;
    int m=0;
    while(a!=1){
        if(a%2==1){
            s=1;
        }
        a=a/2;
        m++;
    }
    if(s==1){
        return m+1;
    }
    return m;
}
int main()
{
    int n=31;
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i]=i+1;
    }
    int nn=check(n+1);
    int arr1[nn]={0};
    for(int i=0; i<nn; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    left_(arr,arr1,0,n,0);
    right_(arr,arr1,0,n,0);
    for(int i=0; i<nn; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    return 0;
}

