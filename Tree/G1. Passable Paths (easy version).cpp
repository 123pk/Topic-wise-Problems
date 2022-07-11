/*
Platform :- Codeforces
Contest :- Codeforces Round 805 Div 3
Approach :- For each query we find the end two points , basically if we consider diameter then we want to finnd the end points of diameter ( end points of path) , now
            we will find distance of each node from one of the end point and we will traverse throgh one of the end point and will check if we get the values in increasing
            order of distance or not , if we reach till the last node then its a valid path else not .
Time complexity :- O(nlogn * q ) since q is small it is O(n log n)
*/
