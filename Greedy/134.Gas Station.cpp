
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx=-1;
        
        //which gas station to choose
        int start=0,d=0,n=gas.size();
        int tot=0;
        for(int i=0;i<n-d;++i){
            tot+=(gas[i]-cost[i]);
            if(tot<0){
                while(tot<0 && d<n){
                    tot+=(gas[n-1-d]-cost[n-1-d]);
                    start=n-1-d;
                    d++;
                }
                
                if(tot<0)return -1;
            }
        }
        
        return start;
    }
};
