/*
Platform :- Codeforces 
Contest :- Codeforces Round 847 Div 3
Approach :- If you will simplify the problem, 'x' = the xor of (a&b)
            if we can get 'x' from offset bits , all bits that are offset have occurence '0' or '2' times ( one in each 'a' and 'b') 
            so we create array of those values and an array of set bits values too .
            For each offset bit we push them two times as both 'a' and b can have that bit set .Now the main motive is to get ( the set bits value) from
            off set bit array.
            We sort the array and start from the bigger values .If we are able to get the set bit array then we can have pair (A,B) else -1.
            We maintain frequency of used value,
            now if frequency is '2' we add that value to both 'a' and b' else we can add to either.
Time Complexity :- O(log^2 n)
*/
#include<bits/stdc++.h>
using namespace std;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
      long long n;
      cin>>n;
      
      string temp = bitset<32>(n).to_string();
      string z = "";
      int f = 0;
      for(int i=0;i<32;++i){
          if(f){
              z+= temp[i];
          }
          else{
              if(temp[i] == '1'){
                  f=1;
                  z += temp[i];
              }
          }
      }
      temp = z;
      reverse(temp.begin(),temp.end());
      
      vector<long long>avail,req;
      long long a = 0,b = 0;
      for(long long i=0;i<temp.size();++i){
          if(temp[i] == '0'){
              avail.push_back(1ll<<i);
              avail.push_back(1ll<<i);
          }
          else{
              req.push_back(1ll<<i);
              if(a == 0)a += 1ll<<i;
              else{
                  b += (1ll<<i);
              }
          }
      }
       
      int len = avail.size();
      sort(avail.begin(),avail.end());
      sort(req.begin(),req.end());
      map<long long,int>used;
      
      
      int j = req.size()-1;
      int i = avail.size()-1;
      
      while(j>=0 && i>=0){
          if(avail[i]<=req[j]){
              req[j] -= avail[i];
              used[avail[i]]++;
              if(req[j] == 0)j--;
              i--;
          }
          else i--;
      }
       
      
      if(j == -1){
          for(auto&x:used){
              if(x.second == 2){
                  a += x.first;
                  b += x.first;
              }
              else a += x.first;
          }
          cout<<a<<" "<<b<<"\n";
      }
      else cout<<"-1\n";
       
      
    }
}
