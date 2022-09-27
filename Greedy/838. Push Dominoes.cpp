class Solution {
public:
    string pushDominoes(string s) {
        string ans=s;
        vector<int>change;
        for(int i=0;i<s.size();++i){
            if(s[i]!='.'){
                change.push_back(i);
            }
        }
        if(change.size()==0)return s;
        int start=change[0];
        int j=1;
        for(int i=0;i<s.size();++i){
            if(i<=start){
                if(i==start){
                    if(s[start]=='L')ans[i]='L';
                    else ans[i]='R';
                }
                else{
                    if(s[start]=='L')ans[i]='L';
                    else ans[i]='.';
                }
            }
            else{
                if((j)<change.size()){
                    if(s[start]=='R' && s[change[j]]=='L'){
                       // cout<<(i+1)<<" ";
                        int d=i-start;
                        int k=change[j]-i;
                        //cout<<d<<" "<<k<<endl;
                        if(d==k)ans[i]='.';
                        else if(d<k)ans[i]=s[start];
                        else ans[i]=s[change[j]];
                    }
                    else if(s[start]=='L' && s[change[j]]=='R'){
                        if(i==change[j])ans[i]='R';
                        else ans[i]='.';
                    }
                    else{
                        ans[i]=s[start];
                    }
                    
                    if(i==change[j]){
                        start=change[j];
                        j++;
                    }
                }
                else{
                    if(s[start]=='R')ans[i]='R';
                    else ans[i]='.';
                }
                
            }
        }
        return ans;
    }
};
