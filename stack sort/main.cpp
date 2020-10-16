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
            if(xx<=top->data){
            temp->bottm=top;
            top=temp;
            temp=NULL;
            }
            else{
                int x;
                pop_(&x);
                push(xx);
                push(x);
            }
        }
    }
    void pop();
    void pop_(int* x){

        if (top==NULL){
                return ;
        }
        else{
            *x=top->data;
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
void stak::pop(){
     if (top==NULL){
                return ;
        }
        else{
            top=top->bottm;
        }
    }

int main(){
    int arr[100]={8,5,7,1,2,5,6,4,2,5};
    stak l1;
    for (int i=0; i<100; i++){
        l1.push(i);
    }
    l1.print();
    return 0;
}
