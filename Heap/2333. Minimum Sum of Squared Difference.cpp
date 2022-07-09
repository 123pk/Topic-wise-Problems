/*
Platform :- Leetcode
Contest :- Leetcode Bi weekly contest 82
Approach :- Find the abs differece of values abs(nums1[i] - nums2[i]) and store in array , find the frequency of each value in difference array , now use priority queu
            aka max heap to store the unqiue value of difference array in it , now we will try to convert the max value into second max value , if we have just one element
            then we will try to change to '0' .
            
            If we dont have sufficient values to change we will change uniformly , like we have 'k' values and we can do 'd' operations then we will decrease each value
            by (k/d) and (k%d) values to be decreased by additional '1', we will update the frequency accordingly in this .
            
            At the end we will add (fre[x] * x) and that is required answer.
            
 Time Complexity :- O(n*log(n))
 Space complexity :- O(n)
*/
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        
        long long val = k1+k2;
        priority_queue<long long>P;
        
        map<long long,long long>count;
        int n = nums1.size();
        for(int i=0;i<n;++i){
            count[abs(nums1[i] -nums2[i])]++;
        }
        
        for(auto&x:count){
            P.push(x.first);
        }
        
        while(!P.empty() && val){
            long long first = P.top();
            P.pop();
            long long c =count[first];
            //cout<<first <<" "<<c<<"\n";
            if(!P.empty()){
                //we will get the second smallest value
                long long second = P.top();
                long long dif = first - second;
                
                dif*=c;
                
                if(dif>val){
                    //this  means we cannot covert all the values to smaller value
                    //so we will convert to some mid value
                    long long rem = val%c;
                    long long change = val/c;
                    long long nw = first - change;
                    count[nw] += c - rem;
                    count[nw-1] += rem;
                    count[first] -= c;
                    break;
                }
                else{
                    //we change them to second smallest value
                    val -= dif;
                    count[second]+=c;
                    count[first] -= c;
                }
            }
            else{
                //if we have justs one value we will try to chagne this to as small as possible
                //first we will check if we can convert to 0 or not
                long long cost = first *c;
                if(cost<=val){
                    count[first] = 0;
                    break;
                }
                long long rem = val%c;
                long long change = val/c;
                long long nw = first - change;
                count[nw] += c - rem;
                count[nw-1] += rem;
                count[first] -= c;
                break;
            }
        }
        
        for(auto&x:count){
            long long val = x.first;
            val*=val;
            val*=x.second;
            ans+=val;
        }
        
        return ans;
    }
};
