/*
Contest :- Leetcode Weekly contest 311
Approach :- We will maintain a trie which will contain one count array which will be updated every time we visit that character node of trie ,  it is basically frequency arry
            for that character node , now while searching we will find the sum of frequency of all characters in path .
Time Complexity :- O(n*m) where m is length of longest string
*/

struct trie{
   public:
    trie*child[26];
    //frequency array to store the frequency of each node we visit
    int count[26];
    bool EndOfWord;
    trie(){
        for(int i=0;i<26;++i){
            child[i] = NULL;
            count[i] = 0;
        }
    }
};

void insert(string& s,trie*root){
    trie*start = root;
    trie*last;
    int prev = 0;
    
    //we traverse the root and create trie
    int n = s.size();
    for(int i = 0;i<n;++i){
        int val = s[i]-'a';
       
        if(start->child[val] == NULL){
            //it means we need to create new node 
            trie*node = new trie;
            start->child[val] = node;
            node->count[val]++;
            
            //It is end of word 
            if(i == (n-1))node->EndOfWord = true;
            else node->EndOfWord = false;
            start = start->child[val];
            
        }
        else{
             
            start = start->child[val];
            
            //updating the frequency
            start->count[val] ++;
        }
    }
}

int search(string&s,trie*root){
    trie*temp = root;
    int n = s.size();
    
     int tot = 0 ; 
    for(int i=0;i<n;++i){
        int idx = s[i]-'a';
        if(temp->child[idx] == NULL){
            return false;
        }
        temp = temp->child[idx];
        
        //finding the sum of frequncy of each character in path 
        tot += temp->count[idx];
    }
    return tot;
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int>ans(n);
        
        //Building trie
         trie*root = new trie;
        for(auto&x:words){
            insert(x,root);
        }
        int i = 0;
        
        //finding the score 
        for(auto&x:words){
            ans[i] = search(x,root);
            i++;
        }
        return ans;
    }
};
