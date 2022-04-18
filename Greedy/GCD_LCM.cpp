/*
Platform :- Codechef
Contest :- Codechef Lunctime April
Approach :- if either of value is '1' then our answer is also '1' else
             we do prime factorisation of 'X'(changing value) , find the primes and their powers , suppose power of some prime 'a' is 'b' in 'X' then if (b>(c-b)) then only
             it is useful as it will decresse X by a^(c-b) , we need to take care of case when 'a' > c there we will first do (a % c)
*/
