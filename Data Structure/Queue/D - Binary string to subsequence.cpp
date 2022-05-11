/*
Platform :- Codeforces 
Contest :- Codeforces Round 661 Div 3
Approach :- We will use two deque to store the no of subsequence , first will store the no for "one"(1's) and no for "two"(2's) . now if we are at some ith index
            and if s[i] == '1' then if we have any available '0' the '1' in that subseqence and update the answer too . And if we don't have any '0' available then we
            will have to add new subsequence , basically update 'd' to d+1 , the 'd' show the no of subsequence and update it in deque .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        deque<int>one,zero;
        //then find using deque the required
        vector<int>ans(n);
        int d = 1;
        for(int i=0;i<n;++i){
            if(s[i] == '1'){
                
                if(zero.size() == 0){
                    ans[i] = d;
                    one.push_back(d);
                    d++;
                }
                else{
                    ans[i] = zero.front();
                    one.push_back(zero.front());
                    zero.pop_front();
                }
            }
            else{
                if(one.size() == 0){
                    ans[i] = d;
                    zero.push_back(d);
                    d++;
                }
                else{
                    ans[i] = one.front();
                    zero.push_back(one.front());
                    one.pop_front();
                }
            }
        }
        
        cout<<d-1<<"\n";
        for(auto&x:ans)cout<<x<<" ";
        cout<<"\n";
    }
}
