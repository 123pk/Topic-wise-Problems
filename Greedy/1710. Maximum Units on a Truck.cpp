/*
Platform :- Leetcode
Approach :- Greedily sort the array ,
*/

bool comp(vector<int>A,vector<int>B){
    if(A[1]==B[1])return A[0]>B[0];
    return A[1]>B[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxType, int truckSize) {
        sort(boxType.begin(),boxType.end(),comp);
        
        int ans=0;
        for(int i=0;i<boxType.size();++i){
            if(truckSize<=boxType[i][0]){
                ans+=(truckSize*boxType[i][1]);
                break;
            }
            else{
                ans+=(boxType[i][0]*boxType[i][1]);
                truckSize-=boxType[i][0];
            }
        }
        return ans;
    }
};
