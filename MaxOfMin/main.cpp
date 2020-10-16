#include <iostream>

using namespace std;
void MaxOfMin(int *arr,int * arr1,int n){
    for(int i=0; i<n; i++){
        int s;
        for(int j=0; j<n-i; j++){
            int m=arr[j];
            for(int k=1; k<i+1; k++){
                if(m>arr[j+k]){
                    m=arr[j+k];
                    continue;
                }
            }
            if (j==0){
                s=m;
            }
            else if(m>s){
                s=m;
            }
        }
        arr1[i]=s;
    }
}
int main()
{
    int n=7;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    cout<<"\n";
    int arr1[n]={0};
    MaxOfMin(arr,arr1,n);
    for(int i=0; i<n; i++){
        cout<<arr1[i];
    }
    return 0;
}
