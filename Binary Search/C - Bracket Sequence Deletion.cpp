/*
Platform :- Codeforces
Contest :- Educational Round 125
Appraoch :- You need to carefully read the problem , So we have two challenges 
            1. How to optimally find if we have regular bracket from current sequence or not and if yes then till where
            2. How to find smallest palindromic prefix from current index 
            
            For '2' option you can analyse that if current character is '(' then required palindromic string is from current character to next occurence of current character
            For option 1 we can use a stack and prefix array , every time we found '(' we will push in stack with index and next time when we found ')' we will pop it out
            and store at the index of poped character the value of current index that will store we are having regular sequence from this 'ith' index to pref[i] , 
            now we will start from first index and we will try to find the smallest index from current index where we have either of one type of good substring .
*/
