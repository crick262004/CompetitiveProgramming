# PREORDER TRAVERSAL


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
    // void util(TreeNode* root, vector<int>& ans)
    // {
    //     if(root == NULL)
    //         return;
    //     ans.push_back(root->val);
    //     util(root->left,ans);
    //     util(root->right, ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // util(root, ans);
        // return ans;


        // iterative:
        // vector<int> ans;
        // stack<TreeNode*> st;
        // if(root == NULL)
        //     return ans;
        // st.push(root);

        // while(!st.empty())
        // {
        //     TreeNode* root = st.top();
        //     st.pop();
        //     ans.push_back(root->val);
        //     if(root->right)
        //         st.push(root->right);
        //     if(root->left)
        //         st.push(root->left);
        // }
        // return ans;

        // the morris preorder traversal : 
        // basically to make the code be O(1) space.
        vector<int> preorder;
        TreeNode* cur = root;

        while(cur)
        {
            if(cur->left == NULL)
            {
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                while(temp->right && temp->right != cur)
                {
                    temp = temp->right;
                }
                if(temp ->right == NULL)
                {
                    temp ->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                    // this over here is the entire point of this traversal.
                    // well usually, we rely on the stack to backtrack from the predecessor back to the root
                    // but that takes up memory.
                    // so while we are at the root, we go to the predecessor and make its right pointer point to the root. So that we naturally come back.
                    // and when we reach the root for the second time, we remove this thread.
                }
                else
                {
                    // this is the second time, so we gotta remove this thread
                    temp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};
