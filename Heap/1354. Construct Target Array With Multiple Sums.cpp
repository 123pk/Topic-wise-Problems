/*
Platform :- Leetcode
Approach :- We go in reverse direction where we will try to obtain an array of all 1's , if it is possible then we return true, else return false.
            We store all the valus in max heap , we get the biggest value , we can remove ( sum - cur_value) from this , we will do this and push the new value in the
            priority queue, we will try to do this  operation greedily , so that to avoid TLE . Like we will get difference between biggest two value and
            remove(ceil(dif_between_two_max)/ value_we_can_remove) ) , we stop if we get '1' , if we get <1 return false; 
*/
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int flag = 0;
        sort(target.begin(),target.end());
        
         
        
        long long sum = 0;
        
        priority_queue<long long>P;
        
        for(auto&x:target){
            P.push(x);
            sum+=x;
        }
        
        //so basic approach is to start from the max value in priority queue
        //as we traverse through the aray and we try to go in reverse like can we get array with all ones
        //or not ?
        //if max element in priority queue is 1 then we have achieved it 
        
        while(P.top() != 1ll){
            long long cur_sum = P.top();
            P.pop();
            long long dif = sum - cur_sum;
            //dif = cur_sum - dif;
            //cout<<cur_sum<<" "<<dif<<"\n";
            if(cur_sum <= dif || dif == 0)return false;
            
            long long next_greater = P.top();
            if(P.top() == 1ll){
                long long val = target.size()-1;
                //cout<<cur_sum<<" "<<val<<"\n";
                if((cur_sum-1)%val)return false;
                break;
            }
            //dif = cur_sum - dif;
            
            long long to_change = cur_sum - next_greater;
            long long rem = to_change/dif;
            if(to_change%dif)rem++;
            rem*=dif;
            
            dif = cur_sum - rem;
            if(dif<1)return false;
            
            sum -= (cur_sum - dif);
            P.push(dif);
        }
        
        return true;
    }
};
