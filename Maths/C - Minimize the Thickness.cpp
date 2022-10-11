/*
Platform :- Codeforces
Contest :- Codeforces Round 826 Div 3
Approach :- We will find the sum and then store the unique factors in a vector,
            now for each vector we will find the size of smallest value and that will be our ansewr.
Time Complexity :- O(n*(sqrt(sum))
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long tot = 0;
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
            tot += A[i];
        }
        
        //find the factors
        set<long long>P;
        for(long long i=1;i*i<=tot ;++i){
            if(tot%i == 0){
                P.insert(tot/i);
                P.insert(i);
            }
        }
        
        vector<long long>temp;
        for(auto&x:P)temp.push_back(x);
        int ans = INT_MAX;
        for(auto&x:temp){
            int c = 0,d = 0,f = 0;
            int have = tot/x;
         //   if(have>n)continue;
            
            long long sum = 0;
            
            for(int i=0;i<n;++i){
                sum += A[i];
                c++;
                if(sum == x){
                    if(i == n-1)f=1;
                    d = max(d,c);
                    c = 0;
                    sum = 0;
                }
            }
            
           if(f) ans = min(ans,d);
        }
        cout<<ans<<"\n";
    }
}
