/*
Contest :- leetcode Weekly contest 323
Approach with detailed explanation:- https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/solutions/2899740/simple-greedy-bfs-c-priority_queue-omn-log-mn/
Time Complexity :- O(m*n log m*n)
*/
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        //I start the dfs and find the score and also the limiting factor
        
        vector<int>temp = queries;
        sort(temp.begin(),temp.end());
        
        map<int,int>sol;
        //{i,j} , score
        int value = grid[0][0];
        priority_queue<pair<int,pair<int,int>>>bfs;
        bfs.push({value,{0,0}});
        int j = 0;
        
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        vis[0][0]++;
         
        vector<int>path;
        
        while(!bfs.empty()){
             int c = bfs.size();
              
                 pair<int,pair<int,int>>cur = bfs.top();
                 bfs.pop();
                 
                 int x = cur.second.first;
                 int y = cur.second.second;
                 int val = abs(cur.first);
                 
                 path.push_back(val);
                 
                 //move in all the four direction
                 if((x-1)>=0){
                     if(vis[x-1][y] == 0){
                         vis[x-1][y]++;
                         int cur_val = grid[x-1][y];
                         bfs.push({-cur_val,{x-1,y}});
                     }
                 }
                 
                 if((x+1)<n){
                     if(vis[x+1][y] == 0){
                         vis[x+1][y]++;
                         int cur_val = grid[x+1][y];
                         bfs.push({-cur_val,{x+1,y}});
                     }
                 }
                 
                 if((y-1)>=0){
                     if(vis[x][y-1] == 0){
                         vis[x][y-1]++;
                         int cur_val = grid[x][y-1];
                         bfs.push({-cur_val,{x,y-1}});
                     }
                 }
                 
                 if((y+1)<m){
                     if(vis[x][y+1] == 0){
                         vis[x][y+1]++;
                         int cur_val = grid[x][y+1];
                         bfs.push({-cur_val,{x,y+1}});
                     }
                 }
             
        }
         
        
        //jo small me hai woh big me honge hi
        int count = 0;
        for(int i=0;i<path.size();){
           // cout<<path[i]<<" ";
            if(temp[j]>path[i]){
                count++;
                if(i == path.size()-1){
                    sol[temp[j]] =  count;
                }
                i++;
            }
            else{
                sol[temp[j]] = count;
                j++;
            }
            if(j == temp.size())break;
        }
        
        while(j<temp.size()){
            sol[temp[j]] = count;
            j++;
        }
        
        vector<int>ans;
        for(auto&x:queries){
            ans.push_back(sol[x]);
        }
        return ans;
    }
};
