#include <iostream>
using namespace std;
class node {
    public:
    int exptr;
    node* next=NULL;
};
class crl{
    public:
    node* start;
    node* end_;
    crl(){
        start=NULL;
        end_=NULL;
    }
    void insert_(int x,int y){
        node *temp=new node();
        temp->exptr=(x-y);
        if(start==NULL){
            start=temp;
            end_=start;
            return ;
        }
       node*cur=start;
        while(cur!=end_){
            cur=cur->next;
        }
        cur->next=temp;
        end_=cur->next;
        end_->next=start;
    }
    int check(int n);
    void print(){
        if(start==NULL){
            cout<<"No element to print"<<endl;
        }
        else{
            node *cur=start;
            while(cur!=end_){
                cout<<cur->exptr<<" ";
                cur=cur->next;
            }
            cout<<cur->exptr<<endl;
        }
    }
};
int crl::check(int n){
    node *cur=start;
    for(int i=0; i<n; i++){
        int s=cur->exptr;
        while(cur!=end_){
            if(s<0){
                break;
            }
            cur=cur->next;
            s=s+cur->exptr;
        }
        if(s>=0){
            return i;
        }
        cur=cur->next;
        end_=end_->next;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    n=2*n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    crl C;
    for(int i=0; i<n; i=i+2){
        C.insert_(arr[i],arr[i+1]);
    }
    C.print();
    cout<<C.check(n/2);
    return 0;
}
