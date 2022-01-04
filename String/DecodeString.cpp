/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/

/*
ALGO
1. Run the function recursively
2. if the string is a digit, then store the digits in k until it is not a digit
3. repeat the function
*/

class Solution {
    string decodeString(string &s, int &i)
    {
        string result;
        while(i<s.length() && s[i]!=']')
        {
            if(isdigit(s[i]))
            {
                int k=0;
                while(i<s.length() && isdigit(s[i]))
                {
                    //ascii value of 0 is 48 so we are subtracting it
                    k=k*10+s[i++]-'0';
                }
                //opening bracket
                i++;
                string r=decodeString(s,i);
                while(k-->0)
                {
                    result+=r;
                }
                //closing bracket
                i++;
                
            }
            else{
                result+=s[i++];
            }
        }
        return result;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};