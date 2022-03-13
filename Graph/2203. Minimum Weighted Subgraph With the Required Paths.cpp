/*
Platform :- Leecode
Contest :- Leetcode Weekly contest 284
Approach :- You need to use pen and paper and think about it , We will use three dijkstra one for 'src1' ,one for'src2' and one for 'dest' , we will create two graph one that is 
            given and other one has reverse direction of edges ( we will use this to go from destination to source nodes) .
            Now if it is not possible to reach from any of source nodes then the answer is -1 else the min cost is( cost_to_reach_dest_from_src1 + cost_to_reach_dest_from_src2)
            and for all the common points/nodes we can visit from all the three , we will find ( cost1[i] + cost2[i] + cost3[i] ) and min of all such value is answer.
*/
