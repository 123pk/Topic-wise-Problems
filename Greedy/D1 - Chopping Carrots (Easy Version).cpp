/*
Platform :- Codeforces 
Contest :- Codeforces Round 809 Div 2
Approach :- Since the constraints are small , we will try to covert each value in array to nearest possible value of 'i' for all 'i' from '1' to 3000 , solution is 
            the min difference between the max and min value near to 'i'
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        int A[n];
        for(int i=0;i<n;++i)cin>>A[i];
        sort(A,A+n);
        
        int ans = INT_MAX;
        for(int i=1;i<=3000;++i){
            //we will try to covert to nearest value i to all the A
             
            int mn = INT_MAX,mx = 0;
            for(int j=0;j<n;++j){
                //we have to find min of this
                if(i > A[j]){
                    mx = max(mx,A[j]);
                    mn = min(mn,A[j]);
                    continue;
                }
                int val1 = A[j]/i;
                
                //mx = max(mx,val1);
                if(val1 <= k){
                    mx = max(mx,A[j]/val1);
                    mn = min(mn,A[j]/val1);
                     
                }
                else {
                    val1 = A[j]/k;
                //int val2 = abs(x - i);
                    mx = max(mx,val1);
                    mn = min(mn,val1);
                }
              //  cout<<mx<<" "<<mn<<"\n";
                //dif += val1;
            }
           // cout<<"\n";
            ans = min(ans,mx - mn);
            
        }
        
        cout<<ans<<"\n";
        
        
    }
}
