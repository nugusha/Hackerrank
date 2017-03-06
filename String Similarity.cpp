// __   _   _   _   _____   _   _   _____   _   _       ___
//|  \ | | | | | | /  ___| | | | | /  ___/ | | | |     /   |
//|   \| | | | | | | |     | | | | | |___  | |_| |    / /| |
//| |\   | | | | | | |  _  | | | | \___  \ |  _  |   / / | |
//| | \  | | |_| | | |_| | | |_| |  ___| | | | | |  / /  | |
//|_|  \_| \_____/ \_____/ \_____/ /_____/ |_| |_| /_/   |_|

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
long long t,ans,n;
long long z[100100];
string s;
long long zz ()
{
    long long l = 0, r = 0 , ans=0;
    for (long long i = 0; i < n; i++)z[i]=0;
    for (long long i = 1; i < n; i++)
    {
        if (i<=r)z[i]=min(z[i-l],r-i+1);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        ans+=z[i];
        if (i+z[i]-1>r) {r=i+z[i]-1; l=i;}
    }
  return ans;
}
int main() {
    cin>>t;
    for(long long o=0;o<t;o++)
     {
         cin>>s;
         n=s.size();
         printf("%lld\n",zz()+n);
     }
    return 0;
}
