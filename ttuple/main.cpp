#include <iostream>
using namespace std;
bool check7(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c){
    if(r!=0 && p!=0){
        long long int k1=(a/p);
        long long int k2=(c/r);
        if(c%r==0 && a%p==0 && (q*k1*k2)==b){
            return true;
        }
    }
    return false;
}
bool check6(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c){
    if(p!=0){
        long long int k1=(c-r);
        long long int k2=(a/p);
        if(a%p==0 && ((q*k2)+k1)==b){
            return true;
        }
    }
    return false;
}
bool check5(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c){
    if(r!=0){
        long long int k1=(a-p);
        long long int k2=(c/r);
        if(c%r==0 && (q+k1)*k2==b){
            return true;
        }
    }
    return false;
}
bool check4(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c){
    long long int k1=(a-p);
    long long int k2=(c-r);
    if((q+k1+k2)==b){
        return true;
    }
    return false;
}
bool check3(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c){
    if(p!=q){
        long long int k1=(a-b);
        long long int k2=(p*b)-(q*a);
        long long int k3=(p-q);
        if(k1%k3==0 && k2%k3==0 && ((r*(k1/k3))+(k2/k3)==c)){
            return true;
        }
    }
    return false;
}

bool check2(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c){
    if(q!=r){
        long long int k1=(b*r)-(q*c);
        long long int k2=r-q;
        long long int r1=c-b;
        if(k1%k2==0 && r1%k2==0){
            if((p+(k1/k2))==a){
                return true;
            }
            if((p*(r1/k2))==a){
                return true;
            }
        }
    }
    return false;
}
bool check1(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c){
    if(q!=r && b!=c){
        long long int k1=(b*r)-(q*c);
        long long int k2=r-q;
        long long int r1=c-b;
        if(k1%r1==0 && r1%k2==0){
            if((p+(k1/r1))==a){
                return true;
            }
            if((p*(r1/k2))==a){
                return true;
            }
        }
    }
    return false;
}

bool case_zero(long long int *arr1,long long int *arr2){
    for(long long int i=0; i<3; i++){
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}
bool case_one(long long int *arr1,long long int *arr2){
    long long int arr3[3]={0};
    long long int s=0;
    for(long long int i=0; i<3; i++){
        arr3[i]=arr2[i]-arr1[i];
    }
    for(long long int i=0; i<3; i++){
        if(arr3[i]!=0){
            for(long long int j=i; j<3; j++){
                if(arr3[j]!=0){
                    if(arr3[i]!=arr3[j]){
                        s=1;
                    }
                }
            }
        }
    }

    if(s==0){
        return true;
    }
    for(long long int i=0; i<3; i++) {
        arr3[i]=0;
    }
    for(long long int i=0; i<3; i++){
        if(arr1[i]==0){
            if(arr2[i]!=0){
                return false;
            }
            arr3[i]=1;
        }
        else if(arr2[i]%arr1[i]==0){
            arr3[i]=arr2[i]/arr1[i];
        }
        else{return false;}
    }
    s=0;
    for(long long int i=0; i<3; i++){
        if(arr3[i]!=1){
            for(long long int j=i; j<3; j++){
                if(arr3[j]!=1){
                    if(arr3[i]!=arr3[j]){
                        s=1;
                    }
                }
            }
        }
    }
    if(s==0){
        return true;
    }
    return false;
}
bool case_two(long long int *arr1,long long int *arr2){
    long long int arr3[3]={0};
    long long int s=0;
    for(long long int i=0; i<3; i++){
        if(arr1[i]==arr2[i]){
            s=1;
        }
        arr3[i]=arr2[i]-arr1[i];
    }
    if(s==1){
        return true;
    }

    long long int k=arr3[0];
    for(long long int i=0; i<3; i++){
        if(arr3[i]==k){
            arr3[i]=arr1[i];
        }
        else {arr3[i]=arr2[i];}
    }

    if(case_one(arr1,arr3)){
        return true;
    }

    s=0;
    for(long long int i=0; i<3; i++){
        if(arr1[i]==0 || arr2[i]%arr1[i]!=0){
            s++;
            arr3[i]=arr1[i];
        }
        else {arr3[i]=arr2[i];}
    }

    if(s==1){
        if(case_one(arr1,arr3)){
            return true;
        }
    }

    if(s==0){
        arr3[0]=arr2[0]/arr1[0];
        arr3[1]=arr2[1]/arr1[1];
        arr3[2]=arr2[2]/arr1[2];
        long long int kk=arr3[0];
        for(long long int i=0; i<3; i++){
            if(arr3[i]==kk){
                arr3[i]=arr1[i];
            }
            else {arr3[i]=arr2[i];}
        }
        if(case_one(arr1,arr3)){
            return true;
        }
    }


    if(check3(arr1[0],arr1[1],arr1[2],arr2[0],arr2[1],arr2[2])){
        return true;
    }

    if(check3(arr1[0],arr1[2],arr1[1],arr2[0],arr2[2],arr2[1])){
        return true;
    }
    if(check3(arr1[1],arr1[0],arr1[2],arr2[1],arr2[0],arr2[2])){
        return true;
    }
    if(check3(arr1[1],arr1[2],arr1[0],arr2[1],arr2[2],arr2[0])){
        return true;
    }
    if(check3(arr1[2],arr1[1],arr1[0],arr2[2],arr2[1],arr2[0])){
        return true;
    }
    if(check3(arr1[2],arr1[0],arr1[1],arr2[2],arr2[0],arr2[1])){
        return true;
    }
    //
    if(check2(arr1[0],arr1[1],arr1[2],arr2[0],arr2[1],arr2[2])){
        return true;
    }

    if(check2(arr1[0],arr1[2],arr1[1],arr2[0],arr2[2],arr2[1])){
        return true;
    }
    if(check2(arr1[1],arr1[0],arr1[2],arr2[1],arr2[0],arr2[2])){
        return true;
    }
    if(check2(arr1[1],arr1[2],arr1[0],arr2[1],arr2[2],arr2[0])){
        return true;
    }
    if(check2(arr1[2],arr1[1],arr1[0],arr2[2],arr2[1],arr2[0])){
        return true;
    }
    if(check2(arr1[2],arr1[0],arr1[1],arr2[2],arr2[0],arr2[1])){
        return true;
    }
    //
    if(check1(arr1[0],arr1[1],arr1[2],arr2[0],arr2[1],arr2[2])){
        return true;
    }

    if(check1(arr1[0],arr1[2],arr1[1],arr2[0],arr2[2],arr2[1])){
        return true;
    }
    if(check1(arr1[1],arr1[0],arr1[2],arr2[1],arr2[0],arr2[2])){
        return true;
    }
    if(check1(arr1[1],arr1[2],arr1[0],arr2[1],arr2[2],arr2[0])){
        return true;
    }
    if(check1(arr1[2],arr1[1],arr1[0],arr2[2],arr2[1],arr2[0])){
        return true;
    }
    if(check1(arr1[2],arr1[0],arr1[1],arr2[2],arr2[0],arr2[1])){
        return true;
    }
    //
    if(check4(arr1[0],arr1[1],arr1[2],arr2[0],arr2[1],arr2[2])){
        return true;
    }

    if(check4(arr1[0],arr1[2],arr1[1],arr2[0],arr2[2],arr2[1])){
        return true;
    }
    if(check4(arr1[1],arr1[0],arr1[2],arr2[1],arr2[0],arr2[2])){
        return true;
    }
    if(check4(arr1[1],arr1[2],arr1[0],arr2[1],arr2[2],arr2[0])){
        return true;
    }
    if(check4(arr1[2],arr1[1],arr1[0],arr2[2],arr2[1],arr2[0])){
        return true;
    }
    if(check4(arr1[2],arr1[0],arr1[1],arr2[2],arr2[0],arr2[1])){
        return true;
    }
    //
    if(check5(arr1[0],arr1[1],arr1[2],arr2[0],arr2[1],arr2[2])){
        return true;
    }

    if(check5(arr1[0],arr1[2],arr1[1],arr2[0],arr2[2],arr2[1])){
        return true;
    }
    if(check5(arr1[1],arr1[0],arr1[2],arr2[1],arr2[0],arr2[2])){
        return true;
    }
    if(check5(arr1[1],arr1[2],arr1[0],arr2[1],arr2[2],arr2[0])){
        return true;
    }
    if(check5(arr1[2],arr1[1],arr1[0],arr2[2],arr2[1],arr2[0])){
        return true;
    }
    if(check5(arr1[2],arr1[0],arr1[1],arr2[2],arr2[0],arr2[1])){
        return true;
    }
    //
    if(check6(arr1[0],arr1[1],arr1[2],arr2[0],arr2[1],arr2[2])){
        return true;
    }

    if(check6(arr1[0],arr1[2],arr1[1],arr2[0],arr2[2],arr2[1])){
        return true;
    }
    if(check6(arr1[1],arr1[0],arr1[2],arr2[1],arr2[0],arr2[2])){
        return true;
    }
    if(check6(arr1[1],arr1[2],arr1[0],arr2[1],arr2[2],arr2[0])){
        return true;
    }
    if(check6(arr1[2],arr1[1],arr1[0],arr2[2],arr2[1],arr2[0])){
        return true;
    }
    if(check6(arr1[2],arr1[0],arr1[1],arr2[2],arr2[0],arr2[1])){
        return true;
    }
    //
    if(check7(arr1[0],arr1[1],arr1[2],arr2[0],arr2[1],arr2[2])){
        return true;
    }

    if(check7(arr1[0],arr1[2],arr1[1],arr2[0],arr2[2],arr2[1])){
        return true;
    }
    if(check7(arr1[1],arr1[0],arr1[2],arr2[1],arr2[0],arr2[2])){
        return true;
    }
    if(check7(arr1[1],arr1[2],arr1[0],arr2[1],arr2[2],arr2[0])){
        return true;
    }
    if(check7(arr1[2],arr1[1],arr1[0],arr2[2],arr2[1],arr2[0])){
        return true;
    }
    if(check7(arr1[2],arr1[0],arr1[1],arr2[2],arr2[0],arr2[1])){
        return true;
    }
    return false;
}
int main()
{
    long long int t;
    cin>>t;
    for(long long int i=0; i<t; i++){
        long long int arr1[3]={0};
        long long int arr2[3]={0};
        for(long long int j=0; j<3; j++){
            cin>>arr1[j];
        }
        for(long long int j=0; j<3; j++){
            cin>>arr2[j];
        }

        if(case_zero(arr1,arr2)){
            cout<<0<<endl;
        }
        else if(case_one(arr1,arr2)){
            cout<<1<<endl;
        }
        else if(case_two(arr1,arr2)){
            cout<<2<<endl;
        }
        else{cout<<3<<endl;}

    }
    return 0;
}
