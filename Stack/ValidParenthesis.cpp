/** Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false**/

/**Algorithm: 

.Declare a character stack S.
.Now traverse the expression string exp. 
1.If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
2.If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else brackets are not balanced.
.After complete traversal, if there is some starting bracket left in stack then “not balanced”**/

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        char x;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty())
                return false;
             if (s.empty())
            return false;
 
        switch (s[i]) {
        case ')':
             
            x = st.top();
            st.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            x = st.top();
            st.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            x = st.top();
            st.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
      }
        return (st.empty());
    }
};