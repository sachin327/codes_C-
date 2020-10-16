#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int n,k;
    cin>>n>>k;
    int arr[n];
    int ss=0;
    for (long long int i=0; i<n; i++){
        arr[i]=i;
    }
    for (long long int i=0; i<k; i++){
        int s=0;
        int p=0;
        for (long long int j=0; j<n; j++){
            if(arr[j]>s){
                s=arr[j];
                p=j;
            }
        }
        arr[p]=arr[p]/2;
        ss=ss+s;
    }
    cout<<ss;
    return 0;
}
