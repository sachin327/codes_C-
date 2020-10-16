#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> S;
    int n=9;
    int arr[n];
    int arr1[n/2]={-1};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s=0;
    for(int i=0; i<n; i++){
        cout<<i<<endl;
        if(arr[i]==1){
            if(S.empty()){
                arr1[0]=arr[i+1];
                s=0;
                cout<<"inserted "<<arr1[0]<<" s is "<<s<<endl;

            }

            else if(arr[i+1]<arr1[s]){
                s++;
                arr1[s]=arr[i+1];
                cout<<"inserted "<<arr1[s]<<" s is "<<s<<endl;
            }
            else   cout<<"inserted "<<arr[i+1]<<" s is "<<s<<endl;

            S.push(arr[i+1]);
            i++;
            continue;
        }
        if(arr[i]==2){
            if(S.empty()){
                cout<<"No elements to pop"<<endl;
            }
            if(S.top()==arr1[s]){
                cout<<"popped "<<arr1[s]<<" s is "<<s<<endl;
                s--;
            }
            else cout<<"popped "<<S.top()<<" s is "<<s<<endl;
            S.pop();
            continue;
        }
        if(arr[i]==3){
            if(S.empty()){
                cout<<"No elements in stack "<<endl;
            }
            else cout<<"MES is "<<arr1[s]<<" s is "<<s<<endl;
        }
    }
    return 0;
}
