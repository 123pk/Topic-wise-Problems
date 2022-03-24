/*
Platform :- Codeforces
Contest :- Codeforces CodeTon Round 1(Div 1+Div 2)
Approach :- So this problem is all about analysing it , 
            1.if we have the minimum element of array >1 then we can always have a solution , we will choose elements in decreasing
            order starting from the maximum value and all the way to minimum value and perform the operation.
            
            2. If we have all same element then also we have a valid solution
            3. If we have both 1 and 0 then we have no solution
            4. if we have min value as 0 and 1 is not present then we have solution ,it is same as case 1
            5. if we have min vaue as 1 then if we have two adjacent values in sorted array having absolute different == 1 , then also we don't have any solution
            
*/
