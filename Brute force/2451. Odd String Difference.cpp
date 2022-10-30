/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 90
Appraoch :- Check for each stirng find the total number of changes required ,if no of changes <= 2, add this string else ignore
Time Complexity ;- O(n*m)
*/
class Solution {
public:
    string oddString(vector<string>& word) {
        string ans;
        
        set<vector<int>>temp;
        map<vector<int>,string>P;
        map<vector<int>,int>count;
        for(auto&x:word){
            vector<int>cur;
            for(int i=1;i<x.size();++i){
                cur.push_back(x[i]-x[i-1]);
            }
            if(temp.size()){
                if(temp.find(cur) != temp.end()){
                    
                }
                else temp.insert(cur);
            }
            else temp.insert(cur);
            count[cur]++;
            P[cur] = x;
            cur.clear();
        }
        
        for(auto&x:temp){
            if(count[x] == 1){
                ans = P[x];
                break;
            }
        }
        
        return ans;
    }
};
