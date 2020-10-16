#include <bits/stdc++.h>
using namespace std;

void solve(int *arr,int n){
    stack <int> S;
    int top_val;
    int i=n-1;
    while (i>=0){
        if(S.empty() || arr[i]<=arr[S.top()]){
            S.push(i--);
        }
        else{
            top_val=S.top();
            arr[top_val]=top_val-i;
            S.pop();
        }
    }
    while(!S.empty()){
        top_val=S.top();
        arr[top_val]=top_val-i;
        S.pop();
    }
}
int main()
{
    int n=6;
    int arr[7]={100,80,60,70,60,75,85};
    int arr1[6]={10,4,5,90,120,80};
    for(int i=0; i<n; i++){
        cout <<arr1[i]<<" ";
    }
    solve(arr1,n);
    cout<<endl;
    for(int i=0; i<n; i++){
        cout <<arr1[i]<<" ";
    }
    return 0;
}
