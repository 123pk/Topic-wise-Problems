/*
Platform :- Codechef
Contest :- Codechef Lunchtime September 2022
Approach :- So the score is the amx differnce between A[i-1] - A[i] for i = 1,n-1.
            We will use set and frequency array using hashmap to store the available differences and the max available non negative difference is our answer.
            We update the difference while adding one element , first we reduce count of previos difference at that position if any and then we do check if we need 
            to remove this diff or not . Then we add new one with increasing frequency.
Time Complexity :- O(n log n) -- > (log n) per query
*/
#include<bits/stdc++.h>
using namespace std;

long long find(vector<long long>&A){
    long long ans = 0;
    int n = A.size();
    long long mx = 0;
    for(int i=1;i<n;++i){
         
        mx = max(mx,A[i-1]-A[i]);
    }
    
    return mx;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,q;
        cin>>n>>q;
        
        vector<long long> A(n);
        set<long long>dif;
        map<long long,int>count;
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(i){
                if(A[i]<A[i-1]){
                    long long change = A[i-1]-A[i];
                    dif.insert(change);
                    count[change]++;
                }
            }   
        }
        
        long long change;
        for(int i=0;i<q;++i){
            int idx;
            long long val;
            cin>>idx>>val;
            idx--;
            
            //get the max value
            if(idx){
                if(A[idx]<A[idx-1]){
                    change = A[idx-1]-A[idx];
                    count[change]--;
                    if(count[change] == 0){
                        dif.erase(change);
                    }
                }
                
                if(val<A[idx-1]){
                    change = A[idx-1]-val;
                    dif.insert(change);
                    count[change]++;
                }
                
                
                if(idx != n-1){
                    if(A[idx]>A[idx+1]){
                        change = A[idx]-A[idx+1];
                        count[change]--;
                        if(count[change] == 0){
                            dif.erase(change);
                        }
                    }
                    
                    if(val>A[idx+1]){
                        change = val - A[idx+1];
                        count[change]++;
                        dif.insert(change);
                    }
                }
            }
            else{
                //for zero only
                if(idx != (n-1)){
                    if(A[idx]>A[idx+1]){
                        change = A[idx]-A[idx+1];
                        count[change]--;
                        if(count[change] == 0){
                            dif.erase(change);
                        }
                    }
                    
                    if(val>A[idx+1]){
                        change = val - A[idx+1];
                        count[change]++;
                        dif.insert(change);
                    }
                }
            }
            
            A[idx] = val;
            if(dif.size() == 0){
                cout<<"0\n";
                continue;
            }
            
            auto it = dif.rbegin();
            long long ans = *it;
            cout<<ans<<"\n";
        }
    }
}
