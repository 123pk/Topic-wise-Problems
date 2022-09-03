/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 86

Approach is to use a left/start pointer and we will consider subarray from [start,current_index 'i'] , 

i. We will use prefix sum to find sum of runningcost in O(1)

ii. We will use set and map , set to get the max element in range in O(logn)

iii. We will use map to store the frequency of each element in subarray choosen,
    while moving the left/start pointer we will decrease the freqeuncy count of left/start element and remove from set
    if frequency becomes zero

So Time complexity :- O(n*log(n))
 

*/
class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {
        int ans = 0;
        
        //we will use two pointer 
        //we will find the cost and also the 
        //let us have prefix array of sum of cost of subarray in range in O(1)
        
        int n = run.size();
        vector<long long>pref(n);
        long long tot = 0;
        
        for(int i=0;i<n;++i){
            tot+=run[i];
            pref[i] = tot;
        }
        
        set<int>P;
        map<int,int>count;
        //so we will use set to find the max element in O(log n)
        //we will use count to remove the elements
        
        tot = 0;
        int c = 0,start = 0;
        long long z;
        for(int i=0;i<n;++i){
           //I choose the current value 
            //add in set and increment frequency of it
            P.insert(charge[i]);
            count[charge[i]]++;
            c++;
            
            //now find the current score
            tot = pref[i];
            if(start)tot-=pref[start-1];
            z = c;
            tot*=z;
            auto it = P.rbegin();
            long long val = *it;
            
            tot += val;
           
            
            //now if this score is within the budget then we store the max size of subarray in answer
            if(tot<=budget){
                ans = max(ans,c);
            }
            else{
                //now I need to move my left poitner until
                //the score is less than budget
                
                while(start<=i){
                    
                    if(count[charge[start]] == 1){
                        P.erase(charge[start]);
                    }
                    count[charge[start]]--;
                    start++;
                    c--;
                    
                    //this means our subarray is empty
                    if(start>i)break;
                    
                    auto it2 = P.rbegin();
                    val = *it2;
                    long long cur_score = 0;
                    cur_score += pref[i];
                    cur_score -= pref[start-1];
                    z = c;
                    cur_score*=c;
                    cur_score+=val;
                    
                    if(cur_score<=budget)break;
                }
            }
        }
        
        return ans;
    }
};
