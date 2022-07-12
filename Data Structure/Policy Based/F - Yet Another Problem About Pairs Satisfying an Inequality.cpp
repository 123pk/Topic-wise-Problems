/*
Platform :- Codeforces 
Contest :- Codeforces Round 806 Div 4
Appraoch :- Ordered set use to find number of values which are strictly greater tahn current 'i' value to its right . We make seperate array of value pairs which for
            or satisfy A[i]<i
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
        vector<int>B;
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(A[i]<(i+1))B.push_back(i);
        }
        
        
        long long ans = 0;
        
        ordered_set P;
        for(int i=B.size()-1;i>=0;--i){
            int idx = B[i];
            if(i == B.size()-1)P.insert(A[idx]);
            else{
                ans+= P.size() - P.order_of_key(idx+2);
               
                P.insert(A[idx]);
            }
        }
        
        
        
        cout<<ans<<"\n";
    }
    
}
