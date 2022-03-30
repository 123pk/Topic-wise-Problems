/*
Platform :- Leetcode
Appraoch :- We will use binary search , Since we are given that ( matrix [ i ][ 0 ] > matrix[ i - 1 ][ col - 1] ) --> first element of ith matrix is greater than last 
            element of i-1th row , so first we will find the row using binary search and then we will use binary serach on that row to find the value 
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       //so we willuse binary search
        // first on row as it is given that first element of ith
        //row is greater than last element of (i-1)th row
        int s_row = 0,e_row = matrix.size()-1;
        int m_row = (s_row+e_row)/2;
        
        while(s_row <= e_row){
            if(matrix[m_row][0] == target){
                return true;
            }
            else{
                if(matrix[m_row][0]<target){
                    s_row = m_row+1;
                    m_row = (s_row+e_row)/2;
                }
                else{
                    e_row = m_row-1;
                    m_row = (s_row+e_row)/2;
                }
            }
        }
        
        //now we will do binary search on that row
        int s_col = 0,e_col = matrix[0].size()-1;
        int m_col = (s_col+e_col)/2;
        
        while(s_col<=e_col){
            if(matrix[m_row][m_col] == target){
                return true;
            }
            else{
                if(matrix[m_row][m_col]<target){
                    s_col = m_col + 1;
                    m_col = (s_col+e_col)/2;
                }else{
                    e_col = m_col - 1;
                    m_col = (s_col+e_col)/2;
                }
            }
        }
        return false;
    }
};
