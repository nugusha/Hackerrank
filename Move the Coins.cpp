#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;
int n,a[100005];
vector<int>v[100005];
int in[100005];
int out[100005];
int xo[100005][2];
int tim=0;
int lvl[100005];
void dfs(int x,int p=-1)
{
    in[x]=++tim;
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        
        if(p==to)continue;
        lvl[to]=lvl[x]+1;
        dfs(to,x);
        xo[x][0]^=xo[to][1];
        xo[x][1]^=xo[to][0];
    }
    
    out[x]=++tim;
    
    xo[x][0]^=a[x];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    
    for(int i=1;i<n;i++)
    {
            int x,y;
            cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
   // lvl[1]++;
    dfs(1);
    
  //  cout<<lvl[1]<<endl;
    
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
            cin>>x>>y;
        
    //    cout<<x<<" "<<y<<" "<<in[x]<<" "<<in[y]<<" "<<out[y]<<" "<<out[x]<<endl;
        
            if(in[x]<in[y] && out[y]<out[x])
            {
                cout<<"INVALID"<<endl;
                continue;
            }
        
           //     assert(0);
            int su=xo[1][1];
        
        
            if(lvl[x]%2==0)su^=xo[x][1];else su^=xo[x][0];
        
        
        
            if(lvl[y]%2)su^=xo[x][1];else su^=xo[x][0];
        
      //  cout<<su<<endl;
        
        
        if(su==0)cout<<"NO"<<endl;else cout<<"YES"<<endl;
        
            
    
    
    }
    
    
    return 0;
}
