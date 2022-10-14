/*
Platform :- Codeforces 
Contest :- Codeforces Round 827 Div 4
Approach :- We will store the sum of height that we can achieve for each of the steps , so we will store the steps in set , if step[i]<step[i-1] ,then we ignore this 
            step[i-1] = height[i-1]+height[i] , now we will use lower_bound to find the nearest valid step that we can have and the height correspondingg to it is 
            our soution.
Time Complexity :- O(n*log(n))
*/
