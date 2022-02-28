/*
Platform :- Leetcode
Approach :- Binary search on values from 0 to size - 1 , We will check for each of the (start+end)/2 , if it is possible to cross then we will update the answer and binary search on
            value from (mid,end) else we binary search on value from (strat,mid).
            
            We will use BFS to find if it is possible to cross or not.
*/
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        //Since the value of ans is in range from one to cells.size()
        // we can perform binary search
        
        int ans = 0;
        int start = 0,end = cells.size()-1 , mid = (start+end)/2;
         
        while(start<=end){
            
            //How to check if we can reach to the dow or not
            vector<vector<bool>>dp(row,vector<bool>(col));
            for(int i = 0;i<=mid;++i){
                dp[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            
            queue<pair<int,int>>bfs;
           // used.clear();
            
            for(int j = 0;j<col;++j){
                if(dp[0][j] == 0){
                    bfs.push({0,j});
                    dp[0][j] = 1;
                    //used.insert({0,j});
                }
            }
            int f=0;
            while(!bfs.empty()){
                int c = bfs.size();
                for(int i=0;i<c;++i){
                    pair<int,int>node = bfs.front();
                    bfs.pop();
                    
                    int x = node.first;
                    int y = node.second;
                    
                    if((x+1) == row){
                        f=1;break;
                    }
                    // So I want to visit those nodes that are permitted 
                    //all four directions
                    if((y-1)>=0){
                        if(dp[x][y-1] == 0){
                           // if(used.find({x,y-1})==used.end()){
                                bfs.push({x,y-1});
                            dp[x][y-1] = 1;
                                //used.insert({x,y-1});
                            //}
                        }
                    }
                    
                    if((x-1)>=0){
                        if(dp[x-1][y] == 0){
                            //if(used.find({x-1,y})==used.end()){
                                bfs.push({x-1,y});
                            dp[x-1][y] = 1;
                              //  used.insert({x-1,y});
                            //}
                        }
                    }
                    
                    if((x+1)<row){
                        if(dp[x+1][y] == 0){
                           // if(used.find({x+1,y})==used.end()){
                                bfs.push({x+1,y});
                            dp[x+1][y] = 1;
                               // used.insert({x+1,y});
                           // }
                        }
                    }
                    
                    if((y+1)<col){
                        if(dp[x][y+1] == 0){
                            //if(used.find({x,y+1})==used.end()){
                                bfs.push({x,y+1});
                            dp[x][y+1] = 1;
                              //  used.insert({x,y+1});
                            //}
                        }
                    }
                    
                }
                if(f)break;
            }
            
            //cout<<mid<<" "<<f<<"\n";
            if(f){
                //this means we are able to cross so now we will decrease the value of mid
                //and change 
                ans = max(ans,mid);
                
                start = mid+1;
                mid = (start+end)/2;
                
            }
            else{
                end = mid-1;
                mid = (start+end)/2;
            }
        }
        
        
        
        return ans+1;
         
    }
};
