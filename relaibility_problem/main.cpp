#include <bits/stdc++.h>
using namespace std;
int A=0;
void topological_sort(int *m,int v,int p,int *arr,int *arr1){

    if(arr[p]==0){
        arr[p]=1;
        int s=0;
        for(int i=0; i<v; i++){
            if ((m+p*v)[i]==1 && arr[i]==0){
                topological_sort(m,v,i,arr,arr1);
                arr1[A++]=p;
                s=1;
            }
        }
        if(s==0) arr1[A++]=p;
    }
    return ;
}
int main()
{
    int t;
    cin>>t;
    for(int ii=0; ii<t; ii++){
        A=0;
        int v,e;
        cin>>v>>e;
        int m[v+1][v+1];
        for(int i=0; i<v+1; i++){
           for(int j=0; j<v+1; j++){
                m[i][j]=0;
            }
        }
        for(int i=0; i<e; i++){
            int i1,i2;
            cin>>i1>>i2;
            m[i1][i2]=1;
        }
        int arr[v+1]={0};
        int arr1[v+1]={0};
        for(int i=0; i<v+1; i++){
           for(int j=0; j<v+1; j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0; i<v+1; i++){
            topological_sort(*m,v+1,i,arr,arr1);
        }
        for(int i=0; i<v+1; i++){
            cout<<arr1[v-i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
