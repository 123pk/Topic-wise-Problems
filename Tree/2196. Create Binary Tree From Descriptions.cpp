/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 283
Approach :- Brutforces , we just mintain a array of pointer where each poiter points to ith node, we also use compression to make the value of nodes in range [1 to n] for easy operation
            then to find root , the node which dont have any parent is our root , apart from that we add child of ith node based on given information .
*/
