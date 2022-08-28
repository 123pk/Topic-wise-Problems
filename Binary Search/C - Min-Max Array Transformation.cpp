/*
Platform :- Codeforces 
Contest :- Codeforces Educational Round 134 
Approach :- Okay so we have to think greedily in which case are we going to have smallest increment operation ,
            i. For smallest increment values we need to convert A[i] to nearest available B[j] >= A[i] , so we can use binary search on sorted B or lower_bound on set with
               all elements of B.
            ii. For greatest increment value we will find the first value which is B[j] >= A[i] , then from index 'j' to 'i' I can convert each element of A to B[i] , we sort the
                elements of array A in increasing order and start from end (n-1) to (0), So basically for each index we want the max value we can convert our value to .
                Now greaterst increment is (max_value[i] - A[i]),
               
*/
#include<bits/stdc++.h>
using namespace std;

int find(vector<long long>&B,long long val){
    int s = 0,e = B.size()-1,m = (s+e)/2;
    int ans = B.size()-1;
    
    while(s<=e){
        if(B[m]>=val){
            ans = min(ans,m);
            e = m-1;
            m = (s+e)/2;
        }
        else{
            s = m+1;
            m = (s+e)/2;
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
        vector<pair<long long,int>>P;
        for(int i=0;i<n;++i){
            cin>>A[i];
            P.push_back({A[i],i});
        }
        
        vector<long long> B(n);
        long long mx = 0;
       map<long long,int>fre;
       set<long long>avail;
        for(int i=0;i<n;++i){
            cin>>B[i];
           /// fre[B[i]]++;
           avail.insert(B[i]);
            mx = max(mx,B[i]);
        }
        
        
        
        long long mnd[n];
        for(int i=0;i<n;++i){
            auto it = avail.lower_bound(A[i]);
            long long val = *it;
            mnd[i] = val - A[i];
        }
        
        sort(P.begin(),P.end());
        //reverse(P.begin(),P.end());
        int left = n;
        long long curr;
        vector<long long>mxd(n);
        for(int i=n-1;i>=0;--i){
            //auto it = avail.lower_bound()
            //find the index where the value is first time >= this limit
            int idx = find(B,P[i].first);
           // cout<<idx<<" ";
            //mxd[idx] = max(mxd[idx],B[i]);
            if(left>idx){
                if(left>i){
                    left = idx;
                    mxd[idx] = B[i];
                    curr = B[i];
                }
                else{
                    left = idx;
                    mxd[idx] = curr;
                }
            }
         }
         long long cur = 0;
         for(auto&x:mxd){
             cur = max(cur,x);
             x = cur;
         }
         vector<long long>ansd(n);
         for(int i=0;i<n;++i){
             ansd[P[i].second] = (mxd[i] - P[i].first); 
         }
    
        for(auto&x:mnd)cout<<x<<" ";
        cout<<"\n";
        for(auto&x:ansd)cout<<x<<" ";
        cout<<"\n";
    }

}
