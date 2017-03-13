#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#define EF 1000000000
#define Pi 3.14159265358
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long 
using namespace std;
string s;
long long n, m, k, i, j, l, r;
long long p=1, q, g, minn=1;
long long res[200005],o[100005],pp[100005];
pair < LL , LL > cur[100005];
int lcp(int i, int j)
{
    int cur=0;
    while(s[i]==s[j] && max(i,j)<s.size())
     {
      i++;
      j++;
      cur++;
     }
    return cur;
}
void pr(int i,int x)
{
     for(int j=i;j<x;j++)cout<<char(s[j]+'a');cout<<endl;    
}     
void suff ()
{
       k=s.size();
       p=1;
       while(p<k){
                  p*=2;
                  q++;
                  }
       for(i=0;i<k;i++){
                        cur[i].fi=s[i]-'0';
                        cur[i].se=-i; 
                        res[i]=cur[i].fi;
                        }
       sort(cur,cur+k); 
       for(j=1;j<=q;j++){
                         minn*=2;
                         for(i=0;i<k;i++)
                          {
                           res[i]=res[i]*(k+1)+res[i+minn/2];
                          }
                         for(i=0;i<k;i++)
                          {
                           cur[i].fi=res[i];
                           cur[i].se=-i;
                          }
                         sort(cur,cur+k);
                         g=0;
                         res[abs(cur[0].se)]=0; 
                         for(i=1;i<k;i++)
                          {
                           if(cur[i].fi!=cur[i-1].fi)
                            {
                             g++;
                            }
                           res[abs(cur[i].se)]=g;
                          }
                         }
}
int main(){
    
    
    cin>>n;
    
    for(i=0;i<n;i++)
    {
                    string x;
                    cin>>x;
                    for (j=0;j<x.size();j++) x[j]=x[j]-'a';
                    s=s+x+((char)(33+i+1));
    }
    suff();
    for(i=0;i<s.size();i++)cur[i].se*=-1;
    
    
    
    for(i=0;i<s.size();i++)
    {
       if(!i){o[i]=0;continue;}
       o[i]=lcp(cur[i].se,cur[i-1].se);
    }
    
    for(i=s.size()-1;i>=0;i--)
    {
             if (s[i] > 33 ) pp[i]=0; else pp[i]=pp[i+1]+1;                
                              
    }
    
    
    int mm;
    cin>>mm;
    while(mm--)
    {
         cin>>k;
         int fl=0;
         for (i=0;i<s.size();i++)
          {
           if (k <= pp[cur[i].se]-o[i])
            {
             pr(cur[i].se,cur[i].se+k+o[i]);fl=1;break;
            } else
            {
             k-=pp[cur[i].se]-o[i];
            }
          }
          if(!fl)cout<<"INVALID"<<endl;
                    
       }
}
