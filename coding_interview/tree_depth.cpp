class Solution {
public:
    int TreeDepth(TreeNode* root) {
		int max_depth = 0;
		helper(root, 0, max_depth);
		return max_depth;
    }

	void helper(TreeNode* root, int depth, int& max_depth){
		if (root == NULL) return;
		depth += 1;
		max_depth = max(depth, max_depth);
		helper(root->left, depth, max_depth);
		helper(root->right, depth, max_depth);
	}
};
