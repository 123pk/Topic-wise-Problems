/*
Platform :- Leetcode
Approach :- We can convert the current number into string and try out all the permutaion of the string and if there is some string which satisfy the given condtion, 
            lik we conver the string to integer and if the integer contains only one set bit in binary reprensentaion then it is power of 2
Time Complexity :- O(2^n)
*/
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string s=to_string(n);
        int f=0;
        sort(s.begin(),s.end());
        do{
            if(s[0]!='0'){
           int m=stoi(s);
           string z=bitset<64>(m).to_string();
            if(count(z.begin(),z.end(),'1')==1){
                f=1;break;
            }
            }
        }while(next_permutation(s.begin(),s.end()));
        return f;
    }
};
