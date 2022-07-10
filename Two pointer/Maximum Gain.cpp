/*
Platform :- Coding Competition with google
Contest :- Google Kickstart Round D 2022
Approach :- We can have 'k' moves so we will try to divide the moves optimally such that we get maximum sum , for each 'i' from 0 to 'k' we will do (i) operations from first
            array and min(m,k-i) operations from array 2 , in those moves we will find the max value we can acheive and max of sum of all those value pair is our solution. 
Time complexity :- O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;
int d = 1;
long long find(vector<long long>&A,int k){
    int n = A.size();
    long long  ans = 0;
    long long sum = 0;
    
    for(int i=0;i<k;++i){
        sum+=A[i];
    }
    ans = sum;
   // if(d){
   //     cout<<ans<<" ";
  //  }
    int j = n;
    long long last = 0;
    for(int i=1;i<=k;++i){
        //so we take k elements from begining and 0 from end
        
            sum-=A[k-i];
            last+=A[n-i];
           /// if(d)<<cout<<(n-i)<<" "<<
            ans = max(ans,sum + last);
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int z = 1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        int n;
        cin>>n;
        
        vector<long  long> A(n);
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        int m;
        cin>>m;
        
        vector<long long>B(m);
        for(int i=0;i<m;++i){
            cin>>B[i];
        }
        
        int k;
        cin>>k;
        
        long long ans = 0;
        
        //doing i operations on array A and k-i operations on B
        for(int i=0;i<=k;++i){
            long long val1 = find(A,min(n,i));
            long long val2 = find(B,min(m,k-i));
            ans = max(ans,val1+val2);
        }
        cout<<ans<<"\n";
        
    }
}
