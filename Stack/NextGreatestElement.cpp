/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
*/


/*
ALGO

1. Move from back of num2 array till front
2. Push the element in the stack, now:
    a) if stack is empty and the element in num2 >= top element in stack then pop from stack
        if stack is empty then map the element and -1
    b) if stack is not empty
       map the element and the top element in stack
3. return the final vector
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        stack<int>s;
        map<int,int>mp;
        int s1=nums1.size(), s2=nums2.size();
        for(int i=s2-1; i>=0; i--)
        {
            while(!s.empty() && nums2[i]>=s.top())
            {
                s.pop();
            }
            if(s.empty()) mp.insert({nums2[i],-1});
            else mp.insert({nums2[i],s.top()});
            s.push(nums2[i]);
        }
        for(auto x:nums1)
        {
            res.push_back(mp[x]);
        }
        return res;
    }
};