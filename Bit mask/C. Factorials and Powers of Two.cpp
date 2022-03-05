/*
Platform :- Codeforces
Contest :- Codeforces Round 774 Div 2
Approach :- We first find all the factorials that are <=n and make an array , then we try to find all possible distinct subsequence sum of that array , let 'c' = no of elements
            in that subsequence , we also maintain a 'rem' variable to store the (n - ' sum_of_subsequece_choosen ') then we find binary representaion of that rem value as it is 
            'sum of power of 2' let no of set bit in it be 'd' then for ith subseqence we have (c+d) no of distinct value which add upto 'n' and min of all of them is our value.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       long long n;
       cin>>n;
      
        vector<long long>P;
        long long val = 1,d = 0;
        while(1){
            d++;
            val*=d;
            if(val>n){
                val/=d;
                d--;
                break;
            }
            P.push_back(val);
        }
        
        string temp = bitset<64>(n).to_string();
        int ans = count(temp.begin(),temp.end(),'1');
        int c = 0;
        long long  rem = 0;
        
        //so whatever option we have
        for(int i=1;i<=(1<<d);++i){
            long long tot = 0;
            int e = 0;
            c= 0;
            for(int j=0;j<d;++j){
                if(i&(1<<j)){
                    tot+=P[j];
                    e++;
                }
            }
           // cout<<tot<<" ";
            if(tot<=n){
                if(tot == n){
                    ans = min(ans,e);
                }
                else{
                    rem = n-tot;
                    temp = bitset<64>(rem).to_string();
                    c = count(temp.begin(),temp.end(),'1');
                    c+=e;
                    ans = min(ans,c);
                }
            }
        }
        cout<<ans<<"\n";
        
    }
}
