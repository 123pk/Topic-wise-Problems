/*
Platform :- Codeforces
Contest :- Educational Round 129
Approach :- We will do partial bruteforce , we will take each digit of current value and find the new value for each digit on each level , we will perform bfs 
            we will choose the top 100 biggest values in each level and proceed with them to next level as soon as we get our first string of length 'n' we break out of loop
            I dont have any proff why to choose only top 100 , its just worked .
Time complexity :- O(100*log(10^n))
*/
