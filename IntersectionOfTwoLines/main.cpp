#include <bits/stdc++.h>
using namespace std;
class point{
    public:
    int x;
    int y;
    point (){
        x=0;
        y=0;
    }
    point(int a,int b=0){
        x=a;
        y=b;
    }
};
bool segmnt(point p1,point p2,point p3){
    if(p2.x<max(p1.x,p3.x) && p2.x>min(p1.x,p3.x) && p2.y<max(p1.y,p3.y) && p2.y>min(p1.y,p3.y)){
        return true;
    }
    return false;
}
int oreint(point p1,point p2,point p3){
    int res=(p2.y-p1.y)*(p3.x-p1.x)-(p3.y-p1.y)*(p2.x-p1.x);
    if(res==0){
        return 0;
    }
    return (res>0)? 2: 1;
}
bool check(point p1,point q1,point p2,point q2){
    int o1=oreint(p1,q1,p2);
    int o2=oreint(p1,q1,q2);
    int o3=oreint(p2,q2,p1);
    int o4=oreint(p2,q2,q1);

    if(o1!=o2 && o3!=o4){
        return true;
    }
    if(o1==0 && segmnt(p1,p2,q1)) return true;
    if(o1==0 && segmnt(p1,q2,q1)) return true;
    if(o1==0 && segmnt(p2,p1,q2)) return true;
    if(o1==0 && segmnt(p2,q1,q2)) return true;
    return false;
}

int main()
{
    point p1(1,1);
    point q1(10,1);
    point p2(1,0);
    point q2(1,2);
    cout<<check(p1,q1,p2,q2);

    return 0;
}
