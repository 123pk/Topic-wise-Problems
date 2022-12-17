/*
Approach :- For even sum we need even number of odd values,
           there are two ways .
           1. Change any odd to even 
           2. Change any even to odd 
           we choose the one with min cost
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        int c_odd = INT_MAX,c_eve = INT_MAX;
        int odd = 0,eve = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            int cur = 0;
            
            int val = A[i];
            if(val%2){
                odd++;
                //cost to make it even
                while(val%2){
                    val/=2;
                    cur++;
                }
                c_odd = min(c_odd,cur);
            }
            else{
                eve++;
                while(val%2 == 0 && val){
                    val/=2;
                    cur++;
                }
                c_eve = min(c_eve,cur);
            }
        }
        
        if(odd%2 == 0)cout<<0<<"\n";
        else{
            //we change one even to odd 
            
            //change one odd to eve
            cout<<min(c_odd,c_eve)<<"\n";
        }
    }
}
