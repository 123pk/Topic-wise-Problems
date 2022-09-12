/*
Platform :- Codeforces
Contest :- Codeforces Round 819 Div 3
Approach :- First we will find new array C[i] =  B[i]-A[i] for all values , now we need to find max number of subset such that their sum >=0 . 
             We will maitain two arrays or heap seperately we will use min heap and max heap , for smallest postive value we will look for smallest -ve value such that sum is
            greater than >= 0 
            If there is no such negative value then we will take one smallest positive value just greater than this and pair it with.
Time Complexity :- O(n * log n)
*/
#include<bits/stdc++.h>
using namespace std;

//increasing order
bool comp1(pair<int,int>&P,pair<int,int>&Q){
    if(P.first == Q.first){
        return P.second<Q.second;
    }
    return P.first<Q.first;
}

//decreaseing order
bool comp2(pair<int,int>&P,pair<int,int>&Q){
    if(P.first == Q.first){
        return P.second<Q.second;
    }
    return P.first>Q.first;
}



int main(){
    int t;
    cin>>t;
    
    while(t--){
          int n;
          cin>>n;
          
          long long A[n];
          long long B[n],P[n];
          priority_queue<long long>pos,neg;
          for(int i=0;i<n;++i)cin>>A[i];
          for(int i=0;i<n;++i){
              cin>>B[i];
              long long val = B[i]-A[i];
              if(val>=0)pos.push(-val);
              else neg.push(val);
             // cout<<val<<" ";
          }
        //  cout<<"\n";
          int ans = 0;
          
          while(!pos.empty()){
              long long temp = abs(pos.top());
              pos.pop();
              //cout<<temp<<" "<<endl;
              if(neg.empty()){
               //   cout<<"*"<<endl;
                  if(pos.empty())break;
                  else{
                      ans++;
                      pos.pop();
                  }
              }
              else{
                  
                   
                  if(neg.empty()){
                    if(pos.empty()){
                        break;
                    }  
                    else{
                        pos.pop();
                        ans++;
                    }
                  }
                  else{
                    long long temp2 = abs(neg.top());
                    if(temp2>temp){
                        //select any positive value
                        if(pos.empty())break;
                        else {
                            ans++;
                            pos.pop();
                        }
                    }
                    else {
                        ans++;
                        neg.pop();
                    }
                    
                  }
              }
          }
          
          cout<<ans<<"\n";
    }
}
