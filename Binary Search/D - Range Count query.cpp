/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 248
Approach :- For each of the values we will store the occurence in set , now we will also maintain an array 'count' which will store the count of 'ith' element at till that
            index (including it) ,  now for each query we will find the first index of occurence in range using 'lower_bound' on set which is same as binary search , 
            and simlary we will do 'lower_bound' of 'r' of range , the no of values are (count[end] - count[start] + 1)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
      
      int A[n];
      unordered_map<int,set<int>>P;
     //this will store the index of each value where they are present
      vector<int>count(n+1);
      //this store the count of value at ith index
      for(int i=0;i<n;++i){
          cin>>A[i];
          P[A[i]].insert(i);
          count[i] = P[A[i]].size();
      }
      
      //now for each query we will find the first and last index of occurence
      //in range  and count is required value
      int q;
      cin>>q;
      set<int>temp;
      
      for(int i=0;i<q;++i){
          int l,r,x;
          cin>>l>>r>>x;
          l--;
          r--;
          temp.clear();
          
          //temp = P[x];
         // cout<<x<<"\n";
         // for(auto&y:temp)cout<<y<<" ";
        //  cout<<"\n";
          //using lowerbound we will find the fisrt and last occurencde of value x
          auto it1 = P[x].lower_bound(l);
          
          if(it1 == P[x].end() || *it1>r)cout<<0<<"\n";
          else{
              int left = *it1;
              auto it2 = P[x].lower_bound(r);
              if(it2 == P[x].end() || *it2>r )it2--;
              int right = *it2;
             // cout<<left<<" "<<right<<"\n";
              cout<<(count[right]-count[left]+1)<<"\n";
          }
      }
}
