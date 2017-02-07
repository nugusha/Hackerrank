#include <cmath>
#include <cstdio>
#include <assert.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define se second
#define fi first
int a[100005];
vector<pair<int,char > > v;
int main() {
    string s,s1,s2;
    
    int n=26;
    
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)if(a[i])v.push_back(make_pair(a[i],i+'a'));
    
    sort(v.begin(),v.end());
    
    s+=v[0].se;
        
        for(int i=v[0].se-'a'+1;i<26;i++)
                for(int j=0;j<a[i];j++)s2+=char(i+'a');
            
            
        for(int i=0;i<v[0].se-'a';i++)
                for(int j=0;j<a[i];j++)s1+=char(i+'a');
            
        
            
            
            
            if(s1.size()==0 && v[0].fi>2 && s2.size() && v.size()>1)
            {
            string s3;
            s3+=v[0].se;
            s3+=v[0].se;
                    for(int i=v[0].se-'a'+1;i<26;i++)
                    {
                        if(a[i])
                        {
                            int l=0;
                            for(int j=2;j<v[0].fi;j++)
                                    s3+=char(i+'a'),s3+=v[0].se,l++;
                            
                            for(int j=l;j<a[i];j++)s3+=char(i+'a');
                            
                            for(int q=i+1;q<26;q++)
                                    for(int u=0;u<a[q];u++)s3+=char(q+'a');
                                
                              cout<<s3<<endl;
                            return 0;
                            
                        }
                    }
                
            
            }
            
            
            
            
            s+=s1;
    for(int i=1;i<v[0].fi;i++)s+=v[0].se;
            s+=s2;
            
            
            
            
            
            cout<<s<<endl;
        return 0;
    
    
    
    
    
            
    return 0;
    
    
}
