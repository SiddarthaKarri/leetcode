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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            unsigned long long mmin = q.front().second;
            unsigned long long first,last;
            int size=q.size();
            for(int i=0;i<size;i++){
                unsigned long long cur=q.front().second - mmin;
                TreeNode* nd=q.front().first;
                q.pop();
                if(i==0)
                    first=cur;
                if(i==size-1)
                    last=cur;
                if(nd->left)
                    q.push({nd->left,2*cur});
                if(nd->right)
                    q.push({nd->right,2*cur+1});
            }
            ans = max(ans,(long long)(last-first+1));
        }
        return (int)ans;
    }
};