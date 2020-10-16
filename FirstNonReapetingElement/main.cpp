#include <bits/stdc++.h>
using namespace std;

void check(char *arr,int n){
    int arr1[26]={0};
    queue <char> q;
    for(int i=0; i<n; i++){
        if(arr1[arr[i]-97]==0){
            q.push(arr[i]);
        }
        arr1[arr[i]-97]++;
        if(q.empty()){
            arr[i]='1';
        }
        else if(arr1[q.front()-97]==1){
            arr[i]==q.front();
        }
        else{
            while(arr1[q.front()-97]!=1){
                q.pop();
                if(q.empty()){
                    arr[i]='1';
                    break;
                }
            }
        }
        if(arr[i]=='1'){
            continue;
        }
        arr[i]=q.front();
    }

}
int main()
{
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    check(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
