#include <bits/stdc++.h>
using namespace std;

int maxHist(int *n,int m){

    stack <int> result;
    int top_val,maxx,area=0;
    int i=0;
    while (i<m){
        if(result.empty() || n[result.top()]<=n[i]){
            result.push(i++);
        }
        else{
            top_val=n[result.top()];
            result.pop();
            area=top_val*i;
            if(!result.empty()){
                area=top_val*(i-result.top()-1);
            }
            maxx=max(area,maxx);
        }
    }
    while(!result.empty()){
        top_val=n[result.top()];
        result.pop();
        area=top_val*i;
        if(!result.empty()){
                area=top_val*(i-result.top()-1);
        }
        maxx=max(area,maxx);
        }
    return maxx;
    }


int main()
{
    int arr[7]={6,2,5,4,5,1,6};
    int k=maxHist(arr,7);
    return 0;
}
