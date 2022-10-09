/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 314
Approach :- We will maintain one suffix array which will store the minimum character to right of current index till the end , basically for index 'i' it store the 
            min character from  index [i,n] , 
            We will maintain a stack which store the available characters we can choose from.
            -- now we travers through the array from left to right and if (suff[i] == s[i]) , we will compare with the top elements of stack , we will take out the
            top element if that element is <= suff[i] , at the end we will add current element also as it is eqaual to suff[i],
            -- similarly for other values we will take top from stack if it is <= suff[i] and at the end we will push the current value in stack.
            If stack is not empty we make it empty and add the top values to end of our curren string .
            
Time Comlexity :- O(n)
*/
class Solution {
public:
    string robotWithString(string s) {
        int last = 0;
        string ans = "";
        
        //get the smallest value in untouched range
        vector<pair<char,int>>P;
        vector<int>fre(26);
        for(auto&x:s)fre[x-'a']++;
        
        
        int n = s.size();
       // sort(P.begin(),P.end());
       // vector<int>vis(n);
        vector<char>suff(n);
        char ch = 'z';
        for(int i=n-1;i>=0;--i){
            ch = min(ch,s[i]);
            suff[i] = ch;
        }
        stack<char>Q;
        for(int i=0;i<n;++i){
             
            //check if this is the smallest 
            if(suff[i] == s[i]){
               // cout<<s[i]<<" ";
               //I will in my stack
                while(!Q.empty()){
                    char cur = Q.top();
                    if(cur <= s[i]){
                        //take this
                        ans += cur;
                        Q.pop();
                    }
                    else break;
                }
                ans += s[i];
            }
            else {
                 
                while(!Q.empty()){
                    char cur = Q.top();
                    if(cur <= suff[i]){
                        Q.pop();
                        ans += cur;
                    }
                    else break;
                }
                Q.push(s[i]);
            }
            
        }
         
        while(!Q.empty()){
            ans += Q.top();
            Q.pop();
        }
        return ans;
    }
};
