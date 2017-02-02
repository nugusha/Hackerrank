#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int INF=int(1e9);
#define fi first
#define se second
vector<pair<int,int> >v[int(1e5)+5];
int x,y,z,n,k;
int d[100005][3],a[100005];
vector<int>g;
void go(int x,int p=-1)
{
 
    for(int i=0;i<v[x].size();i++)if(p!=v[x][i].fi)
        go(v[x][i].fi,x);
    
    
   // cout<<x<<" <-----------"<<endl;
    
    if(a[x])
    {
        
    int sum=0;
        for(int i=0;i<v[x].size();i++)
        {
            if(p==v[x][i].fi)continue;
            int to=v[x][i].fi;
            int len=v[x][i].se;
            sum+=min(d[to][0],d[to][1]+len);
        }
        d[x][1]=sum;
        d[x][0]=INF;
        return;
    }
    else
    {
        g.clear();
        d[x][1]=INF;
        d[x][0]=INF;
    int sum=0;
        int sum1=0,smm=0,w=0;
        for(int i=0;i<v[x].size();i++)
        {
            if(p==v[x][i].fi)continue;
            int to=v[x][i].fi;
            int len=v[x][i].se;
            sum+=min(d[to][0],d[to][1]+len);
            
            g.push_back(min(d[to][0],d[to][1]+len)-min(d[to][0],d[to][1]));
        }
        if(g.size())sort(g.begin(),g.end());
        int pp=0;
          if(g.size())      d[x][1]=sum-g.back();else d[x][1]=INF;
        d[x][0]=sum;
        d[x][1]=min(d[x][1],d[x][0]);
        return;
    }
    
    
}
int main() {
    
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y>>z;x++;y++;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=k;i++)cin>>x,a[++x]=1;
    
    go(1);
 //   for(int i=1;i<=n;i++)
 //       cout<<i<<"~"<<d[i][0]<<" "<<d[i][1]<<endl;
    cout<<min(d[1][0],d[1][1])<<endl;
    
    return 0;
}
