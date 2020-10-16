#include <iostream>

using namespace std;
void insrt(int *arr,int s,int k){
        if(arr[s]==-1){
            arr[s]=k;
            return ;
        }
        else{
            insrt(arr,s+1,k);
        }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n,e;
        cin>>n>>e;
        int arr1[2*e];
        int arr2[2*e];
        int arr3[e][e]={-1};
        int arr4[e][e]={-1};
        for(int ii=0; ii<2*e; ii++){
            arr1[ii];
        }
        for(int ii=0; ii<2*e; ii++){
            arr2[ii];
        }
        for(int k=0; k<2*e; k=k+2){
            insrt(arr3[arr1[k]],0,arr1[k+1]);
        }
        for(int k=0; k<2*e; k=k+2){
            insrt(arr4[arr2[k]],0,arr2[k+1]);
        }
    }
    return 0;
}
