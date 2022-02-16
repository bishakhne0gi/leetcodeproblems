/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Example 3:

Input: s = "bb"
Output: 2
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char, int> map;
        for (int i=0; i<s.size(); i++) // save in map the amount of each letter in s
        {
            map[s[i]]++;
        }
        bool flag = false;
        for (auto x : map)
        {
            res += x.second - (x.second % 2); // add 2 to res for each pair of the same letter
            if (x.second % 2==1) // allow one letter to be only once - for odd length palindrome
                flag = true;
        }
        if (flag)
            res++;
        return res;
    }
};