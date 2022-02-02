/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        int m=a.size();
        int n=b.size();
        vector<int> res;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i=0, j=0;
        while(i<m && j<n)
        {
            if(a[i]<b[j])
                i++;
            else if(b[j]<a[i])
                j++;
            else
            {
                res.push_back(a[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};