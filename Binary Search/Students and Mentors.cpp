/*
Platform :- Coding Competitions with Google
Approach:- We binary serach for the biggest value <= 2*A[i]  for values each A[i] ,
Complexity ;-O( N logN)
*/
#include<bits/stdc++.h>
using namespace std;

long long search(int i,vector<long long>&B){
    long long lim = 2ll;
    lim*=B[i];
    int n = B.size();
    int s = 0,e = n-1,m = (s+e)/2;
    long long ans = -1;
    while(s<=e){
        if(m == i){
            if(i == 0){
               //move to next
               m++;
               s = m;
               if(B[m]<=lim){
                   ans = max(ans,B[m]);
                   s = m+1;
                   m = (s+e)/2;
               }
               else{
                   e = m-1;
                   m = (s+e)/2;
               }
            }
            else if(i == n-1){
                m--;
               e = m;
               if(B[m]<=lim){
                   ans = max(ans,B[m]);
                   s = m+1;
                   m = (s+e)/2;
               }
               else{
                   e = m-1;
                   m = (s+e)/2;
               }
            }
            else{
                //check in right
                if(B[m+1]<=lim){
                    ans = max(ans,B[m+1]);
                    s = m+2;
                    m = (s+e)/2;
                }
                else{
                    if(B[m-1]<=lim){
                        ans = max(ans,B[m-1]);
                        break;
                    }
                    else {
                        e = m-2;
                        m = (s+e)/2;
                    }
                }
            }
        }
        else{
            if(B[m] <= lim){
                ans = max(ans,B[m]);
                s = m+1;
                m = (s+e)/2;
            }
            else{
                e = m-1;
                m = (s+e)/2;
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    
    for(int z =1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        int n;
        cin>>n;
        
        set<long long>P;
        map<long long,int>idx;
        long long A[n];
        vector<long long>B;
        for(int i=0;i<n;++i){
            cin>>A[i];
            B.push_back(A[i]);
  //          P.insert(A[i]);
//            count[A[i]]++;
        }
        sort(B.begin(),B.end());
        for(int i=0;i<n;++i){
            idx[B[i]] = -1;
        }
        
        for(int i=0;i<n;++i){
            if(idx[B[i]] == -1)idx[B[i]] = i;
        }
        vector<long long>ans(n,-1);
        
        for(int i=0;i<n;++i){
            //let us do binary search
            long long val = search(idx[A[i]],B);
            ans[i] = val;
        }
        
        for(auto&x:ans)cout<<x<<" ";
        cout<<"\n";
    }
}
