/*
Platform :- Leetcode
Approach :- We first sort the values by the 'last date' in increasing order and if the 'last date' for some values are same then we sort them based on 'duration' in inreasing
            order. We maintain one max_heap ( priority_queue ) in c++ , we will traverse through the array and choose the 'ith' course if it can be completed within
            'last_date[i]' , else we will check if the max_duration course is greater than 'duration[i]' then we remove that course and took this one , and update the heap
            and total_duration used .
*/
bool comp(vector<int>&P,vector<int>&Q){
    if(P[1]==Q[1]){
        return P[0]<Q[0];
    }
    return P[1]<Q[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int ans=0;
        
        sort(courses.begin(),courses.end(),comp);
        int tot=0;
        
        priority_queue<int>value;
        //so the basic idea is to traverse through the array and choose those values which fit in 
        //the time limit range 
        
        for(int i=0;i<courses.size();++i){
            int temp=tot+courses[i][0];
            if(temp<=courses[i][1]){
                ans++;
                value.push(courses[i][0]);
                tot=temp;
            }
            else{
                if(value.size() && value.top()>courses[i][0]){
                    tot-=(value.top() - courses[i][0]);
                    value.pop();
                    value.push(courses[i][0]);
                }
            }
        }
        return ans;
    }
};
