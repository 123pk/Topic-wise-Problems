/*
Platform :- Codechef
Contest :- Codechef Lunctime March 2022
Approach :- We do bfs on nodes that are frozen and we use a vis array to visit the unvisited ones only , we do so whenever we have some time lapse or query of
            type 2 . We bfs for 't' minutes or until the time our queue is not empty. For 3rd query if the node is already visited then it means it is frozen and we
            print "YES" else "NO"
*/
