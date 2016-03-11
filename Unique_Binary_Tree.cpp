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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) return res;
       return helper(1, n); 
    }
    vector<TreeNode*> helper(int left, int right)
    {
    	vector<TreeNode*> res; res.clear();
    	if(left > right)
    	{
			res.push_back(NULL);
			return res;
    	}
    	for(int i = left; i <= right; i++)
    	{
    		vector<TreeNode*> leftVector = helper(left, i - 1);
    		vector<TreeNode*> rightVector = helper(i + 1, right);
    		for(int j = 0; j < leftVector.size(); j++)
    		{
    			for(int k = 0; k < rightVector.size(); k++)	
    			{
    				TreeNode* root = new  TreeNode(i);
    				root->left = leftVector[j];
    				root->right = rightVector[k];
    				res.push_back(root);
    			}
    		}
    	}
    	return res;
    }
};