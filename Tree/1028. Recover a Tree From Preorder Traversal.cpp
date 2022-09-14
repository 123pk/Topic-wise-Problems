/*
Platform :- Leetcode
Approach :- We store chldren of each node intially marked as [-1,-1] , where first -1 =  no left child and second -1  = no right child.
            We traverse through the string and store the nodes at each level , if we found a node at level 'c' then this node is going to be child of
            lasst node of level '[c-1]' for all ' c >= 1 ' . 
            The very first node that we get is out root node, so we do BFS starting from root node and we progress adding left child first and then right child 
            if they are not -1.
 Time Complexity :- O(nlogn)
*/
