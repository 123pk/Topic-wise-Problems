/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 243
Approach :- For collision we need two things ,
            1. Y coordinate of both the Persons need to be same
            2. Person with smaller coordinate should move to 'R'(right)  and Person with larger coordinate should move to 'L'(left)
            So we will use two 'map' in C++ and 
               i. one to store the range of values (x - coordinate) of persons moving left.
              ii. second one to store the range of values (x - coordinate) of person moving right.
            Now we will check for each value of 'y' if (largest value of coordinate moveing left )> smallest value of coordinate moving right or not . and that is our answer.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    long long x,y;
    map<long long,pair<long long,long long>>left,right;
    vector<pair<long long ,long long>>P;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        P.push_back({x,y});
    }
    
    string s;
    cin>>s;
    map<long long,int >l,r;
    for(int i=0;i<n;++i){
        if(s[i]=='L'){
            if(l[P[i].second]==0){
                l[P[i].second]++;
                left[P[i].second] = {P[i].first,P[i].first};
            }
            else{
                left[P[i].second].first = min(left[P[i].second].first,P[i].first);
                left[P[i].second].second = max(left[P[i].second].second,P[i].first);
            }
        }
        else{
            if(r[P[i].second]==0){
                r[P[i].second]++;
                right[P[i].second] = {P[i].first,P[i].first};
            }
            else{
                right[P[i].second].first = min(right[P[i].second].first,P[i].first);
                right[P[i].second].second = max(right[P[i].second].second,P[i].first);
            }
        }
    }
    
    //for each value we will look if there is a value in right corrensponding to this
    int f = 0;
    set<long long>z;
    
    for(int i=0;i<n;++i){
        if(s[i]=='L'){
            //I want a value with left coordinate
            if(r[P[i].second]){
                if(right[P[i].second].first<P[i].first){
                    f=1;break;
                }
            }
        }
        else{
            if(l[P[i].second]){
                if(left[P[i].second].second>P[i].first){
                    f=1;break;
                }
            }
        }
    }
    
    if(f)cout<<"Yes\n";
    else{
        cout<<"No\n";
    }
         
}
