/*
Platform :- Codeforces
Contest :- Codeforce Educational Round 139
Approach :- We will do dfs , if we start from 0,0 -- we can go 'Down' to 1,0 or Right to '0,1' we will try both option and chek if we can visit all the 'B' cell 
           or not . Similarly if we start from 1,0 we can go to UP 0,0 or right 1,1 we will try this two option also .
           We will only move Right ,Down and UP .
 Time Complexity :- O(m*n)
*/
#include<bits/stdc++.h>
using namespace std;

bool find(vector<vector<char>>&ch,int count,char dir,int s,int p,int n){
    
    vector<vector<int>>vis(2,vector<int>(n));
         int f = 0;
        queue<pair<int,int>>bfs2;
        
        bfs2.push({s,p});
        vis[s][p]++;
         int cur = 1;
        
        while(!bfs2.empty()){
            pair<int,int>temp = bfs2.front();
            bfs2.pop();
            int x = temp.first;
            int y = temp.second;
            cur++;
           // cout<<x<<' '<<y<<" "<<dir<<"\n";
            
            //only two options are allowed for me
              
                 if(dir == 'R'){
                    if((x+1)<2){
                        if(ch[x+1][y] == 'B'){
                            if(vis[x+1][y] == 0){
                                vis[x+1][y]++;
                                dir = 'D';
                                bfs2.push({x+1,y});
                                continue;
                            }
                        }
                    }
                    
                    //for left
                    if((x-1)>=0){
                        if(ch[x-1][y] == 'B'){
                            if(vis[x-1][y] == 0){
                                vis[x-1][y]++;
                                dir = 'U';
                                bfs2.push({x-1,y});
                                continue;
                            }
                        }
                    }
                    
                    //I can go IUP or continue rightt
                    if((y+1)<n){
                        if(ch[x][y+1] == 'B'){
                            if(vis[x][y+1] == 0){
                                vis[x][y+1]++;
                                dir = 'R';
                                bfs2.push({x,y+1});
                                continue;
                            }
                        }
                    }
                }
                else if(dir == 'D'){
                    //I can go left or continue Right
                    if((y+1)<n){
                        if(ch[x][y+1] == 'B'){
                            if(vis[x][y+1] == 0){
                                vis[x][y+1]++;
                                dir = 'R';
                                bfs2.push({x,y+1});
                                continue;
                            }
                        }
                    }
                    
                }
                 else{
                    //I can go left or continue Right
                    if((y+1)<n){
                        if(ch[x][y+1] == 'B'){
                            if(vis[x][y+1] == 0){
                                vis[x][y+1]++;
                                dir = 'R';
                                bfs2.push({x,y+1});
                                continue;
                            }
                        }
                    }
                    
                }
            }
        
        
        return cur == count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int s = 0,p = 0;
        int count = 0;
        vector<vector<char>> ch(2,vector<char>(n));
        for(int i=0;i<2;++i){
            for(int j=0;j<n;++j){
                cin>>ch[i][j];
                
                if(ch[i][j] == 'B'){
                    count++;
                }
            }
        } 
          
          if(count <=1 || count == (2*n)){
              cout<<"YES\n";
              continue;
          }
        
        
         int f = 0;
         if(ch[0][0] == 'B'){
             if(ch[1][0] == 'B' ){
                 if(find(ch,count,'D',1,0,n))f = 1;
                 if(find(ch,count,'U',0,0,n))f = 1;
             }
             else{
                 if(n>1 && ch[0][1] == 'B' && find(ch,count,'R',0,1,n))f = 1;
             }
         }
         else{
             if(n>1 && ch[1][1] == 'B' && find(ch,count,'R',1,1,n))f = 1;
             
         }
         
        
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}
