/*
Platform :- Codechef
Contest :- Codechef Starters 68
Approach :- 
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
        vector<long long>odd,even;
        int c = 0;
        long long mod = 998244353;
        long long ans = 1;
        
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(A[i]%2){
                if(A[i] == 1)c++;
                else{
                    ans*=A[i];
                    ans%=mod;
                }
            }
            else even.push_back(A[i]);
        }
        
        
        sort(even.begin(),even.end());
        //get the even values seperate
        
        //reverse(even.begin(),even.end());
        int m = even.size();
        
        for(int i=0;i<m;++i){
            if(i<c){
                even[i]++;
                ans*=even[i];
                ans%=mod;
            }
            else{
                ans*=even[i];
                
                ans%=mod;
            }
        }
        
        
        
        cout<<ans<<"\n";
    }
}
