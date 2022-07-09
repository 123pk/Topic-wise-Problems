/*
Platform :- Leetcode
Contest :- Leetcode Bi weekly contest 82
Approach :- Find the abs differece of values abs(nums1[i] - nums2[i]) and store in array , find the frequency of each value in difference array , now use priority queu
            aka max heap to store the unqiue value of difference array in it , now we will try to convert the max value into second max value , if we have just one element
            then we will try to change to '0' .
            
            If we dont have sufficient values to change we will change uniformly , like we have 'k' values and we can do 'd' operations then we will decrease each value
            by (k/d) and (k%d) values to be decreased by additional '1', we will update the frequency accordingly in this .
            
            At the end we will add (fre[x] * x) and that is required answer.
            
 Time Complexity :- O(n*log(n))
 Space complexity :- O(n)
*/
