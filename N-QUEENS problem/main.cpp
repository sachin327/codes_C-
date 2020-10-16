#include <bits/stdc++.h>
using namespace std;
stack <int> S;
int n;
//if you want only one solution remove all comments(except this one)
int a=0;
void check1(int *mtrx,int s1,int s2,int s)
{
    if(s==n){
        //a=1;
        stack <int> S1;
        while(!S.empty())
        {
            S1.push(S.top());
            S.pop();
            cout<<S1.top()<<" ";
        }
        cout<< endl;
        while(!S1.empty())
        {
            S.push(S1.top());
            S1.pop();
        }
        return ;
    }
    for(int i=0; i<n; i++)
    {
        if((mtrx+(s2*n))[i]==0)
        {
            s1=i;


            for(int j=0; j<n-s2; j++)
            {
                (mtrx+((s2+j)*n))[s1]++;
            }
            if(s1==0)
            {
                for(int j=1; j<n-s2; j++)
                {
                    (mtrx+((s2+j)*n))[s1+j]++;
                }
            }
            else if(s1==(n-1))
            {
                for(int j=1; j<n-s2; j++)
                {
                    (mtrx+((s2+j)*n))[s1-j]++;
                }
            }
            else
            {
                for(int j=1; j<=s1; j++)
                {
                    (mtrx+((s2+j)*n))[s1-j]++;
                }
                for(int j=1; j<n-s1; j++)
                {
                    (mtrx+((s2+j)*n))[s1+j]++;
                }
            }

            S.push(i);
            check1(mtrx,0,s2+1,s+1);
            //if(a==1){
              //  return ;
            //}
            for(int j=0; j<n-s2; j++)
            {
                (mtrx+((s2+j)*n))[s1]--;
            }
            if(s1==0)
            {
                for(int j=1; j<n-s2; j++)
                {
                    (mtrx+((s2+j)*n))[s1+j]--;
                }
            }
            else if(s1==(n-1))
            {
                for(int j=1; j<n-s2; j++)
                {
                    (mtrx+((s2+j)*n))[s1-j]--;
                }
            }
            else
            {
                for(int j=1; j<=s1; j++)
                {
                    (mtrx+((s2+j)*n))[s1-j]--;
                }
                for(int j=1; j<n-s1; j++)
                {
                    (mtrx+((s2+j)*n))[s1+j]--;
                }
            }
            S.pop();

        }
    }
}
void check(int *mtrx)
{
    check1(mtrx,0,0,0);
}
int main()
{

    int t;
    cin>>t;
    for(int ii=0; ii<t; ii++){
        cin>>n;
        //a=0;
        /*while(!S.empty())
        {
            S.pop();
        }*/
        int mtrx [n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mtrx[i][j]=0;
            }
        }
        if(n==0 || n==1 || n==2 || n==3){
            cout<<"NOT POSSIBLE"<<endl;
        }
        else{check(*mtrx);}

    }
}
