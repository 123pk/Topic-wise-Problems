/*
Platform :- CSES
Problemset :- Dynamic Programming
Approach :- We maintain a set where we store the element of LIS , now when we get new element we find a spot for this current element in the LIS and if there is no element
            greater than this we increment our LIS len by 1 and update answer too, else we remove the just greater element and insert this element, we also store the len
            of LIS for each value in set.
            
            So for finding just greater element we use "Lower_bound" in c++ set stl
Time Complexity :- O(n*log(n))
*/
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        int n;
        cin>>n;
        
        vector<long long>A(n);
        for(int i = 0;i<n;++i){
            cin>>A[i];
        }
        
        set<long long>values;
        map<long long,int>idx;
        int ans = 0;
        vector<int>dp(n,1);
        
        
        for(int i=0;i<n;++i){
            if(i == 0){
               dp[0] = 1;
               values.insert(A[i]);
               idx[A[i]] = 0;
               ans = max(ans,dp[i]);
            }   
            else{
              auto it = values.lower_bound(A[i]);
              if(it == values.end()){
                  //ther is no value that is greatear than or equal to this value
                  //so we simplifyy add it to the lIS till this index
                  dp[i] = ans+1;
                  ans++;
                  values.insert(A[i]);
                  idx[A[i]] = i;
                  continue;
              }
              
              long long cur = *it;
              //cout<<A[i]<<" "<<cur<<" "<<dp[idx[cur]]<<"\n";
              dp[i] = dp[idx[cur]];
              
              if(A[i] == cur)continue;
              
              if(A[i]<cur)values.erase(cur);
              values.insert(A[i]);
              idx[A[i]] = i;
              
               
              ans = max(ans,dp[i]);
              
               
            }
        }
        
        //for(int i=0;i<n;++i)cout<<dp[i]<<" ";
      //  cout<<"\n";
        
        cout<<ans;
    }
}
