/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 124
Approach :- We will always have the winner that is the largest odd value from (1 to 2^n) ,  which is 2^n-1
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int ans = (1<<n)-1;
        cout<<ans<<"\n";
    }
}
