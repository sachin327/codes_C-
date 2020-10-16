#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
int merge_(int *arr,int s,int m,int e){
    int ss=0;
	int ls=arr[m];
	for (int i=m; i>= s; i--){
		ss = ss + arr[i];
		if (ss > ls){
            ls = ss;
        }
	}
	int rs=arr[m+1];
	ss=0;
	for (int i=m+1; i<=e; i++){
		ss = ss + arr[i];
		if (ss > rs){
            rs = ss;
        }
	}
	return(ls+rs);

}
int break_(int *arr,int s,int e){
    if(s==e){
        return arr[s];
    }
    int m=(s+e)/2;
    return(max(break_(arr,s,m),break_(arr,m+1,e),merge_(arr,s,m,e)));

}
int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
	}
	printf("%d\n",break_(arr,0,n-1));

	return 0;
}


