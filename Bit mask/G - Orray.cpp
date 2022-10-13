/*
Platform :- Codeforces
Contest :- Codeforces Contest 827 Div 4
Appraoch :- We get increasing value if we set a bit that is not set , so there can be atmax 30 bits inside current constraints . So we will can have atamax 30 values 
            which will be acutally setting a bit , we will run loop 32 times on array and each time we will find the one elements that will change the OR the most.
            We will mark them , we will choose from unmarked values and at the end the we take all the unmarked ones.
            
 Time Complexity :- O(n)
*/
