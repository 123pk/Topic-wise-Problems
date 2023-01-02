/*
Platform :- Leetcode
Approach :- We will root our tree at '0' (we can choose any node) ,
            now using bfs we will compute two things fro each node (sum_of_path_to_all_nodes_in_subtree ,  no_of_node_in_subtree) .
            We will get the score of rooted node,
            now we run the bfs from that root to other nodes,
            -- count = no_of_nodes_in_subtree_with_current_node_as_root
            
            "Score[i] = Score[parent] - count + ( n - count) }"
            --> We subtract because we are moving a distace from (parent --> ith node) that will reduce the score by (count)
            --> and we get additional value added (n-count)
Time Compelxity :- O(n+e)
*/
