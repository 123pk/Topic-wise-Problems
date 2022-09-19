/*
Platform :- Leetcode
Approach :- We will do bfs greedily / similary to dijkstra , we will sift the empty cell (cell wth value '0') to neighbouring ones , we also maintain one set which store 
             the state , we don't want to get back to same state again .
            So the first time we get the desired state we run out of loop and that is our answer.
Time Complexity :- O(n*m*6!)
*/
class Solution {
public:
    
    bool check(vector<vector<int>>&mat){
        for(int i=0;i<3;++i){
            if(mat[0][i] != (i+1))return false;
        }
        
        if(mat[1][0] != 4)return false;
        if(mat[1][1] != 5)return false;
        if(mat[1][2] != 0)return false;
        return true;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        //so we can starti with bfs 
        //we have multiple optioin for movement 
        //we want the box to come at the last position
        
        //we will use priority_queue sorted by no of moves
        priority_queue<pair<int,pair<pair<int,int>,vector<vector<int>>>>>bfs;
        set<pair<pair<int,int>,vector<vector<int>>>>used;
        
        //we have { no_of_moves,{position,board}}
        int start = 0,end = 0;
        for(int i=0;i<2;++i){
            for(int j=0;j<3;++j){
                if(board[i][j] == 0){
                    bfs.push({0,{{i,j},board}});
                }
            }
        }
        int ans = -1;
        vector<vector<int>>matrix,temp;
        while(!bfs.empty()){
            
            pair<int,pair<pair<int,int>,vector<vector<int>>>> tmp = bfs.top();
            bfs.pop();
            
            int moves = abs(tmp.first);
            int x = tmp.second.first.first;
            int y = tmp.second.first.second;
            matrix = tmp.second.second;
            
            //check the state
            if(check(matrix)){
                ans = moves;
                break;
            }
            
            if(used.size() == 0){
                used.insert(tmp.second);
            }
            else if(used.find(tmp.second) != used.end())continue;
            else used.insert(tmp.second);
            
            
            //what options do I have
            if((x+1)<2){
                //move the cell 0 there 
                temp = matrix;
                swap(temp[x+1][y],temp[x][y]);
                bfs.push({-(moves+1),{{x+1,y},temp}});
                //moved down
            }
            
            //move up
            if((x-1) >= 0){
                //move the cell 0 there 
                temp = matrix;
                swap(temp[x-1][y],temp[x][y]);
                bfs.push({-(moves+1),{{x-1,y},temp}});
                //moved down
            }
            
            //move left
            if((y-1)>=0){
                //move the cell 0 there 
                temp = matrix;
                swap(temp[x][y-1],temp[x][y]);
                bfs.push({-(moves+1),{{x,y-1},temp}});
                //moved down
            }
            
            //move right
            if((y+1)<3){
                //move the cell 0 there 
                temp = matrix;
                swap(temp[x][y+1],temp[x][y]);
                bfs.push({-(moves+1),{{x,y+1},temp}});
                //moved down
            }
        }
        
        return ans;
    }
};
