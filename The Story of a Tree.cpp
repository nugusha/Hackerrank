#include <bits/stdc++.h>
using namespace std;
vector<int>v[1000005];
int in[1000005];
int out[1000005];
int par[1000005];
int she[1000005];
int mi[1000005];
int cnt = 0, ans = 0 , k = 0;

void dfs(int x,int p=-1){
    par[x]=p;
    in[x]=(++cnt);
    for(int i=0;i<v[x].size();i++){
        int to=v[x][i];
        if(to!=p)dfs(to,x);
    }
    out[x]=cnt;
}
#define tree int h,int l1,int r1
#define left h*2,l1,(l1+r1)/2
#define right h*2+1,(l1+r1)/2+1,r1
void cl(tree){
    mi[h]=she[h]=0;
    if(l1==r1)return;
    cl(left);cl(right);
}
void push(int h){
    if(!she[h])return;
    mi[h]+=she[h];
    she[h*2]+=she[h];
    she[h*2+1]+=she[h];
    she[h]=0;
}
void update(int h){
    mi[h]=min(mi[h*2],mi[h*2+1]);
}
void upd(tree,int l,int r){
    push(h);
    
    if(l>r1 || l1>r || l>r)return;
    
    if(l<=l1 && r1<=r){
        she[h]++;
        return;
    }
    upd(left,l,r);
    upd(right,l,r);
    update(h);
}
void pr(tree){
    push(h);
    if(l1==r1){if(mi[h]>=k)ans++;return;}
    pr(left);
    pr(right);
    update(h);
}
void print(int a,int n){
    cout<<a/__gcd(a,n)<<"/"<<n/__gcd(a,n)<<endl;
}
int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        for(int a1 = 0; a1 < n-1; a1++){
            int x;
            int y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cnt=0;
        dfs(1);
        cl(1,1,n);
        
        int g;
        cin >> g >> k;
        for(int a1 = 0; a1 < g; a1++){
            int x;
            int y;
            cin >> x >> y;
            
            if(par[x]==y){
                upd(1,1,n,in[x],out[x]);//cout<<in[x]<<"~"<<out[x]<<endl;
            }else
            if(par[y]==x)
            {
                upd(1,1,n,1,in[y]-1);//cout<<1<<"~~"<<in[y]-1<<endl;
                upd(1,1,n,out[y]+1,n);//out<<out[y]+1<<"~~~"<<n<<endl;
            }
        }
        ans=0;
        pr(1,1,n);
        print(ans,n);
        for(int i = 1; i <= n; i++)v[i].clear();
    }
    return 0;
}
