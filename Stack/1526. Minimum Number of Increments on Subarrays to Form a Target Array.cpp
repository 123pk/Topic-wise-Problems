/*
Platform :- Leetcode
Approach :- We will use stack and if (A[i]<A[i-1]), then we will remove all the values from stack until we get the top element to be smaller than A[i] ,
            else we add in stack if (A[i]>A[i-1]) , if elements are equal we ignore them.
            Now while removing elemet from the stack we will add difference between top and second top element . Because that is the time required by us to change
            top element to second top.
            At the end we will have a non empty stack and we will add the top element to answer.
*/
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        
        stack<int>P;
        int n = target.size();
        
        for(int i=0;i<n;++i){
            if(i == 0)P.push(target[i]);
            else{
                if(target[i]<target[i-1]){
                    int last = P.top();
                    P.pop();
                    
                    if(P.empty()){
                        ans += abs(target[i]-last);
                        P.push(target[i]);
                        continue;
                    }
                    //I need to remove all the elements which are smaller than this
                    while(!P.empty()){
                        int val = P.top();
                        
                        if(val<=target[i]){
                            ans+= abs(last-target[i]);
                            break;
                        }
                        P.pop();
                        ans += last - val;
                        last = val;
                        if(P.empty())ans+=(last - target[i]);
                    }
                    
                    if(P.empty()){
                        P.push(target[i]);
                    }
                    else if(P.top()<target[i]){
                        P.push(target[i]);
                    }
                }
                else{
                    if(target[i]>target[i-1])P.push(target[i]);
                }
            }
          //  cout<<ans<<" ";
        }
        ans+=P.top();
        
        return ans;
    }
};
