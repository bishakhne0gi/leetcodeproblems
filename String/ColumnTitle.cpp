/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
*/

/*ALGO
We shall find the modulus of the number and 26
 1. If it gives 0, then we add Z to the ans, and divide the number by 26 and subtract 1 from it
 2. If it gives non-zero, then we add A+(x-1) to the answer, and then divide the number by 26
*/

class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
    while(n>0)
    {
        int x=n%26;
        if(x==0)
        {
            ans='Z'+ans;
            n=(n/26)-1;
        }
        else{
            ans=char('A'+(x-1))+ans;
            n/=26;
        }
    }
    return ans;
    }
};