/*
Platform :- Codechef
Contest :- Codechef Lunctime April
Approach :- if either of value is '1' then our answer is also '1' else
             we do prime factorisation of 'X'(changing value) , find the primes and their powers , suppose power of some prime 'a' is 'b' in 'X' then if (b>(c-b)) then only
             it is useful as it will decresse X by a^(c-b) , we need to take care of case when 'a' > c there we will first do (a % c)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long x;
        int y;
        cin>>x>>y;
        
        if(x == 1ll || y == 1){
            cout<<"1\n";
        }
        
        /*
        The basic approach is to find the factors of x and everytime we check if it would be benificial to 
         remove that power of z
        */
        else{
            vector<pair<int,int>>P;
            long long start = x;
            int c = 0;
            long long val = start;
            while(start%2 == 0){
                start>>=1ll;
                c++;
            }
            
            c = c%y;
            
            if(c>(y-c)){
                P.push_back({2,y-c});
            }
            else{
               P.push_back({2,c});  
            }
            
            for(long long i=3;i<=start;i+=2ll){
                c = 0;
                while(start%i == 0){
                    start/=i;
                    c++;
                }
                c = c%y;
                if(c>(y-c)){
                    P.push_back({i,y-c});
                }else{
                    P.push_back({i,c});
                }
            }
            
            long long ans = 1;
            long long z;
            for(auto&x:P){
               // cout<<x.first<<" "<<x.second<<"\n";
                z = x.first;
                for(int i =1;i<=x.second;++i){
                    ans*=z;
                }
            }
            
            
            cout<<ans<<"\n";
        }
    }
}
