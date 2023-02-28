/*
Platform :- Codeforces
Contest :- Codeforces Educational ROund 144
Approach :- We need to check for three things
           1. If first element is equal or last element is equal
           2. If there is any subarray of size 2 that is in both 
           if any of this condition is satisfied then solution exist .
 Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

bool check(string&s,string&p,string& ans){
    int i=0,j = 0,c = 0;
    for(int i=1;i<s.size();++i){
        string temp ="";
        temp += s[i-1];
        temp += s[i];
        for(int j = 1;j<p.size();++j){
            string temp2 = "";
            temp2 += p[j-1] ;
            temp2 += p[j];
            if(temp[0] == temp2[0] &&  temp[1] == temp2[1]){
                ans = temp;
                return true;
            }
        }
    }
    
    return false;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string a,b;
        cin>>a>>b;
        
        int n = a.size();
        int m = b.size();
         
        int equal = 0,last = 0;
        int idx = 0;
        string ans = "";
        //I jjust need two consecutive
        if(a[0] == b[0]){
            cout<<"YES\n";
            cout<<a[0]<<"*\n";
        }
        else if(a[n-1] == b[m-1]){
            cout<<"YES\n";
            cout<<"*"<<a[n-1]<<"\n";
        }
        else if(check(a,b,ans)){
            cout<<"YES\n";
            cout<<"*"<<ans<<"*\n";
        }
        else if(check(b,a,ans)){
            cout<<"YES\n";
            cout<<"*"<<ans<<"*\n";
        }
        else cout<<"NO\n";
    }
}
