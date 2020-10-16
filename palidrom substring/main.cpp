#include <iostream>
using namespace std;
int matrix[1000][1000];
string S;
int start;
int end_;
int s;
bool check(int i,int j){
    if(i==j){
        return true;
    }
    if(abs(j-i)==1 && S[i]==S[j]){
        return true;
    }
    if(matrix[i][j]==1){
        return true;
    }
    return false;
}

int main(){
    int  t;
    cin>>t;
    for(int ii=0; ii<t; ii++){
        S="";
        cin>>S;
        int n=S.length();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    matrix[i][j]=1;
                }
                else{matrix[i][j]=0;}
            }
        }
        int i=0;
        int j=1;
        s=0;
        start=0;
        end_=0;
        while(j<n){
            int jj=j;
            int ii=i;
            while(jj<n && ii<n){
                if(S[ii]==S[jj] && check(ii+1,jj-1)){
                    matrix[ii][jj]=1;
                }
                if(matrix[ii][jj]==1){
                    int ss=jj-ii+1;
                    if(ss>s){
                        s=ss;
                        start=ii;
                        end_=jj;
                    }
                }
                jj++;
                ii++;
            }
            j++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=start; i<end_+1; i++){
            cout<<S[i];
        }
        cout<<endl;
        (s>0) ? cout<<s<<endl: cout<<1<<endl;
    }
    return 0;
}
