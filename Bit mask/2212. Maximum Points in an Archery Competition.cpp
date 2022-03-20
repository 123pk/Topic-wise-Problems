/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 285
Approach :- Since there are 12 option for us only then we will try all possilbe combination using bitmask , and the one which give us the max value and bobArrows are <=
             Alice arrows then we choose that option.
*/
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int z = 12;
        vector<vector<int>>ans;
        vector<int>temp;
        int idx = 0,mx = 0,val;
        for(int i=1;i<=(1<<12);++i){
            int tot = 0;
            temp.clear();
            val = 0;
            for(int j=0;j<aliceArrows.size();++j){
                if(i & (1<<j)){
                    val+=(j);
                    temp.push_back(aliceArrows[j]+1);
                    tot+=(aliceArrows[j]+1);
                }
                else temp.push_back(0);
            }
            
            if(tot <= numArrows){
                if(tot<numArrows){
                    int rem = numArrows-tot;
                    for(int i = 0;i<12;++i){
                        if(temp[i]){
                            temp[i]+=rem;
                            break;
                        }
                    }
                }
                if(mx<val){
                    mx = val;
                    idx = i-1;
                }
            }
            ans.push_back(temp);
        }
     //   cout<<mx<<" ";
        return ans[idx];
    }
};
