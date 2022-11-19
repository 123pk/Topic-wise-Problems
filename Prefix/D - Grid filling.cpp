/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 278
Approach :- We find total number of unique values in whole matrix let it be 'x'.
            Since the values can be upto 300 , I used two prefix array which store the minimum and maximum coloumn and row for each value.
            Now for each of the subarray we count how many values are there which are totally inside this subarray let that be 'c'
            then for each subarray we prinnt (x-c)
 Time Complexity :- O(H*w*N)
*/
#include<bits/stdc++.h>
using namespace std;

bool check(int h,int m){
    int h_t = h/10;
    int h_b = h%10;
    
    int m_t = m/10;
    int m_b = m%10;
    
    swap(h_b,m_t);
    int cur_h = h_t*10  + h_b;
    if(cur_h>23)return false;
    
    cur_h = (m_t*10 + m_b);
    
 
    return cur_h<60;
}
 
int main(){
    int n,m,lim,l,r;
    cin>>n>>m>>lim>>l>>r;
    
    vector<vector<int>>A(n,vector<int>(m));
    set<int>unq;
    vector<pair<int,int>>width(lim+1);
    vector<pair<int,int>>height(lim+1);
    
    for(int i=1;i<=lim;++i){
        width[i] = {-1,-1};
        height[i] = {-1,-1};
    }
    
    
    for(int k=0;k<n;++k){
        for(int j=0;j<m;++j){
            cin>>A[k][j];
            
            unq.insert(A[k][j]);
            int i = A[k][j];
            if(width[i].first == -1){
                width[i] = {j,j};
            }
            else{
                width[i].first = min(width[i].first,j);
                width[i].second = max(width[i].second,j);
            }
            
            if(height[i].first == -1){
                height[i] = {k,k};
            }
            else{
                height[i].first = min(height[i].first,k);
                height[i].second = max(height[i].second,k);
            }
        }
    }
    
    int sz = unq.size();
   // cout<<sz<<"\n";
    
    //now let us move from 
    for(int i=0;i<=(n-l);++i){
        for(int j=0;j<=(m-r);++j){
            int w_lim = j + r-1;
            int h_lim = i + l-1;
            int c = 0;
            for(int k=1;k<=lim;++k){
                int s_w = width[k].first;
                int e_w = width[k].second;
                
                 int s_h = height[k].first;
                int e_h = height[k].second;
                int f = 0,g = 0;
                if(j<=s_w && e_w<=w_lim)f=1;
                if(i<=s_h && e_h<=h_lim)g=1;
                
                if(f&&g){
                    c++;
                  //  cout<<k<<" -- ";
                }
            }
            cout<<(sz-c)<<" ";
        }
        cout<<"\n";
    }
}
