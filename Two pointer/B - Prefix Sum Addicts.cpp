/*
Platform :- Codeforces
Contest :- Codeforces Global Round 22
Approach :- We will keep on finding the values , A[i] = B[i]-B[i-1] , and all the value that we have foudn should be increasing in order 
              A[i-1]<=A[i] for all adjacent pairs , after if we have some value remaining we will find the smallest max value we can have out of all 
              x  = ceil(B[0]/(n-k)+1) .. if this 'x' is greatear than smallest A[i] value that we have calculated then also it is impossible .
 Time Comlexity :- O(k) 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        long long A[k];
        for(int i=0;i<k;++i){
            cin>>A[i];
        }
        if(k == 1){
            cout<<"YES\n";
            continue;
        }
        //point to note we have non decresing array
        vector<long long>P(n);
        int j = n-1;
        int f = 0;
        long long last;
        long long mn = 1e18;
        for(int i=k-2;i>=0;--i){
            last = A[i+1]-A[i];
            if(last<0){
                f=1;
                break;
            }
            if(i<(k-2)){
                if(last>P[j+1]){
                    f=1;
                    break;
                }
            }
           // cout<<last<<" ";
            P[j] = last;
            mn = min(mn,last);
            j--;
        }
        //long long mx = P[n-1];
        
        //now I want to achieve that last from that
        //from remaining elements 
        int rem = (n-k)+1;
        long long val = A[0];
        
        long long high = val/rem;
        if(val%rem)high++;
        
        if(high>mn)f=1;
        
        if(f)cout<<"NO\n";
        else cout<<"YES\n";
    }
    
}
