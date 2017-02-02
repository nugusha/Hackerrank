#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define tree int h,int l1,int r1
#define left h*2,l1,(l1+r1)/2
#define right h*2+1,(l1+r1)/2+1,r1
ll ans,F,n,C;    
    ll i=0,sm=-1;
    ll st=-1;
ll a[400005],b[400005],c[400005],sum[1000005],mi[1000005];
void go(int x)
{
    c[x]=0;
    for(int i=(x-1+n)%n;i!=x;i=(i-1+n)%n)
    {
        c[i]=c[(i+1)%n]+b[i]-a[i];
        c[i]=max(c[i],0LL);
    }
    for(int i=0;i<n;i++)
            if(c[i]==0)ans++;
        
      cout<<ans<<endl;
}
int main() {
    
    
    cin>>n>>C;
    for(int i=0;i<n;i++)cin>>a[i],a[i]=min(a[i],C);
    for(int i=0;i<n;i++)cin>>b[i];
 int cnt=0;
    for(int i=0;;i=((i+1)%n))
    {        cnt++; if (cnt > 3*n) goto fin;
        if(sm<0) { F=1,st=i,sm=0;} else
        if(st==i)
        {
                go(i);
                return 0;
        }
        
        sm=min(C,(sm+a[i]))-b[i];
    }
    

    
    fin:
  cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    return 0;
}
