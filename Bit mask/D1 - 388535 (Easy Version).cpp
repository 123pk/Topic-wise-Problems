/*
Platform :- Codeforces
Contest :- Codeforces Round 779 Div 2
Approach :- We will maintian one frequency array and will store the frequency of each bit in array for values from (0 to r) , now we create another frequecy array
            where we store the frequency of bit of array given , now we compare the bits of both arrays and if they are not equal we will add 2^i value where 'i' is ith bit
            as that bit is altered.
*/
#include<bits/stdc++.h>
using namespace std;
 

bool check(string&s){
    int n = s.size();
    for(int i=0;i<(n/2);i++){
        if(s[i] != s[n-1-i]){
            return false;
        }
    }
    return true;
}


int main(){
     int t;
     cin>>t;
     
     while(t--){
         int l,r;
         cin>>l>>r;
         int n = (r-l)+1;
         vector<int>A(n),count(32);
         for(int i=0;i<n;++i){
             cin>>A[i];
             string temp = bitset<32>(A[i]).to_string();
             reverse(temp.begin(),temp.end());
             for(int j=0;j<32;++j){
                 if(temp[j]-'0')count[j]++;
             }
         }
         
         vector<int>req(32);
         for(int i=0;i<=r;++i){
             string temp = bitset<32>(i).to_string();
             reverse(temp.begin(),temp.end());
             for(int j=0;j<32;++j){
                 if(temp[j]-'0')req[j]++;
             }
         }
         int ans = 0;
         for(int i=0;i<32;++i){
             if(count[i]!=req[i]){
                 ans += (1<<i);
             }
         }
         cout<<ans<<"\n";
     }
}
