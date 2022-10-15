/*
Platform :- Coding Competitions with google
Approach :- You need to now how to check if a two cirlces overlap,touch or are dijoint .
            C1*C2 <= abs(R1-R2) --- this means we have two cirlces which have contact to each other 
            else others are disjoint.
            We checkf or all the red and yellow points and store the points touching in increasing order . We increase the count until we found any of different 
            color.
Time Complxity :- O((n+m)*log(m+n)
*/
