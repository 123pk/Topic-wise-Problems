/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 127
Approach :- We will first sort the array of prices  ,then find the max no of different values whose sum is less than "limit" , so let it be 'd' so we will have option
            from [1 to d] no of items to buys . We will start with buying 'd' element and then going till '1' , 
            for (i) elemets we will find the sum of smallest i elements (use prefix sum to store ) now it can be used till ((limit-pref[i])/i )th day
*/
