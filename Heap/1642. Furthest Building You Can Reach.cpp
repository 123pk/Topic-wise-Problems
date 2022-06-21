/*
Platform :- Leetcode
Approach :- We will maintain a max heap and we will add the amount of bricks required when A[i]>A[i-1] , we will add (A[i]-A[i-1]) to our sum , if the (sum>limit)
            then we remove the max value of required brick till current index and will increment the count of such operation , if the count > 'k' we break out of loop.
            and the last index-1 is our answer.
*/
