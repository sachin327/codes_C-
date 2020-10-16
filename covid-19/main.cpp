#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n,p;
        cin>>n>>p;
        int s=0;
        int ss=0;
        int x;
        int arr[n]={0};
        cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n<<endl;
        cin>>x;
        ss=x;
        for(int j=0; j<n; j++){
            cout<<1<<" "<<j+1<<" "<<1<<" "<<j+1<<" "<<n<<endl;
            cin>>x;
            arr[j]=x;
            s=s+x;
            if(s==ss){
                break;
            }
        }
        int matrix[n][n]={0};
        for(int j=0; j<n; j++){
            for(int jj=0; jj<n; jj++){
                matrix[j][jj]=0;
            }
        }


        for(int j=0; j<n; j++){
            s=0;
            for(int jj=0; jj<n; jj++){
                if(s!=arr[j]){
                    cout<<1<<" "<<j+1<<" "<<jj+1<<" "<<j+1<<" "<<jj+1<<endl;
                    cin>>x;
                    if(x==1){
                        matrix[j][jj]=1;
                        s++;
                    }
                }
            }
        }
        for(int j=0; j<n; j++){
            for(int jj=0; jj<n; jj++){
                cout<<matrix[j][jj]<<" ";
            }
            cout<<endl;
        }
        cin>>x;
        if(x==-1){
            break;
        }

    }

    return 0;
}

