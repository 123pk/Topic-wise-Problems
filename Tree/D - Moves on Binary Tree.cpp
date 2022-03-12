/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 243
Approach :- If you will try to use bruteforce operations then you will face long long range over flow , So you should compress as possible , 'U' is very helpful it undo any move 
           of 'L' or 'R' so we will maitain a stack and push 'L' or 'R' in it  , if we have a empty stack and we get 'U' then we decrease the value/index of node by half, else we
           pop top element of stack . Now we will get the string from the stack and perform the operations as it will not overflow now .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long x;
    cin>>x;
    
    string s;
    cin>>s;
    
    //when we go to parent the value is decreased to half
    long long ans = x;
    stack<char>P;
    for(int i=0;i<n;++i){
        if(P.size()==0){
            if(s[i]=='U'){
                ans = max(1ll,(ans>>1ll));
                continue;
            }
            else{
                P.push(s[i]);
            }
        }
        else{
            if(s[i] == 'U')P.pop();
            else{
                P.push(s[i]);
            }
        }
    }
    
    string temp = "";
    while(!P.empty()){
        temp+=P.top();
        P.pop();
    }
    reverse(temp.begin(),temp.end());
    
    for(int i=0;i<temp.size();++i){
        ans = (ans<<1ll);
        if(temp[i] == 'R')ans+=(1ll);
    }
    
    cout<<ans<<"\n";
}
