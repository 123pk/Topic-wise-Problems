/*
Platform :- Leetcode
Approach :- first sort the interval in increasing order of start value, since they are not overlappinng you don't need to care about second value of range
             now maintain tow variable 'l' and 'r'which are end points of current range.
             There are three situations :- 
             1. we have already added the new Interval
                 -- we check if current interval is copletely inside the l and r-- then we leave them
                 --- if they are overalpping then we update the end point of interval.
                 --- disjoint then update and add to our answer
             2. we have not added the current interval
                -- if current enpoints are disjoint and start point is > new interval end then we add the new interval and 
                   add all the remainining intervals as it is.
                -- if current end point come before the new interval we add the current interval and move to next one
Time Complexity :- O(n log n)
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }

        if(newInterval.size() == 0){
            return intervals;
        }

        sort(intervals.begin(),intervals.end());
        sort(newInterval.begin(),newInterval.end());

         
        int n = intervals.size();
        int m = newInterval.size();
        int j = 0;
        int l = intervals[0][0];
        int r = intervals[0][1];
        int x =  newInterval[0];
        int y =  newInterval[1];
        for(int i=0;i<n;++i){
            cout<<l<<" "<<r<<" "<<j<<"\n";

            if(j){
                if(l<=intervals[i][0] && r>=intervals[i][1]){
                    if(i == n-1)ans.push_back({l,r});
                    continue;
                }
                else if(intervals[i][0]<=r){
                    r = max(r,intervals[i][1]);
                    if(i == n-1)ans.push_back({l,r});
                }
                else{
                  //  cout<<"*";
                   
                    ans.push_back({l,r});
                    l = intervals[i][0];
                    r = intervals[i][1];
                    if(i == n-1)ans.push_back({l,r});
                }
            }
            else{
                if(y<l){
                    ans.push_back(newInterval);
                    j++;
                    if(i == n-1)ans.push_back({l,r});
                }
                else if(x>r){
                    ans.push_back({l,r});
                    if(i<n-1){
                        l = intervals[i+1][0];
                        r = intervals[i+1][1];
                    }
                    
                }
                else{
                    //we have overlapping
                    l = min(x,intervals[i][0]);
                    r = max(y,intervals[i][1]);
                    j++;
                    if(i == n-1){
                       ans.push_back({l,r});
                    }
                }
            }
        }

        if(j == 0)ans.push_back(newInterval);

        return ans;
    }
};
