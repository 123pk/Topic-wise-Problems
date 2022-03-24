/*
Platform :- Codechef 
Contest :- Codechef Starters 31 
Approach :- So we will use stack to store the index which we are available to fill, all the indexes having '-1' are assigned in stack , now for values >=0 , we will push that
            index in stack too , we will first maintain the set of values from 0 to max value of array , so the first value of set tells us about current mex of our array
            we will assign value if the first value is < B[i] for all indexes having value >= 0.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int B[n],A[n];
        vector<int>count(n+1);
        int f = 0,mx=0;
         int last = -1;
        for(int i=0;i<n;++i){
            cin>>B[i];
            A[i] = B[i];
            mx = max(mx,B[i]);
            if(B[i]>=0){
                if(last<=B[i]){
                    last = B[i];
                    continue;
                }
                else f=1;
                
            }
        }
      //  cout<<f<<" ";
        //we have decreasing array/mex values which is not possible for our array
        if(f){
            cout<<"-1\n";
            continue;
        }
         
         
        for(int i=0;i<n;++i){
           // cout<<c<<" "<<B[i]<<"\n";
            if(B[i]>(i+1)){
                f=1;
                break;
            }
             
        }
        
        
        if(f){
            cout<<"-1\n";
            continue;
        }
        
        stack<int>idx;
        set<int>used;
        for(int i=0;i<=mx;++i){
            used.insert(i);
        }
        
        int val = 0;
        //int A[n];
        for(int i=0;i<n;++i){
            
            if(B[i] == -1){
                idx.push(i);
            }
            else{
                auto it = used.begin();
                 
                if(*it >= B[i]){
                    idx.push(i);
                    continue;
                }
                else{
                    
                    idx.push(i);
                  //  cout<<(i+1)
                    while(!idx.empty()){
                        auto it = used.begin();
                        int val = *(it);
                        
                        if(val>=B[i]){
                            break;
                        }
                        A[idx.top()] = val;
                        idx.pop();
                        used.erase(val);
                    }
                    
                     
                }
                 
            }
        }
        
         
        
        for(int i=0;i<n;++i){
            if(A[i] == -1 || A[i] == B[i])A[i] = 1e9;
        }
        
        for(auto&x:A)cout<<x<<" ";
        cout<<"\n";
        
        
         
    }
}
