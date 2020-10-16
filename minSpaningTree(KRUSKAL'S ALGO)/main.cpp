#include<iostream>
#define E 10000
using namespace std;
int arr1[3*E]={0};
int main(){
	int t=0;
	cin>>t;
	for(int ii=0; ii<t; ii++){
        int v,e,s;
        cin>>v>>e;
        s=0;
        int arr2[v]={0};
        int arr3[v]={0};
        for(int i=0; i<e; i++){
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            arr1[s]=a1-1;
            arr1[s+1]=a2-1;
            arr1[s+2]=a3;
            s=s+3;
        }
        int arr[v]={0};
        cout<<"arr is "<<" ";
        for(int i=0; i<v; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"arr1 is "<<" ";
        for(int i=0; i<3*e; i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        int ss=0;
        int j=0;
        while (j<v-1){
            s=1000;
            int in=0;
            for(int i=2; i<3*e; i=i+3){
                if(arr1[i]<s){
                    s=arr1[i];
                    in=i;
                }
            }
            arr1[in]=10000;
            if(arr2[min(arr1[in-2],arr1[in-1])]>0 && arr3[max(arr1[in-2],arr1[in-1])]>0){
                continue;
            }
            arr2[min(arr1[in-2],arr1[in-1])]++;
            arr3[max(arr1[in-2],arr1[in-1])]++;
            ss=ss+s;
            j++;
        }
        cout<<"arr is "<<" ";
        for(int i=0; i<v; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"arr1 is "<<" ";
        for(int i=0; i<3*e; i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        cout<<ss<<endl;
	}
	return 0;
}
