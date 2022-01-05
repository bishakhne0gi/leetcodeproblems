/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

/*
ALGO
1. initialise left which will start from left of the array
2. when the sum>= the target subtract the element from the left of the array from the sum
3. increment let index
4. return result
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result=INT_MAX;
        int left=0, val_sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            val_sum+=nums[i];
            while(val_sum>=target)
            {
                result=min(result,i+1-left);
                val_sum-=nums[left];
                left++;
            }
         }
        if(result!=INT_MAX) return result;
            else
                return 0;
    }
};