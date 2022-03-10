/*
Platform :- Codechef
Contest :- Codechef Starters
Approach :- We can have max value of our solution be 'n' in this case we have no adjacent pairs that are equal , else we find the no of no overlapping adjacent pairs and let is
            be 'c' the our solution is (n-'c')
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        int ans = n;
        for(int i=0;i<n;++i){
            if((i+1)<n){
                if(s[i] == s[i+1]){
                    ans--;
                    i++;
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}
