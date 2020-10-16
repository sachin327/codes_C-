#include <iostream>
#include <math.h>
using namespace std;
bool check(long long int i){
    if(i==0 || i==1){
        return false;
    }
    if(i<=3){
        return true;
    }
    if(i%2==0 || i%3==0){
        return false;
    }
    for(long long int j=5; j*j<i; j=j+6){
        if(i%j==0 || i%(j+2)==0){
            return false;
        }
    }
    return true;

}
int main()
{

    cout<<check(pow(2,50));

    return 0;
}
