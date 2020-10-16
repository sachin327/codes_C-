#include <iostream>
using namespace std;
class node{
    public:
    int data ;
    node* next=NULL;

};
class link{
    public:
    node* head;
    link(){
        head=NULL;
    }
    link(int x){
        head=new node();
        head->data=x;
    }
    void insertt(int t){
        insert_(head,t);
    }
    void insert_(node* head,int xx){
        if (head==NULL){
            head->data=xx;
        }
        else{
            node *cur=new node();
            cur=head;
            while(cur->next!=NULL){
                cur=cur->next;
            }
            node* temp=new node();
            temp->data=xx;
            cur->next=temp;
        }
    }
    void print();
    void print_();
};
void link ::print (){
    node*cur=new node();
    cur=head;
    while(cur!=NULL){
            cout<<cur->data<<endl;
                cur=cur->next;
            }
}
void link :: print_(){
    print();
}
int main(){
    link l1(5);
    l1.insertt(12);
    l1.insertt(17);
    l1.print();
    return 0;
}
