/*
Platform :- Codeforces
Contest :- Codeforces Round 806 Div 4
Approach :- We know the max value of A[i] is 10^9 , so it means if no of 2nd operation is more than 30 then that max value will also become zero ,
            so for each index 'i' from 0 to n-1 we will check what if we proceed first 'i' values with 1st operation and next min(n,i+32) value with 
            operation 2nd and store the max of all sum obtained . That will be our required ansewr.
            
Time Complexity :- O(n*32) -- O(n)
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
 
        cin>>n>>k;
        
        vector<long long>A(n);
        for(int i=0;i<n;++i)cin>>A[i];
        
        long long ans = -1e18;
        
        long long tot = 0;
        for(int i=-1;i<n;++i){
            //tot+= (A[i]-k)
            long long sum = tot;
            for(int j=i+1;j<min(n,i+32);++j){
                long long z = A[j];
                z>>=(j-i);
                sum += z;
            }
            //cout<<sum<<" "<<i<<"\n";
            ans = max(ans,sum);
            if((i+1)<n)tot += (A[i+1]-k);
        }
        
        cout<<ans<<"\n";
    }
}
