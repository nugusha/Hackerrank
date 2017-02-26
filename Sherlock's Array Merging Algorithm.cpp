#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define M int(1e9+7)
ll bp(ll a,ll n){
    ll ret=1;
    while(n){
        if(n%2)ret*=a;ret%=M;
        a*=a;a%=M;
        n/=2;
    }
    return ret;
}
#define N 10005
int n;
ll f[N],f1[N],a[N];
ll d[2002][2002];
int main(){
    f[0]=1;
    for(int i = 1; i < N; i++)
        f[i]=(f[i-1]*i)%M;
    for(int i = 0; i < N; i++)
        f1[i]=bp(f[i],M-2);
    
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    n++;
    
    
    
    
    d[0][n]=1;
    for(int i=n;i>=1;i--)
        for(int j=i-1;j>=1;j--){
            if(a[j]>a[j+1] && j<i-1)break;
        
            for(int q=0;q<=i-j;q++){
                d[i-j][j]+=(((d[q][i]*f[i-j])%M)*f1[i-j-q])%M;
                d[i-j][j]%=M;
            }
        }
    
    ll ans=0;
    for(int i = 0; i < n; i++)
        ans+=d[i][1],ans%=M;
    
    cout<<ans<<endl;
    return 0;
}
