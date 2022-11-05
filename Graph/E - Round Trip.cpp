/*
Platform :- Atcoder 
Contest :- Atcoder Beginner Contest 276
Approach :- We start dfs from 'S' starting poitn and maintain one vis array so we don't visit the cell already visited , 
            if we reach to the starting point after some moves such that no of moves>d , then we print yes else no
Time Complexity :- O(n*m)
*/
#include<bits/stdc++.h>
using namespace std;

void find(int i,int j,int x,int y,vector<vector<char>>&ch,int d,int n,int m,int&f,vector<vector<int>>&vis){
   //cout<<(i+1)<<" "<<(j+1)<<" "<<d<<"\n";
    vis[i][j]++;
    //I an move in 4 directions
    d++;
    if((i-1)>=0){
        if(d>=4){
            //check if its valid
            if((x == i-1)&&(j == y)){
            //    cout<<" * "<<(i+1)<<" "<<(j+1)<<"\n";
                f=1;return;
            }
        }
       if(vis[i-1][j] == 0) find(i-1,j,x,y,ch,d,n,m,f,vis);
    }
    
    if((i+1)<n){
        if(d>=4){
            //check if its valid
            if((x == i+1)&&(j == y)){
            //    cout<<" ** "<<(i+1)<<" "<<(j+1)<<"\n";
                f=1;return;
            }
        }
        if(vis[i+1][j] == 0)find(i+1,j,x,y,ch,d,n,m,f,vis);
    }
    
    if((j-1)>=0){
        if(d>=4){
            //check if its valid
            if((x == i)&&(j-1 == y)){
            //   cout<<" # "<<(i+1)<<" "<<(j+1)<<"\n";
                f=1;return;
            }
        }
       if(vis[i][j-1] == 0) find(i,j-1,x,y,ch,d,n,m,f,vis);
    }
    
    if((j+1)<m){
        if(d>=4){
            //check if its valid
            if((x == i)&&(j+1 == y)){
             //   cout<<" ## "<<(i+1)<<" "<<(j+1)<<"\n";
                f=1;return;
            }
        }
        if(vis[i][j+1] == 0)find(i,j+1,x,y,ch,d,n,m,f,vis);
    }
    
}

int main(){
      
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>vis(n,vector<int>(m));
    vector<vector<char>> ch(n,vector<char>(m));
    pair<int,int>start;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>ch[i][j];
            if(ch[i][j] == 'S'){
                start = {i,j};
            }
            if(ch[i][j] == '#')vis[i][j]++;
        }
    }
    
    //now what to do
    //let us start dfs from the point I didn't visited
    //If I reach to the start then its  a yes
    int f = 0;
    
    find(start.first,start.second,start.first,start.second,ch,0,n,m,f,vis);
    
    
    if(f)cout<<"Yes";
    else cout<<"No";
     
}
