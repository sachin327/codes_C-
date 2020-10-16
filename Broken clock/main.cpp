#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int i=0; i<T; i++){
        double l,d;
        double t;
        int ans;
        int arr[3];
        for (int i=0; i<3; i++){
            cin >>arr[i];
        }
        l=arr[0];
        d=arr[1];
        t=arr[2];
        cout<<l<<d<<t<<endl;
        double th=acos(d/l);
        /*if(l<0){
            th=3.14-th;
        }*/
        double kk=th*t;
        if(0<=kk<1.57){
                cout<<l*cos(kk);

        }
        else if(1.57<=kk<3.14){
                cout<<-l*cos(3.14-kk);
        }
        else if(3.14<=kk<1.57*3){
                cout<<-l*cos(1.57*3-kk);
        }
        else if(1.57*3<=kk<3.14*2){
                cout<<l*cos(3.14*2-kk);
        }
        else if(3.14*2<=kk){
            double k=kk;
            while(k>3.14*2){
                k=k-(3.14*2);
            }
            if(0<=k<1.57){
                cout<<l*cos(k);
            }
            if(1.57<=k<3.14){
                    cout<<-l*cos(3.14-k);
            }
            if(3.14<=k<1.57*3){
                    cout<<-l*cos(1.57*3-k);
            }
            if(1.57*3<=k<3.14*2){
                    cout<<l*cos(3.14*2-k);
            }

        }
    }
    return 0;
}
