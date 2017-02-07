#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000005];
int main() {
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++)cin>>a[i];
    
    int shu=0;
    
    int le=0;
    int re=0;
    
    
    int ans=0;
    
    while(re<n && shu<n)
    {
        while(le<n && a[shu]-a[le]>d)le++;
        while(re<n && a[re]-a[shu]<d)re++;
        
        
        if(re<n && le<n && shu<n && a[shu]-a[le]==d && a[re]-a[shu]==d)
        {
            ans++;
        }
        
        
        
        shu++;
    }
    
    
    cout<<ans;
    
    
    
    return 0;
}
