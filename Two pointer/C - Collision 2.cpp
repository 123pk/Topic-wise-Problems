/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 243
Approach :- For collision we need two things ,
            1. Y coordinate of both the Persons need to be same
            2. Person with smaller coordinate should move to 'R'(right)  and Person with larger coordinate should move to 'L'(left)
            So we will use two 'map' in C++ and 
               i. one to store the range of values (x - coordinate) of persons moving left.
              ii. second one to store the range of values (x - coordinate) of person moving right.
            Now we will check for each value of 'y' if (largest value of coordinate moveing left )> smallest value of coordinate moving right or not . and that is our answer.
*/
