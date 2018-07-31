/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
	if (!root) return {};

	vector<vector<int>> ret;
	queue<TreeNode*> q;
	q.push(root);
 	int currLevel = 0;
	int nextLevel = 1;
	while (!q.empty()) {
		if (currLevel) {
			--currLevel;
			auto currNode = q.front();
			q.pop();
			ret.back().push_back(currNode->val);
			if (currNode->left) {q.push(currNode->left); ++nextLevel;}
			if (currNode->right) {q.push(currNode->right); ++nextLevel;}
		} else {
			currLevel = nextLevel;
			nextLevel = 0;
			ret.push_back(vector<int>());
		}
	}

	reverse(ret.begin(), ret.end());

	return ret;
    }
};
