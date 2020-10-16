#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a<b){
        return gcd(b,a);
    }
    else if(a%b==0){
        return b;
    }
    else return gcd(b,a%b);
}
int power(int a,int n,int p){
    a=a%p;
    int result=1;
    while (n>0){
        if(n%2!=0){
            result=(result*a)%p;
        }
        n=n/2;
        a=(a*a)%p;
    }
    return result;

}
bool check(int i,int k){
    if(i<=1 ||i==4){
        return false;
    }
    if(i<=3){
        return true;
    }
    while (k>0){
        int a=2+rand()%(i-4);
        if(gcd(i,a)!=1){
            return false;
        }
        if(power(a,i-1,i)!=1)
            return false;
        k--;
    }
    return true;
}
bool prime(int x){
    int k=10;
    check(x,k);
}
int main()
{
    int t;
    cin>>t;
    cout<<prime(t);

    return 0;
}
