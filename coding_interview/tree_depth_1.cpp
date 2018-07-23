class Solution {
public:
    int TreeDepth(TreeNode* root) {
		if (NULL == root) return 0;
		queue<TreeNode*> parent;
		int depth = 1;
		parent.push(root);
		while (!parent.empty()){
            queue<TreeNode*> child;
			while (!parent.empty()){
				TreeNode* tmp = parent.front();
				parent.pop();
				if(tmp->left) child.push(tmp->left);
				if(tmp->right) child.push(tmp->right);
			}
			if (!child.empty()) depth += 1;
			parent = child;
		}
		return depth;
    }
};
