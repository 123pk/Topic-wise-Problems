/*
Platform :- Codeforces
Contest :- Codeforces Round 809 Div 2
Approach :- For odd length of 'n' we have one solution and that is to make all values at even index (1-based indexing) greater than their adjacne neighbours.
            For even length of 'n' we have three options and min cost of those three is our solution
Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
        for(int i=0;i<n;++i)cin>>A[i];
        
        //we want to maximise no of cool building with minimising cost
        //can we do binary search ?
        //because number is limited 
        
        //in case of odd no of building we donot have any option so we get it directly 
        if(n%2){
            long long ans =0;
            
            for(int i=1;i<n;i+=2){
                if(A[i]>A[i-1]&& A[i]>A[i+1])continue;
                ans += (max(A[i-1],A[i+1]) - A[i])+1ll;
            }
            
            cout<<ans<<"\n";
        }
        else{
            long long ans = 1e18,tot = 0;
            //we have 3 options 
            //start from 2,4,6,...
            
            for(int i=1;i<n-1;i+=2){
                if(A[i]>A[i-1]&& A[i]>A[i+1])continue;
                tot += (max(A[i-1],A[i+1]) - A[i])+1ll;
            }
            ans= min(ans,tot);
            
            tot = 0;
            //start with 3,5,7 ..
            for(int i=2;i<n-1;i+=2){
                if(A[i]>A[i-1]&& A[i]>A[i+1])continue;
                tot += (max(A[i-1],A[i+1]) - A[i])+1ll;
            }
            ans= min(ans,tot);
            
            tot = 0;
            //start with 2,5,7,..
            //for this we need help of suffix sum
            vector<long long>suff(n);
            for(int i=n-1;i>0;--i){
                if(i == n-2){
                        long long val = 0;
                        if(A[i]>A[i-1] && A[i]>A[i+1]){
                            val = 0;
                        }
                        else{
                            val += (max(A[i-1],A[i+1]) - A[i]) + 1ll;
                        }
                        suff[i] = val ;
                }
                else {
                    if(i%2 == 0){
                        long long val = 0;
                        if(A[i]>A[i-1] && A[i]>A[i+1]){
                            val = 0;
                        }
                        else{
                            val += (max(A[i-1],A[i+1]) - A[i]) + 1ll;
                        }
                        suff[i] = val + suff[i+2];
                    }
                }
            }
            
            tot = 0;
            for(int i=1;i<n-1;i+=2){
                long long val = 0;
                if(A[i]>A[i-1] && A[i]>A[i+1]){
                    val = 0;
                }
                else val += (max(A[i-1],A[i+1])-A[i]) + 1ll;
                tot += val;
                if((i+3) < n)ans= min(ans,tot + suff[i+3]);
                else break;
            }
            
            cout<<ans<<"\n";
            //min cost out of three is our solution 
            
        }
        
    }
}
