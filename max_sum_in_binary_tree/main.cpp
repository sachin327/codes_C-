#include <bits/stdc++.h>
using namespace std;
void max_(long long int *arr,long long int *arr1,long long int a,long long int n){
    if(a>=n){
        return ;
    }
    max_(arr,arr1,(2*a)+1,n);
    //arr1[a] represent what if we don't take that element.
    //arr1[a+n] represent what if we take that element.
    if((2*a)+1>=n && (2*a)+2>=n){
        arr1[a]=0;
        arr1[a+n]=arr[a];
    }
    else if((2*a)+1>=n){
        arr1[a]=max(arr1[(2*a)+2],arr1[(2*a)+2+n]);
        arr1[a+n]=arr1[(2*a)+2]+arr[a];
    }
    else if((2*a)+2>=n){
        arr1[a]=max(arr1[(2*a)+1],arr1[(2*a)+1+n]);
        arr1[a+n]=arr1[(2*a)+1]+arr[a];
    }
    else {
        arr1[a]=max(arr1[(2*a)+1],arr1[(2*a)+1+n])+max(arr1[(2*a)+2],arr1[(2*a)+2+n]);
        arr1[a+n]=arr1[(2*a)+1]+arr1[(2*a)+2]+arr[a];
    }
    max_(arr,arr1,(2*a)+2,n);
    if((2*a)+1>=n && (2*a)+2>=n){
        arr1[a]=0;
        arr1[a+n]=arr[a];
    }
    else if((2*a)+1>=n){
        arr1[a]=max(arr1[(2*a)+2],arr1[(2*a)+2+n]);
        arr1[a+n]=arr1[(2*a)+2]+arr[a];
    }
    else if((2*a)+2>=n){
        arr1[a]=max(arr1[(2*a)+1],arr1[(2*a)+1+n]);
        arr1[a+n]=arr1[(2*a)+1]+arr[a];
    }
    else {
        arr1[a]=max(arr1[(2*a)+1],arr1[(2*a)+1+n])+max(arr1[(2*a)+2],arr1[(2*a)+2+n]);
        arr1[a+n]=arr1[(2*a)+1]+arr1[(2*a)+2]+arr[a];
    }
}
int main()
{
    long long int n;
    cin>>n;

    long long int arr1[n];
    for (long long int i=0; i<n; i++){
        arr1[i]=i+1;
    }
    long long int arr2[2*n]={0};
    /*for (long long int i=0; i<2*n; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;*/
    max_(arr1,arr2,0,n);
    /*for (long long int i=0; i<2*n; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;*/
    cout<<max(arr2[0],arr2[n]);

    return 0;
}
