/*
Platform :- Codeforces
Contest :- Codeforces Round 811 Div 3
Approach :- You need to carefully observe few things , for all values except (5 and 0) , we can always hit the repeating values at the one's position .
            if we perform the repetitve operation given in problem we will get following sequence for remainder value (1 to 9) excluding (5 and 0)
            1 --> 2 --> 4 --> 8 --> 6 --> 2 --> 4 -->8  ..so 
            2 --> 4 ---> 8 -->6 --->2 ...
            yeah so repetaing value is (2 - 4 - 8 - 6 ) the sum of them is 20.
            So basic idea is to cahnge the values of array such that we get the remainder with 10 one of the above vlaue . Now we can only convert one to another if 
            the differnece between them is multiple of 20 else we cannot .If for any of the remainder value (2,4,6,8} we get the condition satisfied we can make them eual
            
            For 5 --> 0
            for 0.
            So we will do check them separately 
*/
