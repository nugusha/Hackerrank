#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int siz1,siz2;
long long aa[1004592];
long long bb[1004592];
void go(long long *aa,int &siz)
{
    for(int i=0;i<siz;i++)
            if(aa[i]>=1000)
            {
                if(i==siz-1)siz++;
        
                aa[i+1]+=aa[i]/1000;
                aa[i]%=1000;
            }
}
void ch(long long x)
{
    if(x<10)printf("00");else
    if(x<100)printf("0");
}
int main() {
    long long *a=aa;
    long long *b=bb;
    int A,B,n;
    cin>>A>>B>>n;
    a[0]=A;
    b[0]=B;siz1=siz2=1;go(a,siz1);go(b,siz2);
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<siz2;j++)
        for(int q=0;q<siz2;q++) 
                a[j+q]+=b[j]*b[q];
            
        
        siz1=siz2*2-1;
        
        go(a,siz1);
        
        swap(siz1,siz2);
        
        swap(a,b);
    }
    for(int i=siz2-1;i>=0;i--){if(i!=siz2-1)ch(b[i]);printf("%lld",b[i]);}cout<<endl;
    return 0;
}
