/*
Platform :- Leetcode
Approach :-  I will find the maximum frequency of character in string , that is the max possible frequency that can be assigned
             I will maintain a frequency array and sort the frequencis in decreasing order
             I will run a loop from i = mx to 1 and assign I would give the frequency of 'i' to the ith character if ( fre[i]> = i ) and I will have to delete
             (fre[i]-i) characters . Once I reach to 1 then I have to delete all the remaining characters and add frequency to answer.

*/
class Solution {
public:
    int minDeletions(string s) {
        vector<int>fre(26);
        int mx = 0;
        for(auto&x:s){
            fre[x-'a']++;
            mx = max(mx,fre[x-'a']);
        }
        
        //I dont care which character is what 
        //sort them in decreasing
        sort(fre.begin(),fre.end(),greater<int>());
        
         
        
        //Now I will giving frequency 
        int ans = 0;
        for(int i = 0;i<26;++i){
            if(fre[i]==0)break;
            if(mx==0){
                //only option is to delete all the characters
                ans+=fre[i];
            }else{
                 if(fre[i]<=mx){
                     mx = fre[i]-1;
                 }else{
                     ans+=(fre[i]-mx);
                     mx--;
                 }
            }
            //cout<<fre[i]<<" "<<ans<<" "<<mx<<"\n";
        }
        
        return ans;
        
    }
};
