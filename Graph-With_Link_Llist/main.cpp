#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int a){
        data=a;
        next=NULL;
    }
};
class link_list{
    public:
    node *head=NULL;
    link_list(){
        head=NULL;
    }
    void _insert(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
            return ;
        }
        node *cur=head;
        while(cur->next!=NULL){
            if(cur->data==a){
                cout<<a<<" Already exist"<<endl;
                return ;
            }
            cur=cur->next;
        }
        if(cur->data==a){
            cout<<a<<" Already exist"<<endl;
        }
        else{ cur->next=temp;}
    }
    void print(){
        node *cur=head;
        while(cur!=NULL){
            cout<<cur->data<<" ,";
            cur=cur->next;
        }
    }
};
class graph{
    public:
    int n=0;
    vector <link_list> A;
    graph(){

        cout<<"Please create graph with no. of edges"<<endl;
    }
    graph(int v){
        A.resize(v+1);
        n=v+1;

    }

    void addedge(int a,int b){
        A[a]._insert(b);
    }
    void print_(){
        for(int i=0; i<n; i++){
            cout<<i<<" -> ";
            A[i].print();
            cout<<endl;
        }
    }

};

int main()
{
    graph G(6);

    for(int i=0; i<6; i++){
        G.addedge(i,i+1);
    }
    G.addedge(6,0);
    G.addedge(0,2);
    G.addedge(0,1);
    G.addedge(1,3);
    G.print_();
    return 0;
}
