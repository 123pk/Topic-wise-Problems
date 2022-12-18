/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 324
Approach :- We will first compress the values to be in range from [0,n-1],
            now we will find degree of nodes ,let c = count of nodes with odd degree
            if 'c' > 4 we cannot do it as two edges can cover atmax '4' nodex.
            if 'c' =  1 or c = '3' then also we cannot cover them in two edges.
            if (c==4) then we can cover if their is two pair of nodes out of all combination such that we can add them 
            if(c == 2) we have two option either to add a directly if possible or 
            node1 -->x  and  node2 --> x ,where x is some even degree node and it is allowed to have those edges
Time Compelxity :- O(n+e)
*/
