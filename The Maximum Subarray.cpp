#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005],b[100005],c[100005],ma,n,t,ans,an;
int main() {
    cin>>t;
    while(t--)
    {
        ma=0;ans=0;an=-999999999;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>c[i];
        for(int i=1;i<=n;i++)if(c[i]>0)ans+=c[i];
            if(ans==0)
        for(int i=1;i<=n;i++)if(c[i]<=0)an=max(an,c[i]);
            
        for(int i=1;i<=n;i++)a[i]=a[i-1]+c[i];
        for(int i=2;i<=n;i++)b[i]=min(b[i-1],a[i]);
        for(int i=1;i<=n;i++)ma=max(ma,a[i]-b[i]);
        
            
            if(ans>0)
        cout<<ma<<" "<<ans<<endl;else
         cout<<an<<" "<<an<<endl;
    }
    return 0;
}
