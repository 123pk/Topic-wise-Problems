/*
Platform :- Codechef
Contest :- Codechef Starters 41
Approach :- if k == 1, then we will always get the current parity of 'n'
            else for k = 2, we will always get 'ODD' parity
            else for all other values we will get even parity.
            
            Why , because we will always be left with 2 to k-1, values and on each move we will get rid of odd elements except of the case when k = 2 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n,k;
        cin>>n>>k;
        
        if(k == 1){
            if(n%2ll)cout<<"ODD"<<"\n";
            else cout<<"EVEN\n";
        }else{
            if(k == 2ll)cout<<"ODD\n";
            else cout<<"EVEN\n";
        }
        
    }
}
