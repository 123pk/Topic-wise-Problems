/*
Platform :- Codechef
Contest :- Codechef Starters 67
Approach :- If you will carefully observe you will find that it is always optimal to swap the big with the smallest and so on second largest with second smallest..
            On each swapping we add some amount of inversions which you have to construct the relation.
            
Editorial :- https://discuss.codechef.com/t/maxagry-editorial/104323            

Time Complexity :- O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        
        if(n == 1){
            cout<<0<<"\n";
            continue;
        }
        long long rem = 2;
        rem*=k;
        rem = (n-rem);
        rem = max(0ll,rem);
        
        if(rem == 0){
            long long ans = n;
            ans*=(ans-1ll);
            ans>>=1ll;
            
            cout<<ans<<"\n";
            continue;
        }
        
        long long ex = rem*k;
        long long small = (k);
        small*=(small-1ll);
        small>>=1;
        
        long long z = (n-k);
        long long tot = (n*(n-1ll));
        tot>>=1ll;
        
        z*=(z-1ll);
        z>>=1;
        tot -= z;
        
         tot += ex;
         tot += small;
         
         cout<<tot<<"\n";
        
    }
}
