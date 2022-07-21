/*
Platform :- Codechef
Contest :- Codechef Starters 48
Approach :- We will maintain list for each value from '1' to 'n' and store the values at the index given in 'm' instructions, we will contsturct our array backwards from 
            n to 1, we will check if there is any list for 'i' value or not if there is a value we will store it in max_heap or we can use set of negative values as this will
            also give max values in log(n) time . Now we will initialise 'i' with the max value we have .
            --> Solution is not possible for case where our heap or set becomes empty and we have some index to fill.
Time Complexity :- O(n * log(n)) 
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        set<int>avail;
        for(int i=1;i<=n;++i)avail.insert(-i);
        
        vector<set<int>>P(n+1);
        vector<int>count(n+1);
        vector<int>zz;
        for(int i=1;i<=m;++i){
            int val,idx;
            cin>>val>>idx;
            if(P[idx].size() == 0)count.push_back(idx);
            P[idx].insert(-val);
            
            if(avail.find(-val)!=avail.end())avail.erase(-val);
        }
        int sum = 0,f = 0;
        
        sort(count.begin(),count.end());
        
        for(int i=0;i<count.size();++i){
            
            sum += P[count[i]].size();
            if(sum>count[i]){
                f=1;
                break;
            }
        }
        
        if(f){
            cout<<"-1\n";
            continue;
        }
        int m1 = count.size();
        if(count[m1-1] != n){
            count.push_back(n);
            m1++;
        } 
        
        for(auto&x:avail)P[n].insert(x);
        avail.clear();
        
        int i = n;
        set<int>temp;
        vector<int>ans;
        int j = m1-1;
        
        while(i>=1){
            //we will move and assign values
            if(i == count[j]){
                
                //what will we do 
                //we will fill the values in set
               
                for(auto&x:P[i])avail.insert(x);
                
                //store the max value availabe to current index
                auto it = avail.begin();
                ans.push_back(abs(*it));
                avail.erase(it);
                j--;
                
            }
            else{
                auto it = avail.begin();
                ans.push_back(abs(*it));
                avail.erase(it);
            }
            i--;
            
        }
        
        reverse(ans.begin(),ans.end());
        
        for(auto&x:ans)cout<<x<<" ";
        cout<<"\n";
        
        
        
    }
}
