/*
Platform :- Codeforces
Contest :- Codeforces Round 776 Div 3
Approach :- Find our the smalesst (2*n) weights and correspoinding coordinates , now sort the coordinates and map 'i' coordinate with '(2*n-i)' coordinate for 1 based indexing
*/
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<pair<long long,long long>,int>&P,pair<pair<long long ,long long>,int>&Q){
    if(P.first.second == Q.first.second){
        return P.first.first<Q.first.first;
    }
    return P.first.second<Q.first.second;
}

bool comp2(pair<long long ,int>&P,pair<long long,int>&Q){
    return P.first<Q.first;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,m;
         cin>>n>>m;
         
         long long x,y;
         long long tot = 0;
         vector<pair<pair<long long,long long>,int>>P;
         for(int i=0;i<m;++i){
             cin>>x>>y;
             P.push_back({{x,y},i+1});
         }
         
         sort(P.begin(),P.end(),comp);
         vector<pair<long long,int>>values;
         
         for(int i=0;i<2*n;++i){
             tot+=P[i].first.second;
             values.push_back({P[i].first.first,P[i].second});
         }
         cout<<tot<<"\n";
         sort(values.begin(),values.end(),comp2);
         for(int i=0;i<n;++i){
             cout<<values[i].second<<" "<<values[(2*n-1)-i].second<<"\n";
         }
         cout<<"\n";
    }
}
