/*
Platform :- Codechef
Contest :- Codechef Starters 47
Appraoch :- You need to carefully understand the lines in problem statement 
           --> You can sepearate out all the group of size  = 1 , let c = count of such values then 
           --> if c>1 then it will cost us (c*(c+1))/2 operations to make them into a single group and it will be the minimum cost too
           --> if c == 1 and the max_size of any gropu is  = 2 then we have to do '2' opeartion
           --> else we need '1' operation and this is our edge case
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        map<long long ,int>P;
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
            P[A[i]]++;
        }
        
        int ans = 0;
        int c = 0;
        int mx = 0;
        long long val = -1;
        for(auto&x:P){
            mx= max(mx,x.second);
            if(x.second == 1){
                c++;
                val = x.first;
            }
        }
        
        sort(A,A+n);
        
        if(c == 1){
            if(mx == 2){
                if(val == A[n-1])ans+=2;
                else ans++;
            }
            else ans++;
        }
        else ans += (c+1)/2;
         
        cout<<ans<<"\n";
    }
}
