/*
Platform :- Codeforces
Contest :- Codeforces Round 780 Div 3
Approach :- 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        int ans = 0;
        
        stack<char>P;
        vector<int>count(26);
        for(auto&x:s){
            if(P.empty()){
                P.push(x);
                count[x-'a']++;
            }
            else{
                if(count[x-'a']){
                    
                    while(!P.empty()){
                        count[P.top()-'a']--;
                        P.pop();
                        ans++;
                    }
                    count[x-'a'] = 0;
                    ans--;
                   // P.pop();
                }
                else{
                    P.push(x);
                    count[x-'a']++;
                }
            }
            //cout<<P.size()<<" "<<ans<<"\n";
        }
        while(!P.empty()){
            P.pop();
            ans++;
        }
        cout<<ans<<"\n";
    }
}
