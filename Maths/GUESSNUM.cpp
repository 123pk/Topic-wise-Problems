/*
Platform :- Codechef
Contest :- December Lunchtime 2019 Div 2
Approach :- This is based on Pure maths and finding factors of value in O(sqrt(N)),
*/
#include<bits/stdc++.h>
using namespace std;

bool check(long long& y,long long&a){
    return (y-1)%a == 0;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         long long a,m;
         cin>>a>>m;
         
         /*
          Let us simplify the equation 
          M = a*N + d;
          where 'd' is factor of N 
          so we can write 
          
          M  = a*x*d + d   here x*d = N   
          
          So taking d commmon , Now M also need to be multiple of 'd' or d is factor of M 
          So 
          
          y*d = a*x*d + d
          y-1  = a*x
          x = y-1/a
          N = x*d
          
         */
         
         vector<pair<long long,long long>>factors_of_m;
         
         for(long long i = 1;i*i<=m;++i){
             if(m%i == 0){
                 factors_of_m.push_back({i,m/i});
                 //factors_of_m.push_back();
             }
         }
         
         /*
         
         */
         vector<long long> ans;
         long long val  = 0;
         for(int i=0;i<factors_of_m.size() ; ++i){
             //for each value pair assume one to be 'y' and one to be 'd'
             //vice versa
             long long y = factors_of_m[i].first;
             long long d = factors_of_m[i].second;
         //    cout<<y<<" "<<d<<" "<<a<<"\n";
             if(check(y,a) && y>1){
                 
                 val = (y-1)/a;
                 val*=d;
                 ans.push_back(val);
                 
             }
              
                 swap(y,d);
                 if(check(y,a) && y>1){
                     val = (y-1)/a;
                     val*=d;
                     ans.push_back(val);
                 }
              
         }
         sort(ans.begin(),ans.end());
         
         cout<<ans.size()<<"\n";
         for(auto &x:ans)cout<<x<<" ";
         cout<<"\n";
         
    }
}

 
