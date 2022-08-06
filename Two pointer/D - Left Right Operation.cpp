/*
Platform :- Atcode
Contest :- LINE Verda Programming Contest（AtCoder Beginner Contest 263）
Approach :- We find the max perfix difference we can get using the operation till (ith index) replacing each element with 'L' 
           Similarly we found the suffix max of change in sum we can get from (n-1th to ith index)by replacing each elemnet with 'R'.
           We found the max value(pref[i]+suff[i+1]) and also max(pref[n-1] ,suff[0])---> in this case we are removing each element and addding L or R whole 
           now we remove the max of all from the sum of elements , we will remove +ve value only if the max is -ve we ignore.

Time Complexity ;- O(n),space - O(3*n)
*/
 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
     int n;
     cin>>n;
     
     long long l,r;
     cin>>l>>r;
     
     long long A[n];
     vector<long long> pre_sum(n);
     for(int i=0;i<n;++i){
         cin>>A[i];
         pre_sum[i] = A[i];
         if(i) pre_sum[i]+=pre_sum[i-1];
     }
     long long tot = pre_sum[n-1];
     
     vector<long long>suff(n),pref(n);
     long long ans = tot;
     
     
     for(int i=0;i<n;++i){
         //what is the change if I add l to first I values 
         long long rem = tot - pre_sum[i];
         long long add = i+1ll;
         add*=l;
         
        // cout<<(i+1)<<" "<<rem<<" "<<add<<"\n";
         //rem+=add;
         
         
         if(add<pre_sum[i]){
             pref[i] = pre_sum[i] - add;
         }
         
     }
     
     for(int i=1;i<n;++i){
         pref[i] = max(pref[i],pref[i-1]);
     }
     
     for(int i=n-1;i>=0;--i){
         long long rem = pre_sum[i-1];
          
         long long add = (n-i);
         add*=r;
         //rem+=add;
         
         long long have = tot;
         if(i)have-= pre_sum[i-1];
         
         if(add<have){
             suff[i] = have - add;
         }
     }
     
     for(int i=n-2;i>=0;--i){
         suff[i] = max(suff[i],suff[i+1]);
     }
    
     long long mx = 0;
     for(int i=0;i<n-1;++i){
         long long val = pref[i] + suff[i+1];
         mx = max(mx,val);
     }
     
     
     mx = max(mx,pref[n-1]);
     mx = max(mx,suff[0]);
     
     ans -= mx;
     cout<<ans<<"\n";
 }
