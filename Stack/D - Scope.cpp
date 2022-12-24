/*
Platform :- Atcoder 
Contest :- Atcoder Beginner Contest 283
Approach:- We maintain one frequency array of size 26 where 0-->a ,1 -->b ... 25-->z ,
           we will traverse the array and we will push'(' and other alphabets in stack and also maintain frequency count array 
           if frequency count is >1 at any point for any character it is not allowd,
           else if we found ')' we pop out every thing until we find '(' if there is no '(' then also it is not possible to make it emnpty
           else we can always make the string empty
Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;
      cin>>s;
       
      
      int c = 0;
      stack<char>P;
      int n = s.size();
      vector<vector<int>>Q(n,vector<int>(26));
      vector<int>fre(26),count(26);
      
      int f = 0;
      
      for(int i=0;i<s.size();++i){
          if(s[i] == '('){
              P.push(s[i]);
          }
          else if(s[i] == ')'){
               int g = 0;
               while(!P.empty()){
                   if(P.top() == '('){
                       P.pop();
                       g=1;
                       break;
                   }
                   else {
                       int idx = P.top()-'a';
                       count[idx]--;
                       P.pop();
                   }
               }
               if(g == 0){
                   f=1;
                   break;
               }
          }
          else{
              int cur = s[i]-'a';
              if(count[cur]){
                  f=1;
                  break;
              }
              count[cur]++;
              P.push(s[i]);
          }
         
      }
      
      
      if(f == 0){
          
         cout<<"Yes";
      }
      else cout<<"No";
}
