#include <bits/stdc++.h>

using namespace std;
string check(string s){
    
    long long num=0;
    string ret;
    for(int i=1;i<=s.size()/2;i++){
        num=num*10+s[i-1]-'0';
        string ne=to_string(num);
        ret="";
        long long now=num;
        while(ret.size()<s.size()){
            ret+=to_string(now);
            now++;
        }   
   //     cout<<s<<" "<<ret<<endl;
        if(ret==s)return ne;
    }
    return "-";
}
int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string x=check(s);
        if(x=="-")cout<<"NO"<<endl;else
                  cout<<"YES "<<x<<endl;
        // your code goes here
    }
    return 0;
}
