/*
Platform :- Codechef
Contest :- Codechef Starters
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         string s;
         cin>>s;
         
         string temp = s;
         reverse(temp.begin(),temp.end());
         int ans = s.size()-1;
         
          int n = s.size();
         if(s==temp){
             cout<<ans<<"\n";
             continue;
         }
         int z = 0,idx=-1;
         //cout<<"* ";
         string one="",two="";
         for(int i=0;i<temp.size();++i){
           if(temp[i]!=s[i]){
               z = (n-i);
               idx = i;break;
           }
            
         }
         ans = min(ans,z);
         //cout<<ans<<" ";
          one="",two="";
         //if it is of for OX -->XO it is better to swap O
        // vector<sting>start,end;
         for(int i = 0;i<n;++i){
             if(i==0){
                 one+=temp[i];
                 two+=temp[i];
             }
             else{
                 one+=temp[i];
                 two=temp[i]+two;
             }
             if(one==two){
                 ans =min(ans,(n-(i+1)));
             }
            // cout<<one<<" "<<two<<"\n";
         }
        // cout<<ans<<" "<<sz<<"\n";
         if(idx!=-1){
             int sz = z;
         one="",two="";
         for(int i = idx;i<n;++i){
             if(i==0){
                 one+=temp[i];
                 two+=temp[i];
             }
             else{
                 one+=temp[i];
                 two=temp[i]+two;
             }
             if(one==two){
                 ans =min(ans,(sz-(i+1)));
             }
          //   cout<<one<<" "<<two<<"\n";
         }
         
         }
         cout<<ans<<"\n";
    }
}
