/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 293
Approach :- Basic approach is to store the first value of range in set so we can do (insert and delet operation in Log(n)) , We will store the end part of range of each 
            value of set using map . 
            
            There are many cases to take care of 
            1. If our set is empty we push directly into the set 
            2. else we will check if we start value of range in set or not , if yes then we will update the end value accordingly and if we have certain overlapping ranges
               we will remove them if they come inside the range .
            3. If this value is not present in set then also ther are two sceneraio 
                 i. either it is withing some range or 
                 ii. not in range of any 
                 we take care of these cases accordingly.
*/
