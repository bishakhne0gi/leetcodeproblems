/**
 Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
**/

/**ALGO
Using 1 Stack. O(n) Time & O(n) Space
This is similar to Inorder using 1 Stack. The difference is we keep track of the previously printed node in pre. And we only print a node if its right child is null or equal to pre.
Push all left nodes into the stack till it hits NULL.
root = s.peek()
if root.right = null or pre (Means we have traversed the right subtree already)
We print root and pop it from s.
Make pre = root
root = null (So we dont go down to left child again)
else
root = root.right (Traverse the right subtree before printing root)
Keep iterating till both the below conditions are met -
Stack is empty and
Root is NULL.
**/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    int i=0;
    stack<TreeNode *> s;
    TreeNode *prev= NULL;
        while(root!= NULL|| !s.empty()){
			if(root!= NULL){				
				s.push(root);
				root = root->left;
			}
			else{
				root = s.top();
				if(root->right==NULL || root->right==prev){
				    v.push_back(root->val);
                    i++;
				    s.pop();
				    prev=root;
				    root = NULL;
				}
				else
				    root = root->right;
			}
		}
        
        return v;
    }
};