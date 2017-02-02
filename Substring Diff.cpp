#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;
int d[1505][1505],i,m,t,ans,k,l,j,q,x,n,ma,mi;
string s1,s2;
int check(int L)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)d[i][j]=0;

    for(int i=0;i<L;i++)if(s1[i]!=s2[i])d[0][0]++;
    for(int i=1;i<n-L+1;i++)
    {
        for(int j=i;j<i+L;j++)if(s1[j]!=s2[j-i])d[i][0]++;
        for(int j=i;j<i+L;j++)if(s1[j-i]!=s2[j])d[0][i]++;
    }
    for(int i=1;i<n-L+1;i++)
      for(int j=1;j<n-L+1;j++)
        d[i][j]=d[i-1][j-1]-(s1[i-1]!=s2[j-1])+(s1[i+L-1]!=s2[j+L-1]);


          for(int i=0;i<n-L+1;i++)
        for(int j=0;j<n-L+1;j++)if(d[i][j]<=k)return 1;

        return 0;

}
main()
{
    cin>>t;

    while(t--)
    {
        cin>>k;cin>>s1>>s2;
    n=s1.size();
        int l=1,r=min(s1.size(),s2.size());
        n=r;
        while(l<r)
        {
            int m=l+r+1;m/=2;
            int w=check(m);
            if(w)l=m;else r=m-1;
        }
        cout<<l<<endl;
    }
}
