#include <iostream>
using namespace std;
//itne intigers kaahe use krte ho
int find(int a[],int n)
{ int pa=0;
  int d=0;
  int p=0;
  int t=0;
  while(t!=n)
  {if (a[t]==5)
   {pa++;
    t++;
   }
  if (a[t]==10)
  {if(pa>0)
  {d++;
   pa--;
   t++;}
   else
   {cout<<"NO"<<endl;
    return 0;}
  }
  if(a[t]==15)
  {if(d>0)
   {d--;
    p++;
    t++;
   }
   else if (pa>=2)
    {pa=pa-2;
     p++;
     t++;
    }
    else
    {cout<<"NO"<<endl;
    return 0;}
  }

 }
cout<<"YES"<<endl;
return 0;
}

int main()
{int t;
 cin>>t;
 int o=0;
 while(o!=t)
 {int k;
  cin>>k;
  int a[k];
  for (int i=0;i<k;i++)
  {cin>>a[i];
  }
  find(a,k);
  o++;
 }
 return 0;
}




