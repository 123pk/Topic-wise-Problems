/*
Platform :- Codeforces
Contest :- Codeforces Round 772 Div2
Approach :- Just find OR of all the element sof array
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        vector<int>val(32);
        string temp;
        
        for(int i = 0;i<n;++i){
            cin>>A[i];
            temp = bitset<32>(A[i]).to_string();
            for(int j = 0;j<32;++j){
                val[j]+=(temp[j]-'0');
            }
        }
        
        int ans = 0;
        reverse(val.begin(),val.end());
        
        for(int i = 0;i<32;++i){
            if(val[i])ans+=(1<<i);
        }
        
        cout<<ans<<"\n";
    }
}
