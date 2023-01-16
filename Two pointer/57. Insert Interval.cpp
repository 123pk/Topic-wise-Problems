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
