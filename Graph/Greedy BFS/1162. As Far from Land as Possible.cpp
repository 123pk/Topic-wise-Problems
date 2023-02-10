/*
Platform :- Leetcode
Approach :- We maintain one 2d- matrix which store the smallest distance of that cell (i,j) from any land ,
            for all the land it will be '0'
            else we initialise to "infinity" for all the cell initally.
            Now whenever we have any land cell , we start bfs from there and move to neighbouring water cells only if 'cost' or smallest distance [i,j] < cur_cost+1 .
            In this way we find the smallest value for each of the cell .
Time Complexity :- O(n*m)
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>score(n,vector<int>(m,INT_MAX));
        int ans = -1;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1){
                    score[i][j] = 0;
                    int cur = 0;
                    queue<pair<pair<int,int>,int>>bfs;
                    bfs.push({{i,j},0});

                    while(!bfs.empty()){
                       
                       pair<pair<int,int>,int> temp = bfs.front();
                       bfs.pop();
                       int l = temp.first.first;
                       int r = temp.first.second;
                       int cost = temp.second;

                       if(l-1>=0){
                          if(grid[l-1][r] == 0){
                              if(score[l-1][r] > (cost+1)){
                                 score[l-1][r] = cost+1;
                                 bfs.push({{l-1,r},cost+1});
                              }
                           }
                        }

                        if(l+1<n){
                          if(grid[l+1][r] == 0){
                              if(score[l+1][r] > (cost+1)){
                                 score[l+1][r] = cost+1;
                                 bfs.push({{l+1,r},cost+1});
                              }
                           }
                        }

                        if(r+1<m){
                          if(grid[l][r+1] == 0){
                              if(score[l][r+1] > (cost+1)){
                                 score[l][r+1] = cost+1;
                                 bfs.push({{l,r+1},cost+1});
                              }
                           }
                        }

                        if(r-1>=0){
                          if(grid[l][r-1] == 0){
                              if(score[l][r-1] > (cost+1)){
                                 score[l][r-1] = cost+1;
                                 bfs.push({{l,r-1},cost+1});
                              }
                           }
                        }
                    }
                    
                }
            }
        }

        for(auto&x:score){
            for(auto&y:x){
                if(y == 0)continue;
               if(y != INT_MAX)ans = max(ans,y);
            }
           // cout<<"\n";
        }

        return ans;
    }
};
