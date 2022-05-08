/*
Platform :- Codeforces
Contest :- Codeforces Round 789 Div 2
Approach :- If there is any '0' in array then the answer is no of non zero values (let it be 'x' ),
            if we have only unque element then ansewr is x+1 else 'x'
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int f = 0,d = 0;
        long long A[n];
        map<long long ,int>count;
        for(int i=0;i<n;++i){
            cin>>A[i];
            count[A[i]]++;
            if(count[A[i]]>1){
                f=1;
            }
            if(A[i])d++;
        }
        sort(A,A+n);
        int ans = d;
        
        if(A[0]){
            if(f == 0)ans++;
        }
        
        cout<<ans<<"\n";
    }
}
