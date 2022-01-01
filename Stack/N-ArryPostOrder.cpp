/*
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:


Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
Example 2:


Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
*/

/*ALGO
1. Push the root traverse the children from left to right
3. Reverse the vector
4. Return the vector
*/

/*
Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node *> s;
        if(root == NULL) return res;
        s.push(root);
        while(!s.empty())
        {
            Node *temp= s.top();
            s.pop();
            res.push_back(temp->val);
            for(int i=0; i<temp->children.size(); i++)
                s.push(temp->children[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};