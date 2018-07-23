class Solution {
public:
    int TreeDepth(TreeNode* root) {
		if (NULL == root)
			return 0;
		int left = 1 + TreeDepth(root->left);
		int right = 1 + TreeDepth(root->right);
		return max(left, right);
    }
};
