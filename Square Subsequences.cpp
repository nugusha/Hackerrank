#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;
long long d[1005][1005],i,m,n,ans,k,l,j,q,x,ma,mi,t,M=int(1e9)+7;

char c[1055],s[1055],s1[1055],s2[1055];


int go()
{

    int ans=0;
    n=strlen(s1);
    m=strlen(s2);

    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)d[i][j]=0;

    d[0][0]=1;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    {
        if (i)d[i][j]+=d[i-1][j];
        if (j)d[i][j]+=d[i][j-1];

        if (i && j && s1[i-1]!=s2[j-1])d[i][j]-=d[i-1][j-1]-M;

        d[i][j]%=M;
    }

    for(int j=0;j<m;j++)
        if (s1[n-1]==s2[j])ans+=d[n-1][j],ans%=M;

    return ans;
}
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&s);
        memset(s1, 0, sizeof s1);
        memset(s2, 0, sizeof s2);
        int n=strlen(s);
       int ans=0;

        for(int i=0; i+1<n; i++)
        {
           strncpy(s1,s,i+1);
           strcpy(s2,s+i+1);
           ans+=go();ans%=M;
        }
       printf("%d\n",ans);
    }
}
