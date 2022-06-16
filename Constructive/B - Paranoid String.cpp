/*
Platform :- Codeforces
Contest :- Codeforces Round 800 Div 2
Approach :- We will traverse through the array and will maintain one count , as soon as we foound s[i] != s[i-1] , we will add count to our answer,and update it .
           we will start with inital value of our anwer as 'n' 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    
    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        long long ans = n;
        long long c = 0;
        char last;
        for(int i=0;i<n;++i){
            if(i == 0){
                c++;
                last = s[i];
            }
            else{
                //we need to do this
                if(s[i] == last){
                    c++;
                }
                else{
                    ans+=c;
                    c++;
                }
                last = s[i];
            }
        }
        cout<<ans<<"\n";
    }
}
