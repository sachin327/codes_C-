#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int x;
    int y;
    node* next;
    node(){
        x=0;
        y=0;
        next=NULL;
    }
};
class LRU{
    public:
    node *head;
    LRU(){
        head=NULL;
    }
    void append(int i,int a);
    void get(int a);
    void set_(int i,int a,int c);
};
void LRU::append(int i,int a){
    node *temp=new node();
    temp->x=i;
    temp->y=a;
    if (head==NULL){
        head=temp;
        return ;
    }
    node *cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=temp;
}
void LRU::set_(int i,int a,int c){
    if(c==0){
        cout<<"Cache space is 0"<<endl;
    }
    node *temp=new node();
    temp->x=i;
    temp->y=a;
    if (head==NULL){
        head=temp;
        return ;
    }
    else if(head->x==i){
        head=head->next;
        append(i,a);
        return ;
    }
    int s=1;
    node *cur=head;
    while(cur->next!=NULL && s!=c){
        if(cur->next!=NULL && cur->next->x==i){
            cur->next=cur->next->next;
            append(i,a);
            return ;
        }
        cur=cur->next;
        s++;
    }
    if(s!=c){
        cur->next=temp;
    }
    else if(s==c){
        node *cur=head;
        if(cur->next==NULL){
            head=temp;
            return ;
        }
        while(cur->next->next!=NULL){
            cur=cur->next;
        }
        cur->next=temp;
        return ;
    }

}
void LRU::get(int a){
    node *cur=head;
    while(cur!=NULL && cur->x!=a){
        cur=cur->next;
    }
    if(cur==NULL){
        cout<<-1<<endl;
        return ;
    }
    cout<<"Value "<<cur->y<<" is present and it's index is "<<cur->x<<endl;
}

int main()
{
    LRU l;
    int c;
    cout<<"Enter capicity ";
    cin>>c;
    for(int i=0; i<20; i++){
        int a;
        cout<<"For set press 1 "<<endl;
        cout<<"For Get press 2 "<<endl;
        cin>>a;
        if(a==1){
            int a1,a2;
            cout<<"Set:a,b  ";
            cin>>a1>>a2;
            l.set_(a1,a2,c);

        }
        else if(a==2){
            int a3;
            cout<<"Get:a  ";
            cin>>a3;
            l.get(a3);
        }
        else {cout<<"Type correct keyword"<<endl;}
    }

    return 0;
}
