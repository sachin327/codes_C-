#include <bits/stdc++.h>
using namespace std;
void DFS(int *m,int v,int p,int *arr){
    arr[p]=1;
    cout<<p;
    for(int i=1; i<v; i++){
        if ((m+p*v)[i]==1 && arr[i]==0){
            DFS(m,v,i,arr);
        }
    }
    return ;
}
int main()
{
    int t;
    cin>>t;
    for(int ii=0; ii<t; ii++){
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
        DFS(*m,v+1,1,arr);

    }
    return 0;
}
