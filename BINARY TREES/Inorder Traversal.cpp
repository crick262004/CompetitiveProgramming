// INORDER TRAVERSAL

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
    //     util(root->left, ans);
    //     ans.push_back(root->val);
    //     util(root->right, ans);
    //     return;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // util(root, ans);
        // return ans;

        // iterative solution:
        // vector<int> ans;
        // stack<TreeNode*> st;
        // TreeNode* temp = root;
        // while(temp)
        // {
        //     st.push(temp);
        //     temp = temp->left;
        // }
        // while(!st.empty())
        // {
        //     TreeNode* cur = st.top();
        //     st.pop();
        //     ans.push_back(cur->val);
        //     temp = cur->right;
        //     while(temp)
        //     {
        //         st.push(temp);
        //         temp = temp->left;
        //     }
        // }
        // return ans;   

        // ITERATIVE STANDARD SOLUTION
        // I DONT QUITE UNDERSTAND THE INTUITION.
        // I mean, kar toh vahi raha hai. Its just that we made
        // a temp variable to push in all the left nodes
        // and made it's loop a part of the bigger loop.
        // vector<int> ans;
        // TreeNode* temp = root;
        // stack<TreeNode*> st;
        // while(true)
        // {
        //     if(temp)
        //     {
        //         st.push(temp);
        //         temp = temp->left;
        //     }
        //     else
        //     {
        //         if(st.empty())
        //             break;
        //         TreeNode* node = st.top();
        //         st.pop();
        //         ans.push_back(node->val);

        //         temp = node->right;
        //     }
        // }
        // return ans;


        // the morris traversal. 
        // O(1) space 
        // I'm not too sure about the time complexity.
        // something like O(NlogN) or O(N)
        
        vector<int> inorder;
        TreeNode* cur = root;

        while(cur)
        {
            if(cur->left == NULL)
            {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                while(temp->right && temp->right != cur)
                    temp = temp->right;
                if(temp ->right == NULL)
                {
                    // first time
                    temp->right = cur;
                    cur = cur->left;
                }
                else{
                    // second time
                    temp ->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};