/*
Platform :- Codeforces
Contest :- Educational Round 132
Approach :- We will try to find max value in range of (y1,y2) columns  using segment tree in log(n) per query . Then we will check few things the abs(x2-x1) and abs(y2-y1)
            both this should be divisible by 'k' else we cannot reach there , then we will check if we can go above the max value or not ,basically a distance 'x' which is
            multiple of 'k' distance from 'x1' and 'x'> max value .
*/
