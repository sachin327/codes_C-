#include <bits/stdc++.h>

using namespace std;

void check(int *arr,int n){
    queue <int> q;
    q.push(n);
    for(int i=n-1; i>0; i--){
        q.push(i);
        for(int ii=0; ii<i; ii++){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
    }
    int i=1;
    while(i<n+1){
        arr[n-i]=q.front();
        q.pop();
        i++;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n]={0};
    check(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
