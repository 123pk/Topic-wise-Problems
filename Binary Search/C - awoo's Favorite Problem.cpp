/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 130
Approach :- If you will carefully analyse the problems you will find that 'ab' --> 'ba'  and 'bc' to 'cb'
            this operations is usful for shifting operation . Like we can shift 'b' to 'x' no of positions if we have 'x' consecutive 'a' before 'b'
            --> similarly we can shift 'c' if we have 'x' no of 'b'
            
            Now we will traverse through the string and will find that if the charactes are not equal in both string at 'ith' position then 
            for s[i] = 'a' we can change to 'b' only and that also when we have 'b' just after occurence of 'a'
            similarly for s[i]  = 'b' we can change to 'c' only depending upon its occurence.
            
            For all other cases we cannot perform any operation .
            After performing all the operations we check if we have both string equal or not
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        
        int n;
        cin>>n;
        
        string s,p;
        cin>>s>>p;
        
        //let us store the count of b for each index
        //we will also store the index of occurence of 'a' and 'c' in string 
        set<int>bidx,cidx,aidx;
         
         
        
        for(int i=0;i<n;++i){
            if(s[i] == 'a')aidx.insert(i);
            if(s[i] == 'b')bidx.insert(i);
            if(s[i] == 'c')cidx.insert(i);
        }
        
        //now let us traverse throught the array and check if we can do the change
        //first we can shift 'b' and 'c's ony if they are preceeded by 'a' and 'b' respectively
        
        vector<int>start,end;
        int f = 0;
        for(int i=0;i<n;++i){
            
            if(s[i]==p[i]){
                continue;
            }
            
            //if it is 'a'
            if(s[i] == 'a'){
                //I can change only to 'b'
                if(p[i]!='b')break;
                
                //look for index of b 
                auto it = bidx.lower_bound(i);
                if(it == bidx.end())break;
                
                //I want that 'b'should be preceeded by 'a' only
                int idx = *it;
                auto it2 = cidx.lower_bound(i);
                int idx2;
                if(it2 == cidx.end()){
                    idx2 = n;
                }
                else idx2 = *it2;
                
                if(idx2<idx)break;
                
                //else I am having only a till 'b'
                swap(s[i],s[idx]);
                aidx.erase(i);
                aidx.insert(idx);
                bidx.erase(idx);
                bidx.insert(i);
                 
            }
            else if(s[i] == 'b'){
                //I can replace by 'c' only
                if(p[i]!='c')break;
                
                //this can only happen if 'c' i s preceeded bt 'b' only
                //look for index of b 
                //look for index of b 
                auto it = cidx.lower_bound(i);
                if(it == cidx.end())break;
                
                //I want that 'b'should be preceeded by 'a' only
                int idx = *it;
                auto it2 = aidx.lower_bound(i);
                int idx2;
                if(it2 == aidx.end()){
                    idx2 = n;
                }
                else idx2 = *it2;
                
                if(idx2<idx)break;
                
                //else I am having only a till 'b'
                swap(s[i],s[idx]);
                bidx.erase(i);
                bidx.insert(idx);
                cidx.erase(idx);
                cidx.insert(i);
            }
            else{
                //I cannot do anything
                break;
            }
        }
      //  cout<<s<<"\n"<<p<<"\n";
        
        if(s != p)cout<<"NO\n";
        else cout<<"YES\n";
    }
}
