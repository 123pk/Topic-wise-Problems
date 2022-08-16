/*
Platform :- CSES
Problemset :- Dynamic Programming
Approach :- We maintain a set where we store the element of LIS , now when we get new element we find a spot for this current element in the LIS and if there is no element
            greater than this we increment our LIS len by 1 and update answer too, else we remove the just greater element and insert this element, we also store the len
            of LIS for each value in set.
            
            So for finding just greater element we use "Lower_bound" in c++ set stl
Time Complexity :- O(n*log(n))
*/
