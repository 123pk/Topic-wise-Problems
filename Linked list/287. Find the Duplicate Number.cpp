/*
Platform :- Leetcode
Approach :- the idea is same as ditecting cycle in a linked list where we use two pointer one is slow and one is fast which hops two places to next whenever they became equal
            we return that element.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums)
{
	if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
}
};
