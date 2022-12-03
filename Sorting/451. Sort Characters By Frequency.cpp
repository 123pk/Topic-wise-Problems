/*
Platform :- Leetcode
Approach :- We will find the frequencey of each character and then sort the characters by frequency in decreasing order.
            Later we will add the characters to the final string.
Time Complexity :- O(n log n)
*/
bool comp(pair<int,char>&P,pair<int,char>&Q){
    if(P.first == Q.first)return P.second<Q.second;
    return P.first>Q.first;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>fre;
        for(auto&x:s)fre[x]++;

        vector<pair<int,char>>P;
        for(auto&x:fre){
            P.push_back({x.second,x.first});
        }
        sort(P.begin(),P.end(),comp);

        string ans = "";
        for(auto&x:P){
            char ch = x.second;
            for(int i=1;i<=x.first;++i){
                ans += ch;
            }
        }
        return ans;
    }
};
