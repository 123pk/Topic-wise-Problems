/*
Platform :- Codechef
Contest :- Codechef starters 62
Approach :- Since the biggest odd factor of N is 10^5 , we can exploit this ,
           first of all you need to know X^2 * (A^2 + B^2) =  (XA^2 + XB^2) ,
           so A number N can be written as Y*Z where Y is product of combination of elements occuring even number of times . X*X*Y*Y... as this can be written into (X*Y)^2
           So at the end there will be the element Z which contins odd occurence of element with just one occurence we need to check if this number is perfect square or not
           if this number of perfect sqare then yes we can find a pair A,B and multiply them with the X*Y
Time Comlexity :- O(sqrt(2*10^5)
*/
