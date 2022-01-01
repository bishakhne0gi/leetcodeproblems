/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/

/*
ALGO
1. if the stack is not empty and character equal to # pop the top element
2. if the stack is empty and character equal to # dont pop the top element
3. if the stack is empty and character != # push the element
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1=s.size();
        stack<char> s1;
        int n2=t.size();
        stack<char> t1;
        for(int i=0; i<n1; i++)
        {
            if(s[i]== '#' && !s1.empty())
            {
                s1.pop();
            }
            else if((s[i]!= '#' && !s1.empty()) || (s[i]!= '#' && s1.empty()))
            {
                s1.push(s[i]);
            }
         
        }
        for(int i=0; i<n2; i++)
        {
              if(t[i]=='#' && !t1.empty())
            {
                t1.pop();
            }
            else if((t[i]!= '#' && !t1.empty()) || (t[i]!= '#' && t1.empty()))
            {
                t1.push(t[i]);
            }
        }
        bool flag=true;
        if(s1.size()!=t1.size())
        {
            flag=false;
            return flag;
        }
        while(!s1.empty())
        {
            if(s1.top()==t1.top())
            {
                s1.pop();
                t1.pop();
            }
            else{
                flag=false;
                break;
            }
        }
        return flag;
    }
};