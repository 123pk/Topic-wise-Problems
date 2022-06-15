/*
Platform :- Codechef
Contest :- Codechef Starters 43
Approach :- We want to make the and of all values to '0' , so we start with max value and get back to 1, from n ---> 1 , we will mark the values already used using set
            now find the bitwise representation of current value 'i' and find the biggest value with which '&' is '0' and choose that value .
            if n is odd then except for '1' all other odd values donot have any solution.
*/
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        if(n == 1){
            cout<<1<<"\n"<<1<<"\n";
        }
        else if(n%2)cout<<"-1\n";
        else{
            //basic approach is to get 0
            vector<int>first;
            map<int,int>value;
            set<int>used;
            for(int i=1;i<=n;++i){
                first.push_back(i);
            }
            
            //now the permutaition
            
            for(int i=n;i>=1;--i){
                
                if(used.size() && used.find(i)!=used.end())continue;
                
                //map with correspondig value
                string temp = bitset<32>(i).to_string();
                reverse(temp.begin(),temp.end());
                int lb;
                //find the last bit
                for(int j=0;j<32;++j){
                    if(temp[j]-'0'){
                        lb = j;
                    }
                }
                int val = 0;
                for(int j=0;j<lb;++j){
                    if(temp[j] == '0'){
                        val+=(1<<j);
                    }
                }
                used.insert(i);
                used.insert(val);
                value[i] = val;
                value[val] = i;
            }
            
            for(auto&x:first)cout<<x<<" ";
            cout<<"\n";
            for(auto&x:first)cout<<value[x]<<" ";
            cout<<"\n";
           
        }
    }
} 
