/*
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
*/

/*ALGO
Pop the top node from the stack – Top from the stack and insert it into visited list of nodes.
Push all of the child nodes of Top into the stack from right to left as the traversal from the stack will be carried out in a reverse order. As a result, correct preorder traversal is achieved.
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
    vector<int> preorder(Node* root) {
        stack<Node*> Stack;
    vector<int> Preorder;
    if(root==NULL) return Preorder;
    Stack.push(root);
  
    while (!Stack.empty()) {
        Node* temp = Stack.top();
        Stack.pop();
        // store the key in preorder vector(visited list)
        Preorder.push_back(temp->val);
        // Push all of the child nodes of temp into
        // the stack from right to left.
        for (int i = temp->children.size() - 1; i >= 0; i--) {
            Stack.push(temp->children[i]);
        }
     }
        return Preorder;
    }    
};