/*
Platform :- Codeforces
Contest :- Codeforces Round 808 Div 2
Approach :- It is optimal to choose the value from end , we maintain one prefix array which store number of values (A[i] <= k) till 'ith' index, now we start
           from the last value and try to get as many problem as we can from 'k' value.
           
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        
        long long A[n];
        int count[n];
        long long tot = 0;
        string x = "";
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(A[i]<=k){
                count[i] = 1;
                x+='1';
                tot++;
            }
            else x+='0';
        }
        
        long long ans = tot;
        for(int i=1;i<n;++i){
            count[i] += count[i-1];
        }
        
        long long val =0;
        tot = 0;
        string s = "";
        long long cur = 0;
        //now start from the end and greedilly decide which index to be given 
        for(int i=n-1;i>=0;--i){
            if(val>=k){
                if(A[i]<=k){
                    s+='1';
                    tot++;
                }
                else s+='0';
            }
            else{
                if(val >= A[i]){
                    tot++;
                    s+='1';
                }
                else{
                    s+='1';
                    val++;
                    tot++;
                }
            }
        }
        reverse(s.begin(),s.end());
        if(tot>ans){
            x = s;
        }
        cout<<x<<"\n";
    }
}
