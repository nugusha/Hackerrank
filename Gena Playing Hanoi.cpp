#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define mp make_pair
pair<pair<ll,ll>,pair<ll,ll> >he,ne;
#define pii pair<pair<ll,ll>,pair<ll,ll> >
#define fi first
#define se second
map<pair<pair<ll,ll>,pair<int,int> >,int>f,d;
ll b[100005];
ll e[100005];
int main(){
    int n;
    cin >> n;
    vector<ll> a(n,0);
    vector<ll> c(50,0);
    ll x=0;
    
    
    vector<ll>v[50];
    
    for(int i = 0;i < n;i++){
       cin >> a[i];
        x=x*11+n-i;
    }
    
    //cout<<x<<endl;
    
    for(int i = 0;i < n;i++)
        v[a[i]-1].push_back(i+1);
    
    
    
    for(int i=0;i<4;i++)
    {
        for(int j=v[i].size()-1;j>=0;j--)
                c[i]=c[i]*11+v[i][j];
    }
    
                    if(c[1]<c[2])swap(c[1],c[2]);
                    if(c[1]<c[3])swap(c[1],c[3]);
                    if(c[2]<c[3])swap(c[2],c[3]);
                   
                    
                    pii esmi=mp(mp(c[0],c[1]),mp(c[2],c[3]));
    
   //     cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
    
 //  cout<<x<<endl;
    
    
    queue<pair<pair<ll,ll>,pair<int,int> > >q;
    
    q.push(mp(mp(x,0),mp(0,0)));
    
    f[mp(mp(x,0),mp(0,0))]=1;
    while(!q.empty())
    {
        pii now=q.front();
        
        
        
        
        if(now==esmi)
        {
            cout<<f[now]-1<<endl;
            return 0;
        }
        
        q.pop();
        
        
        e[0]=now.fi.fi;
        e[1]=now.fi.se;
        e[2]=now.se.fi;
        e[3]=now.se.se;
        
        
        
    
        for(int i=0;i<4;i++)if(e[i]>0)
            for(int j=0;j<4;j++)if(i!=j)
            {           
                b[0]=now.fi.fi;
                b[1]=now.fi.se;
                b[2]=now.se.fi;
                b[3]=now.se.se;
            
            
                if(b[i]%11<b[j]%11 || b[j]==0)
                {
                    b[j]=b[j]*11+b[i]%11;
                    b[i]/=11;
                    
                    if(b[1]<b[2])swap(b[1],b[2]);
                    if(b[1]<b[3])swap(b[1],b[3]);
                    if(b[2]<b[3])swap(b[2],b[3]);
                    ne=mp(mp(b[0],b[1]),mp(b[2],b[3]));
                   
                    
                    if(!f[ne])
                    {
                        f[ne]=f[now]+1;
                        q.push(ne);
        if(ne==esmi)
        {
            cout<<f[ne]-1<<endl;
            return 0;
        }
                    }
                }
            }
    }
    
    
   // cout<<go();
    
    
    
    
    return 0;
}
