
/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 134
Approach :- We will check for blockage , there are four kind of blockage ,if we can reach from top left (1,1) to (n,m) then min cost is (n+m-2)
            else -1,
            there are four types of blockage 
            1. row blockage   , whole row is is danger area this is possible when (x-1)<= d && (n-x)<=d
            2. column blockage , this is for column
            3. Upper cut reverse ' __|' blockage
            4. lower cur r blockage 
*/
