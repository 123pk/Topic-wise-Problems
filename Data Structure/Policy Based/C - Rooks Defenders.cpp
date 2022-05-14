/*
Platform :- Codeforces
Contest :- Codeforces Round 791
Approach :- For query of type '3' , we can acheive that if and only if we have atleast one rook in all the row from 'x1' to 'x2' or in all columns from 'y1' to 'y2'
            we can do that query in log(n) using 'Policy Based Data structure' in C++ by 'Ordered Set' , which gives no of values strictly smaller than current value
            in 'log(n)' , if we have (x2-x1) = order_of_key(x2) - order_of_key(x1) same for columns , but those rows and columns must be present in ordered set 
            ---> We will also maintain frequency of each row and each column it will help us in removing elemnet form set .
*/
