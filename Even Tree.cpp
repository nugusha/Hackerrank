#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ans,n,m,x,y,f[1000005];
vector<int>v[100005];
int go(int x)
{
    f[x]=1;
    int sum=0;
    for(int i=0;i<v[x].size();i++)
            if(!f[v[x][i]])sum+=go(v[x][i]);
    sum++;
    if(sum%2==0)ans++;
    return sum%2;
}
int main() {
    
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(!f[i])go(i);
    cout<<ans-1<<endl;
}
