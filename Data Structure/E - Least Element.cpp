/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 281
Approach:- We maintain two set , one to store the 'k' smallest vlaues in range , one another set to store the remaining (m-k) values of range ,
           We maitain frequency count also .
           The main idea is to store smallest k value sin one set and reamaining in other ,then when we have new value we compare with the largest 
           value in current set if (largest_available > current) we add current to set and add the largest_available to extra. We do the following changes in 
           sum also.
 Time Complexity :- O(n log n)
  */
#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,m,k;
     cin>>n>>m>>k;
     
     long long A[n];
     for(int i=0;i<n;++i)cin>>A[i];
     
     map<long long,int>cur_fre,extra_fre;
     set<long long>cur,extra;
     long long tot = 0;
     vector<long long>ans;
      int count = 0;
     for(int i=0;i<m;++i){
         if(count == k){
             //check if biggest value is bigger or smaller than current
             auto it = cur.rbegin();
             long long last = *it;
             if(last>A[i]){
                 cur_fre[last]--;
                 cur.insert(A[i]);
                 cur_fre[A[i]]++;
                 tot -= last;
                 tot += A[i];
                 //removing the last eleemnt if fre is 0
                 if(cur_fre[last] == 0)cur.erase(last);
                 extra.insert(last);
                 extra_fre[last]++;
             }
             else{
                 //we add this to extra
                
                 extra.insert(A[i]);
                 extra_fre[A[i]]++;
             }
             
         }
         else{ 
             count++;
             tot += A[i];
             cur.insert(A[i]);
             cur_fre[A[i]]++;
         }
         
     }
     ans.push_back(tot);
    
     
     for(int i=m;i<n;++i){
         
         if(i>=m){
             //we remove the i-mth value
             long long val = A[i-m];
             //check if it is extra'
             if(extra.size()){
                 if(extra.find(val) != extra.end()){
                     extra_fre[val]--;
                     if(extra_fre[val] == 0)extra.erase(val);
                 }
                 else{
                     count--;
                     cur_fre[val]--;
                     tot -= val;
                     if(cur_fre[val] == 0)cur.erase(val);
                 }
             }
             else{
                 count--;
                 cur_fre[val]--;
                 if(cur_fre[val] == 0)cur.erase(val);
                 tot -= val;
             }
         }
         
         if(count<k){
             if(extra.size()){
                 auto it = extra.begin();
                 long long z = *it;
                 extra_fre[z]--;
                 if(extra_fre[z] == 0)extra.erase(z);
                 cur.insert(z);
                 count++;
                 cur_fre[z]++;
                 tot += z;
             }
             else{
                 count++;
                 cur.insert(A[i]);
                 cur_fre[A[i]]++;
                 tot += A[i];
                 ans.push_back(tot);
                 continue;
             }
         }
        
             auto it = cur.rbegin();
             long long last = *it;
             
             if(last>A[i]){
                 tot -= last;
                 cur_fre[last]--;
                 
                 cur.insert(A[i]);
                 cur_fre[A[i]]++;
                 
                 if(cur_fre[last] == 0)cur.erase(last);
                 
                 extra_fre[last]++;
                 extra.insert(last);
                 tot += A[i];
                 
                 
             }
             else{
                 extra.insert(A[i]);
                 extra_fre[A[i]]++;
             }
             ans.push_back(tot);
        
     }
     
     for(auto&x:ans)cout<<x<<" ";
     cout<<"\n";
}
