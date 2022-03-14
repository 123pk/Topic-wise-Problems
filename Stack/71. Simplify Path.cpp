/*
Platform :- Leetcode
Approach :- We will use the stack of string to push the folder names , if we enounter '..' after a single or series of slash '/' then we pop the top element of stack at the end
            we take all the string from the stack and add it to our answer where each directory name is separated by '/' and the canonial path start with '/'
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>P;
        string ans="/";
        string temp="";
        int f = 0,d=0;
        for(int i=0;i<path.size();++i){
            if(f){
                if(path[i]=='.'){
                    d++;
                    temp+='.';
                    if(i == path.size()-1){
                        if(d==2 && temp.size()==2){
                            if(P.size())P.pop();
                        }
                        else if(d==1)continue;
                        else{
                            P.push(temp);
                        }
                    }
                }
                else{
                    if(path[i] == '/'){
                       // cout<<temp<<" ";
                        if(temp.size()){
                            if(d==2 && (temp.size()==2)){
                                if(P.size())P.pop();
                            }
                            else if(d==1 && temp.size()==1){
                                 
                            }
                            else {
                                P.push(temp);
                            }
                            
                        }
                        temp="";
                        d=0;
                    }
                    else {
                        d=0;
                        temp+=path[i];
                        if(i == path.size()-1){
                            P.push(temp);
                        }
                    }
                }
            }
            else{
                if(path[i]=='/'){
                    f=1;
                    d=0;
                }
                
                    
                 
            }
        }
        vector<string>zz;
        while(!P.empty()){
            zz.push_back(P.top());
            P.pop();
        }
        
        reverse(zz.begin(),zz.end());
        string z="";
        for(auto&x:zz){
            ans+=x;
            ans+='/';
        }
        
        if(ans[ans.size()-1]=='/')ans.pop_back();
        if(ans.size()==0)ans+='/';
        
        return ans;
    }
};
