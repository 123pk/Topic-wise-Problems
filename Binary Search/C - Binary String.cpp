/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 128
Appraoch :- We do binary search on no of zeros we will eliminate , we will have a 'V' shape curve , vlaues will decrease then increase after reaching some point , so we will 
            find two value/score , one is for the middile element and one to its neighbour and based on score we will decide which way to move . As we want to reach the local
            minima.
            We will use prefix and suffix array which will store no of '1' we have to remove till that '0' value index.
            This will help us in finding the score in O(mid) time ,
            So what we will do is first mid,mid-1,mid-2......1.0 , value from start and 0,1,....mid values from end in this combination we  wull remove zeros .
*/
