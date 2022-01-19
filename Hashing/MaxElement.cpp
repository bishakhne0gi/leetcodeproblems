/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>umap;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            umap[nums[i]]++;
        }
        int number=0;
        int freq=0;
        for(auto itr=umap.begin(); itr!=umap.end(); itr++)
        {
            int key=itr->first;
            int val=itr->second;
            if(val>freq)
            {
                freq=val;
                number=key;
            }
        }
        return number;
    }
};