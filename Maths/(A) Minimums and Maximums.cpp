/*
Platform :- Codefoces
Contest :- Codeforces Educational round 128
Approach :- If we have overlapping interval , then answer is max of (a,c) else it is sum of (a+c_)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        
        int ans = 0;
        if(c<=b && c>=a  || (a<=d && a>=c)){
            //cout<<"* ";
            ans = max(a,c);
        }
        else ans = a+c;
        cout<<ans<<"\n";
    }
}
