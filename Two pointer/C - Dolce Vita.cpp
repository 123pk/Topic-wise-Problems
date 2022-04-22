/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 127
Approach :- We will first sort the array of prices  ,then find the max no of different values whose sum is less than "limit" , so let it be 'd' so we will have option
            from [1 to d] no of items to buys . We will start with buying 'd' element and then going till '1' , 
            for (i) elemets we will find the sum of smallest i elements (use prefix sum to store ) now it can be used till ((limit-pref[i])/i )th day
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         long long lim;
         cin>>n>>lim;
         
         int A[n];
         for(int i=0;i<n;++i){
             cin>>A[i];
         }
         sort(A,A+n);
         
         long long ans = 0;
         int d = 0;
         long long tot = 0;
         vector<long long>pref;
         for(int i=0;i<n;++i){
             tot+=A[i];
             if(tot<=lim){
                 d++;
                 pref.push_back(tot);
             }
             else break;
         }
         
         
         long long prev = -1,last = -1;
         for(int i=d;i>=1;--i){
            //long long start
            long long sum = pref[i-1];
            sum = (lim-sum);
            long long z = i;
            sum/=z;
            
            long long wait = z*(sum-last);
            last = sum;
            ans+=wait;
         }
         
         cout<<ans<<"\n";
    }
}
