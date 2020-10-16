#include <iostream>

using namespace std;
int rot(int*arr,int n,int i,int k){
    if(i>0 && i<n){
        if(arr[i]==1){
           arr[i]=k;
           return 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    cin>>t;
    int r,c;
    cin>>r>>c;
    int arr[r*c];
    for(int i=0; i<r*c; i++){
        cin>>arr[i];
    }
    int arr1[r*c]={0};
    int s=0;
    int ii=0;
    int m=2;
    int k=0;
    while (true){
        s=0;
        k=0;
        for (int i=0; i<r*c; i++){
            if(arr[i]==1){
                k=1;
            }
            if(arr[i]==m){
                if(i%c==0){
                    s=s+rot(arr,r*c,i+1,m+1);
                    s=s+rot(arr,r*c,i-c,m+1);
                    s=s+rot(arr,r*c,i+c,m+1);
                    continue;
                }
                else if(i%c==c-1){
                    s=s+rot(arr,r*c,i-1,m+1);
                    s=s+rot(arr,r*c,i-c,m+1);
                    s=s+rot(arr,r*c,i+c,m+1);
                    continue;
                }
                s=s+rot(arr,r*c,i+1,m+1);
                s=s+rot(arr,r*c,i-1,m+1);
                s=s+rot(arr,r*c,i-c,m+1);
                s=s+rot(arr,r*c,i+c,m+1);
            }
        }
        if(s==0){
            break;
        }
        ii++;
        m++;
    }
if(k==0){
    cout<<ii;
}
else{cout<<-1;}
}
