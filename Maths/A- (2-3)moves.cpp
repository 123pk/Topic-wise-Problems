/*
Platform :- Codeforces
Contest :- Educational Round 133 
Approach :- We first convert n to abs(n) as its easy to deal with +ve value , now it is much better to do jump of '3' , so we will do (n/3) jumps of '3' steps , now
            if there is some remainder we need +1 additional jump .
            Take care of case when n == 1, here we need 2 jumps.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n;
        cin>>n;
        n = abs(n);
        //we can move +3,+2 or -3,-2
        long long ans = n/3ll;
        long long dis = ans*3ll;
        n-=dis;
        if(n == 2){
            ans++;
        }
        else if(n == 1){
            if(ans)ans++;
            else ans+=2;
        }
        cout<<ans<<"\n";
        
    }
}
