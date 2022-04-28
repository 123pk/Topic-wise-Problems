/*
Platform :- Leetcode
Approach :- We will maintain a 2d array which will store the min value that we can have if we choose that cell to be in our final path , that value will be the min of 
            max value of all choosen paths till there . If current value of that cell is less than the value we will moving from neighbouring cell then we will not consider
            that path as we have better option.
            
Time complexity :- O(n*m)
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = INT_MAX;
        int val = 0;
        int n = heights.size(),m = heights[0].size();
        vector<vector<int>>cell_effort(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,int>>bfs;
        bfs.push({0,0});
        cell_effort[0][0] = 0;
        
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<int,int>temp = bfs.front();
                bfs.pop();
                int x = temp.first;
                int y = temp.second;
                
                //so we can move in four directions if valid 
                //we will also check the condition that moving to that cell is
                //going to help us in any way or not 
                
                //up
                if((x-1)>=0){
                    val = abs(heights[x][y]-heights[x-1][y]);
                    val = max(val,cell_effort[x][y]);
                    if(val<cell_effort[x-1][y]){
                        cell_effort[x-1][y] = val;
                        bfs.push({x-1,y});
                    }
                }
                
                //left
                if((y-1)>=0){
                    val = abs(heights[x][y]-heights[x][y-1]);
                    val = max(val,cell_effort[x][y]);
                    if(val<cell_effort[x][y-1]){
                        cell_effort[x][y-1] = val;
                        bfs.push({x,y-1});
                    }
                }
                
                //down
                if((x+1)<n){
                    val = abs(heights[x][y]-heights[x+1][y]);
                    val = max(val,cell_effort[x][y]);
                    if(val<cell_effort[x+1][y]){
                        cell_effort[x+1][y] = val;
                        bfs.push({x+1,y});
                    }
                }
                
                //right
                if((y+1)<m){
                    val = abs(heights[x][y]-heights[x][y+1]);
                    val = max(val,cell_effort[x][y]);
                    if(val<cell_effort[x][y+1]){
                        cell_effort[x][y+1] = val;
                        bfs.push({x,y+1});
                    }
                }
                
            }
        }
        
        return cell_effort[n-1][m-1];
    }
};
