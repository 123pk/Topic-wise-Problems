/*
Platform :- Codeforces
Contest :- Codeforces Round 791
Approach :- For query of type '3' , we can acheive that if and only if we have atleast one rook in all the row from 'x1' to 'x2' or in all columns from 'y1' to 'y2'
            we can do that query in log(n) using 'Policy Based Data structure' in C++ by 'Ordered Set' , which gives no of values strictly smaller than current value
            in 'log(n)' , if we have (x2-x1) = order_of_key(x2) - order_of_key(x1) same for columns , but those rows and columns must be present in ordered set 
            ---> We will also maintain frequency of each row and each column it will help us in removing elemnet form set .
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        
        //I want to maintain two map which will store the frequency of each rowwhere rook is present 
        //each column where it is presnt 
        //we will also use a set to do lower_bound in them
        ordered_set P;
        ordered_set Q;
        unordered_map<int,int>rcount,ccount;
        
        for(int i=1;i<=q;++i){
            int c;
            cin>>c;
            
            if(c == 1){
                int x,y;
                cin>>x>>y;
                
                // while inserting the rook
                rcount[x]++;
                ccount[y]++;
                if(rcount[x] == 1)P.insert(x);
                if(ccount[y] == 1)Q.insert(y);
                
            }
            else if(c == 2){
                int x,y;
                cin>>x>>y;
                
                //removing the rook
                rcount[x]--;
                ccount[y]--;
                
                if(rcount[x] == 0)P.erase(x);
                if(ccount[y] == 0)Q.erase(y);
            }
            else{
                //now using binary search /lower_bound of set we will check if it can be attacked or not
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                
                 
                
                 
                if(rcount[x1] && rcount[x2]){
                    int req = x2-x1;
                
                    int have = P.order_of_key(x2)-P.order_of_key(x1);
                    if(have == req){
                       cout<<"Yes\n";
                       continue;
                    } 
                }
                
                
                if(ccount[y1] && ccount[y2]){
                    int req = y2-y1;
                    int have = Q.order_of_key(y2)-Q.order_of_key(y1);
                    if(have == req){
                       cout<<"Yes\n";
                       continue;
                    }
                
                }
                cout<<"No\n";
            }
        }
    }
}
