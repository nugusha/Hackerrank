#include <bits/stdc++.h>

using namespace std;

int main(){
    int g;
    cin >> g;
    while(g--){
        int n;
        int m;
        long long x;
        cin >> n >> m >> x;
        vector<long long> a(n+1);
        for(int i = 1; i <= n; i++){
           cin >> a[i];
            a[i]+=a[i-1];
        }
        vector<long long> b(m+1);
        for(int i = 1; i <= m; i++){
           cin >> b[i];
            b[i]+=b[i-1];
        }
        
        int ans=0;
        for(int i = 0; i <= n; i++){
            if(a[i]>x)break;
            
            int l=0,r=m,ls=-1;
            
            while(l<=r){
                int m=(l+r)/2;
                if(a[i]+b[m]<=x){
                    ls=m;
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            
            ans=max(ans,i+ls);
            
        }
        cout<<ans<<endl;
        
        
    }
    return 0;
}
