#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int first;
    int mid;
};
vector<node> append(vector<node>V,node* temp,int n) {
		if (n > 0 && V[n - 1].mid == temp->mid)
			return V;
		if (n > 0 && V[n - 1].first == temp->first) {
			V[n - 1].mid = max(V[n - 1].mid, temp->mid);
			return V;
		}
		V.push_back(*temp);
		return V;
}
vector<node> _merge(vector<node> V1,vector<node> V2,int s,int e){
	int h1 = 0, h2 = 0;
	vector<node> res;
	int i = 0, j = 0;
	while (i < s && j < e) {
		if (V1[i].first < V2[j].first) {
			int x1 = V1[i].first;
			h1 = V1[i].mid;
			int maxh = max(h1, h2);
			node* temp=new node;
			temp->first=x1;
			temp->mid=maxh;
			res=append(res,temp,res.size());
			temp=NULL;
			i++;
		}
		else {
			int x2 = V2[j].first;
			h2 = V2[j].mid;
			int maxh = max(h1, h2);
			node* temp=new node;
			temp->first=x2;
			temp->mid=maxh;
			res=append(res,temp,res.size());
			temp=NULL;
			j++;
		}
	}
	while (i < s) {
        node * temp=new node;
        temp->first=V1[i].first;
        temp->mid=V1[i].mid;
        res=append(res,temp,res.size());
        temp=NULL;
        i++;
    }
    while (j < e) {
        node * temp=new node;
        temp->first=V2[j].first;
        temp->mid=V2[j].mid;
        res=append(res,temp,res.size());
        temp=NULL;
        j++;
    }
    return res;


}

vector<node> break_(int *arr,int s,int e){
    if(s==e){
        vector<node> res;
        node* temp=new node;
        temp->first=(arr+3*s)[0];
        temp->mid=(arr+3*s)[1];
        res.push_back(*temp);
        temp->first=(arr+3*s)[2];
        temp->mid=0;
        res.push_back(*temp);
        temp=NULL;
        return res;
    }
    int m=(s+e)/2;
    vector<node> b1=break_(arr,s,m);
    vector<node> b2=break_(arr,m+1,e);
    vector<node> res=_merge(b1,b2,b1.size(),b2.size());

    return res;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n][3];
	int i=0;
	while(i<n){
        int arr1[3];
        scanf("%d %d %d",&arr1[0],&arr1[1],&arr1[2]);
        arr[i][0]=arr1[0];
        arr[i][1]=arr1[1];
        arr[i][2]=arr1[2];
        i++;
	}

    vector<node> ans=break_(*arr,0,n-1);
    n=ans.size();
    for (i=0; i<n; i++){
        if(i==n-1){
            printf("%d %d ",ans[i].first,0);
            break;
        }
        printf("%d %d ",ans[i].first,ans[i].mid);
    }
    printf("\n");
	return 0;
}
