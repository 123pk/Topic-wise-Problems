/*
Platform :- Leetcode
Approach :- We will use a stack which will store "value" and "count" , where count is number of values which are consecuitevely before "value" and are smaller or equal
            to "value" , whenever we get value from stack and check if that value is smaller or equal to current value then we remove it and add the count to our answer
            at the end we push current value and answer to stack.
Time Complexity :- O(n)
*/
class StockSpanner {
public:
    // we wnat to know the number of consecutive elemeents that 
    //are <= current price
    stack<pair<int,int>>P;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!P.empty()){
            //get the max value
            if(P.top().first<=price){
                ans += P.top().second;
                P.pop();
            } 
            else break;
        }
        P.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
