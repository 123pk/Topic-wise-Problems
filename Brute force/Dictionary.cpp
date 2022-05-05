/*
Platform :- Codeforces
Contest :- Codeforces Round 786 Div 3
Approach :- We will get all the valid strings possible using two for loops from ('a' to 'z' in both) we will ignore when we have same character in both loop 
            else we will increment index variable which will initially start from zero ,as soon as we find our required string we will come out of loops and 
            print the index .
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
        int f = 0;
        for(char ch1='a';ch1<='z';++ch1){
            
            for(char ch2='a';ch2<='z';++ch2){
                string temp ="";
                temp+=ch1;
                temp+=ch2;
                if(ch1 == ch2)continue;
                ans++;
                if(temp == s){
                    f=1;break;
                }
            }
            if(f)break;
        }
        cout<<ans<<"\n";
    }
}
