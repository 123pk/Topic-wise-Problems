/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 245
Approach :- We have a poynomial Sequence A and B , the product of those is C , We are given A and C and we want to find 'C' , so we can get that by simplifying the given
            information , like for Cn+m = A[n]*B[m] , we can get B[m] from here , similarly for Cn+m-1 = A[n-1]*B[m] + A[n]*B[m-1] , since we already know values of all the
            values ( Cn+m-1 , A[n] , A[n-1] and B[m]) hence we can find B[m-1] , similarly we can get for all the other values . We will start form last value because it is 
            guaranteed that those values cannot be '0' for all test cases .
*/
#include<bits/stdc++.h>
using namespace std;

//vector<int>dp[100001];
 

int main(){
     int n,k;
     cin>>n>>k;
     n++;
     k++;
     int m = n+k-1;
      
     vector<long long>A(n),C(m);
     for(int i=0;i<n;++i){
         cin>>A[i];
     }
     
     for(int i=0;i<m;++i){
         cin>>C[i];
     }
     reverse(C.begin(),C.end());
     reverse(A.begin(),A.end());
    // int k = m-n;
     vector<long long>B(k,INT_MIN);
     B[0] = C[0]/A[0];
  //   else B[0] = 0;
     for(int i=1;i<m;++i){
         long long z = 0;
         int idx = -1;
         long long tot = 0;
         for(int l = 0;l<=i;++l){
             int dif = i-l;
             if((l<n) && dif<k){
                 if(B[dif] == INT_MIN){
                     z = A[l];
                     idx = dif;
                 }
                 else{
                     tot+=(A[l]*B[dif]);
                 }
             }
         }
       //  cout<<idx<<" "<<C[i]<<" "<<tot<<" "<<z<<endl;
         if(idx>=0)  B[idx] = (C[i]-tot)/z;
             
         //}
     }
     reverse(B.begin(),B.end());
     for(auto&x:B)cout<<x<<" ";
     cout<<"\n";
}
