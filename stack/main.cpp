#include <iostream>
using namespace std;
class node{
    public:
    int data ;
    node* bottm=NULL;

};
class stak{
    public:
    node* top;
    stak(){
        top=NULL;
    }
    stak(int x){
        top->data=x;
    }
    void push(int xx){
        node* temp=new node();
        temp->data=xx;
        if (top==NULL){
            top=temp;
            temp=NULL;
        }
        else{
            temp->bottm=top;
            top=temp;
            temp=NULL;
        }
    }
    void pop(){

        if (top==NULL){
                return ;
        }
        else{
            top=top->bottm;
        }
    }
    void print();
};
void stak ::print (){
    node*cur=new node();
    cur=top;
    while(cur!=NULL){
            cout<<cur->data<<endl;
                cur=cur->bottm;
            }
}
int main(){
    stak l1;
    l1.push(12);
    for (int i=0; i<50; i++){
        l1.push(i);
    }
    l1.print();
    l1.pop();
    l1.print();
    return 0;
}
