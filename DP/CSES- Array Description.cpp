/*
Platform :- CSES
Approach :- We will use ( recurison + memoistaion ) , for a current index 'i' we will get A[i+1] in our parameter , we will then check if absolute difference between 
            abs(A[i+1]-A[i]) <= 1 or not if it is greater than '1' then we cannot move forward as there is no array with such value , if it satisifies the condition 
            we move forward to i-1 and do similar stuff ,
            
            if(A[i] == 0) then we will try three values 'A[i+1]',' A[i+1]-1 ' and A[i+1]+1 , as these three value are the only ones which satisfy the conditon abs(A[i]-A[i+1) <= 1
            
*/
