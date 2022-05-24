/*
Platform :- Codeforces
Contest :- Educational Round 129
Approach :- We will do partial bruteforce , we will take each digit of current value and find the new value for each digit on each level , we will perform bfs 
            we will choose the top 100 biggest values in each level and proceed with them to next level as soon as we get our first string of length 'n' we break out of loop
            I dont have any proff why to choose only top 100 , its just worked .
Time complexity :- O(100*log(10^n))
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long val;
    cin>>n>>val;
    
    //top 8 max values are choosen
    string s = to_string(val);
    int g = 0;
    //if s is not valid then we leave this 
    for(auto&x:s){
        if(x>'1'){
            g = 1;break;
        }
    }
    
    if(g == 0){
        cout<<"-1";
        exit(0);
    }
    
    queue<pair<string,long long>>bfs;
    bfs.push({s,val});
    vector<long long>P;
    
    int ans = 0,f = 0;
    int count = 0;
    long long new_val;
    
    while(!bfs.empty()){
        int c = bfs.size();
        P.clear();
        for(int i=0;i<c;++i){
            pair<string,long long>temp = bfs.front();
            bfs.pop();
            s = temp.first;
            val = temp.second;
             
            if(s.size() == n){
                ans = count;
                f = 1;
                break;
            }
            
            vector<int>dig(10);
            for(auto&x:s)dig[x-'0']++;
            for(int j=2;j<=9;++j){
                if(dig[j]){
                    //find the values store in vector we will choose the top 10
                    new_val = j;
                    new_val*=val;
                    P.push_back(new_val);
                }
            }
        }
        
        if(f)break;
        count++;
        sort(P.begin(),P.end(),greater<long long>());
        int sz = P.size();
        for(int i=0;i<min(sz,100);++i){
            bfs.push({to_string(P[i]),P[i]});
        }
    }
    
    cout<<ans<<"\n";
    
}
