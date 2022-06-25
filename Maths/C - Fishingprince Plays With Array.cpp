/*
Platform :- Codeforces
Contest :- Codeforces Global Round 21
Approach:- We will first perform operation '1' on array A till the time it is possible , we will maintain two things {value,count} , now we will traverse through array 
           B and will check if we can get the B[i] from P[j] or not . We can only get if B[i]%P[j] == 0 and the required value is power of m , req = B[i]/P[j] , req  = m^b
           else we cannot get that values
Time Complexity = O(n+m)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        long long m;
        cin>>n>>m;
        
        long long A[n];
        
        for(int i=0;i<n;++i){
            cin>>A[i];
             
        }
        
        int k;
        cin>>k;
        
        long long B[k];
        for(int i=0;i<k;++i)cin>>B[i];
        
        
        //basic approach is to modify array A to simplest form and then try to get B from it 
        int f = 0;
        int last = 0;
        vector<pair<long long,long long>>P;
        for(int i=0;i<n;++i){
             
            
            if(i == 0){
                long long val = A[i];
                while(val%m == 0){
                    val/=m;
                }
                
                
                long long count = A[i]/val;
                P.push_back({val,count});
            }
            else{
                long long val = A[i];
                while(val%m == 0){
                    val/=m;
                }
                
                long long count = A[i]/val;
                last = P.size()-1;
                
                if(P[last].first == val){
                    P[last].second += count;
                }
                else{
                    P.push_back({val,count});
                }
            }
        }
        
       /*  for(auto&x:P){
             cout<<x.first<<" "<<x.second<<"\n";
         }
         */
        int j = 0;
        //now we will try to get B from P;
        for(int i=0;i<k;++i){
            if(B[i]%P[j].first){
                //here we cannot do anything to get B[i] from p[J]
                f = 1;break;
            }
            //if values are same then just reduce the count and move to next
            if(B[i] == P[j].first){
                P[j].second--;
                if(P[j].second == 0ll)j++;
            }
            else{
                long long req = B[i]/P[j].first;
                if(req>P[j].second){
                    f = 1;
                    break;
                }
                else{
                    
                    long long check = req;
                    while(check%m == 0){
                        check/=m;
                    }
                    if(check != 1ll){
                        f=1;break;
                    }
                    
                    P[j].second-=req;
                    if(P[j].second == 0ll)j++;
                }
            }
        }
        
        
        if(f || j<P.size())cout<<"No\n";
        else cout<<"Yes\n";
    }
}
