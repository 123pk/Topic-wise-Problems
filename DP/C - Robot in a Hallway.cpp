/*
Platform :- Codeforces
Contest :- Codeforces Educatinal Round 133
Approach :- We have two options only either to go right or down . We will follow this pattern DRURDRUR...
            and at each point we have option to go straing to the end and then go up and get back stragint and we do the same we precompute the cost of 
            path1 , going from 0,0 --> 0,1-->...0,n-1 then to 1,n-1 --> 1,n-2 -- ... 1,0 , this is our path 1 we find the time to reach the node and waiting time 
            to reach till that node .
            
            Similarly path2 is reverse of this and we do the same .
            While folowing the starting pattern of (DRURDR..) at any point of time we will find the cost to reach using the path1 or 2 and the min cost out of all such option
            is our solutin.
*/
