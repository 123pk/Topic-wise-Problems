/*
Platform :- Codechef
Contest :- Codechef starters 48 Div 2
Approach :- We will first sort the nodes by level where root is at level '1' and leaf is at 'd' where 'd' is the depth of tree . Now we will sort nodes by decreasing order
            of their level and assign first 'k' values with '1' , now we will make sure than all the nodes will assigned in such a way that the xor value of their subtree is '0'
*/
