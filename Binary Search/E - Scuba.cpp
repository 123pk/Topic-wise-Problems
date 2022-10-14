/*
Platform :- Codeforces 
Contest :- Codeforces Round 827 Div 4
Approach :- We will store the sum of height that we can achieve for each of the steps , so we will store the steps in set , if step[i]<step[i-1] ,then we ignore this 
            step[i-1] = height[i-1]+height[i] , now we will use lower_bound to find the nearest valid step that we can have and the height correspondingg to it is 
            our soution.
Time Complexity :- O(n*log(n))
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         int n,q;
         cin>>n>>q;
         
         long long A[n];
         map<long long,long long>values;
         set<long long>steps;
         long long last,sum = 0;
         for(int i=0;i<n;++i){
             cin>>A[i];
             sum += A[i];
             if(i == 0){
                 steps.insert(A[i]);
                 values[A[i]] = sum;
                 last = A[i];
             }
             else{
                 if(last >= A[i]){
                     values[last] = sum;
                 }
                 else{
                     last = A[i];
                     steps.insert(A[i]);
                     values[last] = sum;
                 }
             }
         }
         
         
         for(int i=0;i<q;++i){
             long long x;
             cin>>x;
             
             auto it = steps.lower_bound(x);
             if(it == steps.end())it--;
             long long val = *it;
             long long score = values[val];
             
             if(val > x){
                 if(it == steps.begin())score = 0;
                 else {
                     it--;
                     val = *it;
                     score = values[val];
                 }
             }
             cout<<score<<" ";
         }
         cout<<"\n";
    }
}
