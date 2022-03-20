/*
Platform :- Codeforces
Contest :- Codeforces Round 778(Div 1 + Div 2)
Approach :- We will traverse through the array and it is optimal to choose a prefix of size '1' and remove it , so we will look for the first character where our frequency
            of that character is '1' , all the characters from that character to the end cannot be removed and are left.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        vector<int>fre(26);
        for(auto&x:s)fre[x-'a']++;
        
        string temp="";
        int f = 0;
        for(int i=0;i<s.size();++i){
            if(f){
                temp+=s[i];
            }
            else{
                if(fre[s[i]-'a'] == 1){
                    temp+=s[i];
                    f=1;
                }
                else{
                    fre[s[i]-'a']--;
                }
            }
        }
        cout<<temp<<"\n";
        
    }
}
