/*
Platform :- Codeforces
Contest :- Codeforces Round 670 # Div 2
Approach :- First find the no of centroid , if there is just one centroid then we remove and add same edge .
            --> For finding centroid we store the size of subtree for each node and for node 'i' , we find the max of all subtree size of child nodes and (n-(sum_of_all)+1)
                 this will give me upper subtree (nodes above current node) size
                 
            --> We cannot have more than two centroid . In this case we remove leaf  node of one centroid and add it to other centroid.
*/
