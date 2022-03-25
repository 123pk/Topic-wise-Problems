/*
Platform :- Codeforces 
Contest :- Codeforces CodeTon (Div1+Div2)
Explanation :- It is purely based on math and observation ,for all odd values we have always a solution for k ='2'.
               1. For all power of 2 we dont have any solution
               2. For all other even values we will find values.
               
               Link :- https://codeforces.com/blog/entry/101211
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n;
        cin>>n;
        
        long long k = 1;
        
        if(n%2)cout<<2<<"\n";
        else{
            n<<=1;
            while(n%2==0){
                n>>=1;
                k<<=1;
            }
            if(n == 1)cout<<"-1\n";
            else{
                cout<<min(n,k)<<"\n";
            }
        }
    }
}
