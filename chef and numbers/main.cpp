#include <iostream>

using namespace std;

int main()
{   int t,n,max_;
    cin>>t;
    for(int ii=0; ii<t; ii++){
        int arr1[1001]={0};
        cin>>n;
        int arr[n];
        int s=0;
        for (int i=0; i<n; i++){
            cin >>arr[i];
            if(i==0){
                arr1[arr[i]]+=1;
                cout<<endl;
                cout<<i<<endl;
                continue;
            }
            else if(arr[i]==arr[i-1]){
                if(s==0){
                    s=1;
                    continue;
                }
                else {
                    arr1[arr[i]]+=1;
                    cout<<i<<endl;
                    s=0;
                    continue;
                }

            }
            s=0;
            arr1[arr[i]]+=1;
            cout<<i<<endl;
        }
    max_=0;
    for(int i=0; i<1001; i++){
            if(arr1[i]>arr1[max_]){
                max_=i;
            }
        }
        cout<<max_;
        for(int i=0; i<10; i++){
            cout<<arr1[i];
        }
        cout<<endl;
    }

    return 0;
}
