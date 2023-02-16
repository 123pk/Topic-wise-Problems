/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 143
Approach :- 
Time Complexity :- O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;

int search(vector<long long>&A,long long value,int start){
    int end = A.size()-1,mid = (start+(end-start)/2);
    int ans = start;
    while(start<=end){
        if(A[mid]<=value){
            ans = mid;
            start = mid+1;
            mid = (start+end)/2;
        }
        else{
            end = mid-1;
            mid = (start+end)/2;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       
       long long A[n];
       vector<long long>pref(n);
       long long tot = 0;
       for(int i=0;i<n;++i){
           cin>>A[i];
            
            
       }
       
       long long B[n];
       for(int i=0;i<n;++i){
           cin>>B[i];
           tot += B[i];
           pref[i] = tot;
       }
       
       vector<long long>ex(n);
       vector<int>count(n);
       
       for(int i=n-1;i>=0;--i){
           //no of value to my left
           long long rem = 0;
           if(i)rem += pref[i-1];
           rem += A[i];
           
           int idx = search(pref,rem,i);
           //cout<<i+1<<" "<<idx<<" for "<<rem<<"\n";
           //now if sum is exactly equal to that
           if(pref[idx] == rem){
               count[idx]++;
               if(i)count[i-1]--;
           }
           else if(pref[idx]<rem){
               count[idx]++;
               if(i)count[i-1]--;
               if((idx+1)<n)ex[idx+1] += (rem-pref[idx]);
           }
           else{
               ex[idx] += A[i];
           }
       }
       
       long long cur_count = 0;
       vector<long long>ans(n);
       for(int i=n-1;i>=0;--i){
           cur_count += count[i];
           count[i] = cur_count;
           long long value = cur_count*B[i];
           value += ex[i];
           ans[i] = value;
       }
      
       
       for(auto&x:ans)cout<<x<<" ";
       cout<<"\n";
    }
}
