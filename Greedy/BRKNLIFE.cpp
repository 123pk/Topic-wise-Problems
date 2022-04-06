/*
Platform :- Codechef
Contest :- Codechef Starters 33
Approach :- If 'A' is subsequenece of 'S' then there is no way we can get 'S1' in this case we print -1
            else we find the missing character starting from left to right while checking for subsequence , and similarly form right to left 
            we ignore these two characters and choose any characters different from this and fill them in '?'
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        
        int n,m;
        cin>>n>>m;
        
         string s,p;
         cin>>s>>p;
         
         
         //if our string is already a subsequence then we cannot trasform
         //check if p is subsequence or not
         char ch = '@';
         int j = 0;
         for(int i=0;i<n && j<m;++i){
             if(s[i] == p[j]){
                 j++;
             }
         }
         
         if(j == m){
             cout<<"-1\n";
         }
         else{
             ch = p[j];
             
             //now reverse check
             char ch2='@';
             j = m-1;
             for(int i=n-1;i>=0 && j>=0;--i){
                 if(s[i] == p[j]){
                     j--;
                 }
             }
             ch2 = p[j];
            // vector<char>P;
             char start = 'a';
             for(;start<='e';start++){
                 if(ch!=start && start!=ch2){
                     ch = start;
                     break;
                 }
             }
             for(int i=0;i<n;++i){
                 if(s[i] == '?')cout<<ch;
                 else cout<<s[i];
             }
             cout<<"\n";
         }
         
    }
}
