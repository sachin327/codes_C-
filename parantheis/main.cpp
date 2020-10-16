#include <bits/stdc++.h>
#include <string.h>
using namespace std;
char rev(char s){
    if(s=='}')
        return '{';
    else if(s==')')
        return '(';
    if(s==']')
        return '[';
}
void check(string s,int n){
    stack <char> S1;
    for(int i=0; i<n; i++){
        S1.push(s[i]);
        if(s[i]=='}' || s[i]==']' || s[i]==')'){
                if(S1.empty()){
                        cout<<"Unbalanced"<<endl;
                        return ;
                    }
                while(S1.top()!=rev(s[i])){
                    S1.pop();
                    if(S1.empty()){
                        cout<<"Unbalanced"<<endl;
                        return ;
                    }
                }
                S1.pop();
            }
    }
    if(S1.empty())
        cout<<"balanced";
    else cout<<"Unbalanced";
    return ;
}
int main()
{
    string s="{}([)]";
    check(s,6);
    return 0;
}
