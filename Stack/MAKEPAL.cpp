/*
Contest :- Codechef Starters 66
Approach :- 
Time Complexity ;- O(n)
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
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        vector<long long>cost(n);
        for(int i=0;i<(n/2);++i){
            cost[i] = max(A[i],A[n-1-i])-A[i];
            cost[n-1-i] = max(A[i],A[n-1-i])-A[n-1-i];
        }
        
        long long ans = 0;
        long long last = 0;
        stack<int>P;
        P.push(0);
        for(int i=0;i<n;++i){
            //check with the top value
            if(P.top()>=cost[i]){
                ans += (P.top()-cost[i]);
                P.pop();
                P.push(cost[i]);
            }
            else{
                P.push(cost[i]);
            }
        }
        
        while(!P.empty()){
            int first = P.top();
            P.pop();
            if(P.empty())break;
            ans += first - P.top();
        }
        cout<<ans<<"\n";
    }
}
