/*
Platform :- Codeforces
Contest :- Codeforces Round 855 Div 3
Approach :- We will first check if we have same number and type of characters in each string or not ,
            now if you will observe you will find that for index [0,min(n,k)-1] if there is any index which have different characters s[i]!=p[i] 
            and [i+k < n] then we can always change this value .
            else we cannot chang that value and our answer is "NO" else 
            we can and it is "YES".
            
            how is this happening ?
            k = 5 and n = 8 
            we can move from 0 --> 5, 1 - >6 , 2 ->7 , 7->1 , 6 -> 0 so this is forming a cycle we can visit all the cells if we are able to visit
            [0,min(k,n)-1] cell .
Time Complexity :- O(n)
*/

#include<bits/stdc++.h>
using namespace std;

bool check(string s,string p){
    sort(s.begin(),s.end());
    sort(p.begin(),p.end());
    
    for(int i=0;i<s.size();++i){
        if(s[i] != p[i])return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k;
         cin>>n>>k;
         
        string s,p;
        cin>>s>>p;
        
        if(!check(s,p)){
            cout<<"NO\n";
            continue;
        }
        
        int f = 0;
        vector<int>vis(k);
        for(int i=0;i<min(k,n);++i){
            if((i+k)<n){
                continue;
            }
            if(s[i] != p[i]){
                f=1;
                break;
            }
            
        }
        
        if(f)cout<<"NO\n";
        else cout<<"YES\n";
         
    }
}
