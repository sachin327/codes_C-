#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int ii=0; ii<t; ii++){
        int n,m;
        cin>>n>>m;
        int arr1[n];
        int arr2[n];
        for(int i=0; i<n; i++){
            cin>>arr1[i];
        }
        for(int i=0; i<n; i++){
            cin>>arr2[i];
        }
        int mtrx[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                mtrx[i][j]=0;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(arr2[i-1]>j){
                    mtrx[i][j]=mtrx[i-1][j];
                    continue;
                }
                mtrx[i][j]=max(mtrx[i-1][j],(mtrx[i-1][j-arr2[i-1]])+arr1[i-1]);
            }
        }
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                cout<<mtrx[i][j]<<" ";
            }
            cout<<endl;
        }
        int k1=0;
        int mm=m;
        for(int j=1; j<m+1; j++){
            k1=max(k1,mtrx[n][j]);
        }
        for(int i=n; i>0; i--){
            int k2=0;
            int s=0;
            for(int j=1; j<m+1; j++){
                if(mtrx[i][j]==k1){
                    s=1;
                    break;
                }
            }
            if(s==0){
                arr2[i-1]=0;
                continue;
            }
            i--;
            for(int j=1; j<m+1; j++){
                if(mtrx[i][j]==k1){
                    k2=1;
                }
            }
            i++;
            if(k2==1){
                arr2[i-1]=0;
            }
            else {
            mm=mm-arr1[i-1];
            k1=mm;
            arr2[i-1]=1;
            }

        }
        for(int i=0; i<n; i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
    }
}
