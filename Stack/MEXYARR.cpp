/*
Platform :- Codechef 
Contest :- Codechef Starters 31 
Approach :- So we will use stack to store the index which we are available to fill, all the indexes having '-1' are assigned in stack , now for values >=0 , we will push that
            index in stack too , we will first maintain the set of values from 0 to max value of array , so the first value of set tells us about current mex of our array
            we will assign value if the first value is < B[i] for all indexes having value >= 0.
*/
