# POSTORDER TRAVERSAL


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
    void util(vector<int>& ans, TreeNode* root)
    {
        if(root == NULL)
            return;
        util(ans, root->left);
        util(ans, root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // // util(ans, root);
        
        // return ans;

        // ITERATIVE:
        vector<int> ans;
        stack<TreeNode*> st;
        if(root == NULL)
            return ans;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->left)
                st.push(root->left);
            if(root->right)
                st.push(root->right);
        }
        reverse(ans.begin(), ans.end() );
        return ans;
    }
};
