/*
Platform :- Leetcode
Approach :- This problem is variation of (74. Search a 2D Matrix)
            --> the difference in both the problem is that here it is not nescessary that ( matrix[i][0] > matrix[i-1][m-1] ) 
            --> so here for all the columns of first row we will do binary search and check if there is our target value in that particular column or not
Time Complexity :- O( m * Log n)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //so we will check for each column in first row
        //if we have that target value or not 
        //time complexity is O(m*logn)
        for(int i = 0;i<matrix[0].size();++i){
            //now check for each column in first row if there is 
            //the target value or not 
             
            int start = 0,end = matrix.size()-1,mid = (start+end)/2;
            while(start<=end){
                if(matrix[mid][i] == target){
                    return true;
                }
                else{
                    if(matrix[mid][i]<target){
                        start = mid+1;
                        mid = (start + end)/2;
                    }
                    else{
                        end = mid - 1;
                        mid = (start + end )/2;
                    }
                }
            }
        }
        
        return false;
    }
};
