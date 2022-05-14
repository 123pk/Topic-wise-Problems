/*
Platform :- Codeforces
Contest :- Codeforces Round 791
Approach :- We will use greedy algorithm here ,
         --> So we use a flag to check if we have use any operation of type '2' till now or not , we will also maintain a set which will store indexes which are changed
         --> if we have not used then it is easy we just update the  ' total_sum  += (value - A[idx] ) ' 
         --> if we have used type '2' then we will erase all the values in set storing changed index and update 'total_sum = n*value'.
         --> we will maintain a variable that will store the last value of type '2' operation . 
         --> while performing type '1' operation when we have performed type '2' in past , we check if current index is changed or not ,
             if not we change the value to 'last_value_type2' and update the total_sum ,  else we compare with updated sum 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        
        long long A[n];
        long long tot = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            tot+=A[i];
        }
        int f = 0;
        long long last = 0;
        set<int>changed;
        //changed store the index which need to be change
        
        //now what we can do 
        for(int i = 0;i<q;++i){
            int x;
            cin>>x;
            if(x == 1){
                int idx;
                long long val;
                cin>>idx>>val;
                idx--;
                
                //if we have already changed this 
                if(f){
                    if(changed.size()){
                        //so we have not perfom any change operation after task 2 then it remains same
                        if(changed.find(idx) == changed.end()){
                            tot+=(val-last);
                            A[idx] = val;
                            changed.insert(idx);
                        }
                        else{
                            tot+=(val-A[idx]);
                            A[idx] = val;
                        }
                    }
                    else{
                        changed.insert(idx);
                        tot+=(val-last);
                        A[idx] = val;
                    }
                }
                else{
                    tot+=(val-A[idx]);
                    A[idx] = val;
                }
                cout<<tot<<"\n";
            }
            else{
                changed.clear();
                long long val;
                cin>>val;
                f = 1;
                last = val;
                tot = n;
                tot*=val;
                cout<<tot<<"\n";
            }
        }
    }
}
