/*
Platform :- Codeforces
Contest :- Codeforces Contest 847 Div 3
Approach :- We will store the frequency of count of each value and store all values in set too ,
            now we perform the following operation until the set becomes empty :- 
               - we traverse through the set starting with the first value and get traverse through consecutive values 
               - decrease their frequency , if frequency becomes 0 we store in some vector 
               - erase all the elements of vector from set
               - increse our count by 1
Time Complexity :- O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;
       
       set<long long>unq;
       
       map<long long,int>P;
       long long A[n];
       for(int i=0;i<n;++i){
           cin>>A[i];
           P[A[i]]++;
           unq.insert(A[i]);
       }
       int ans = 0;
       while(!unq.empty()){
           //get what uou can get
           auto it = unq.begin();
           vector<long long>temp;
           long long last = *it;
           ans++;
           for(auto&x:unq){
               if(x == last){
                   if(P[last] == 1){
                       temp.push_back(last);
                   }
                   P[x]--;
                   last++;
               }
               else{
                   break;
               }
           }
           
           for(auto&x:temp){
               unq.erase(x);
               //P[x]--;
           }
           temp.clear();
       }
       
        cout<<ans<<"\n";
    }
}
