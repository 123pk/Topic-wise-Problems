/*
Platform :- Codeforces
Contest :- Educational Round 125
Appraoch :- You need to carefully read the problem , So we have two challenges 
            1. How to optimally find if we have regular bracket from current sequence or not and if yes then till where
            2. How to find smallest palindromic prefix from current index 
            
            For '2' option you can analyse that if current character is '(' then required palindromic string is from current character to next occurence of current character
            For option 1 we can use a stack and prefix array , every time we found '(' we will push in stack with index and next time when we found ')' we will pop it out
            and store at the index of poped character the value of current index that will store we are having regular sequence from this 'ith' index to pref[i] , 
            now we will start from first index and we will try to find the smallest index from current index where we have either of one type of good substring .
*/
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        //I know how to find palindromic sbustring in O(logn)
        vector<int>start,end,pref(n);
        stack<pair<char,int>>P;
        int c = 0,f=0;
        for(int i=0;i<n;++i){
            if(s[i] == '('){
                P.push({s[i],i});
                start.push_back(i);
            }
            else{
                if(!P.empty()){
                    if(P.top().first == '('){
                        pref[P.top().second] = i;
                        P.pop();
                    }
                }
                end.push_back(i);
            } 
        }
        
        //so I can use lowerbound to find 
        int ans = 0,last = 0;
        char ch = s[0];
        while(last<n){
            int temp = n;
            int f = 0,g= 0;
            ch = s[last];
            //check for palindrome
            if(ch == '('){
                auto it = lower_bound(start.begin(),start.end(),last+1);
                if(it == start.end()){
                    //we cannot move forward
                    g=1;
                }
                else{
                    temp = min(temp,*it);
                }
            }
            else{
                auto it = lower_bound(end.begin(),end.end(),last+1);
                if(it == end.end()){
                    //we cannot move forward
                    g=1;
                }
                else{
                    temp = min(temp,*it);
                }
            }
            //check for regular
            
            if(pref[last]){
                temp = min(temp,pref[last]);
            }
            else{
                f=1;
            }
            if(f && g)break;
            //choose the min
            
            //if nothing is possible break
            ans++;
            last = temp;
            last++;
        }
        
        cout<<(ans)<<" "<<(n-last)<<"\n";
        
    }
}
