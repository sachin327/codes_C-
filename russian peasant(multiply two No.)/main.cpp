#include <iostream>

using namespace std;
long long int Russian_Peasant(long long int a,long long int b){
    long long int res=0;
    if(a<b){
        long long int temp=b;
        b=a;
        a=temp;
    }

    while(b!=1){
        if(b%2==1){
            res=res+a;
        }
        a=a*2;
        b=b/2;
    }
    return (res+a);
}
int main()
{
    cout<<Russian_Peasant(14789654782,12837289434);
    return 0;
}
