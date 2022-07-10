/*
Platform :- Coding Competition with google
Contest :- Google Kickstart Round D 2022
Approach :- It is optimal to sort the array and make set of size '1' of largest (m-1) values and for last set of (n-(m-1)) values we will get the middle value as said in 
            problem statement
Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        int n,m;
        cin>>n>>m;
        
        long double A[n];
        for(int i = 0;i<n;++i){
            cin>>A[i];
        }
        
        sort(A,A+n);
        
        long double ans = 0;
        int i=n-1;
        while(m>1){
            ans+=A[i];
            i--;
            m--;
        }
       // cout<<ans<<" "<<i<<endl;
        if(i%2){
            //we have even no of value
            int idx = i/2;
            long double mid =A[idx] + A[idx+1];
            mid/=2;
            ans+=mid;
        }
        else ans+=A[i/2];
        
        cout<<to_string(ans)<<"\n";
        
    }
}
