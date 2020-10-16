#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    queue <int> q2;
    void push_(int x){
        queue <int> q1;
        q1.push(x);
        if(!q2.empty()){
           while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
           }
        }
        q2=q1;
    }
    void pop_(){
        if(!q2.empty()){
            q2.pop();
            return ;
        }
    }
    void print(){
        queue<int> cur;
        cur=q2;
        while(!cur.empty()){
            cout<<cur.front()<<endl;
            cur.pop();
        }
    }
};
int main()
{
    Stack S;
    for(int i=0; i<10; i++){
        S.push_(i);
    }
    S.print();
    S.pop_();
    S.print();
    S.push_(9);
    S.print();
    return 0;
}
