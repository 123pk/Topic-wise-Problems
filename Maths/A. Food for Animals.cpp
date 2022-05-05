/*
Platform :- Codeforces 
Contest :- Codeforces Round 787 
Approach :- We will try to find extra requirement to be fullfilled for dog and cat and if that value is greater than universal value then we cannot feed then else we can
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        
        long long have = 0;
        if(x>a){
            x-=a;
        }else x = 0;
        
        if(y>b)y-=b;
        else y = 0;
        
        have = x+y;
        if(have<=c)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
