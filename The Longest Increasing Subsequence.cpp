#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N int(1e6)
int a[N+5],b[N+5],siz,l,r,mid,ls,ma,n;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)b[i]=int(1e9);
    
    
    for(int i=1;i<=n;i++)
    {
        l=0;
        r=n;
        ls=-1;
        while(l<=r)
        {
            mid=l+r;mid/=2;
            if(b[mid]>=a[i])ls=mid,r=mid-1;else l=mid+1;
        }
        b[ls]=a[i];
        ma=max(ma,ls);
    }
    
    
    
    
    
    
    
    cout<<ma<<endl;
    return 0;
}
