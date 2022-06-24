/*
Platform :- Leetcode
Approach :- We go in reverse direction where we will try to obtain an array of all 1's , if it is possible then we return true, else return false.
            We store all the valus in max heap , we get the biggest value , we can remove ( sum - cur_value) from this , we will do this and push the new value in the
            priority queue, we will try to do this  operation greedily , so that to avoid TLE . Like we will get difference between biggest two value and
            remove(ceil(dif_between_two_max)/ value_we_can_remove) ) , we stop if we get '1' , if we get <1 return false; 
*/
