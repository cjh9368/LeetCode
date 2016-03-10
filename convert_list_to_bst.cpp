/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
 		if(head == NULL)     return NULL;
 		int cnt = 0;
 		ListNode* itr = head;
 		while(itr != NULL) 
 		{
 			itr = itr->next;
 			cnt++;
 		}
 		return helper(0, cnt - 1, head);
    }
    TreeNode* helper(int start, int end, ListNode* node)
    {
    	if(start > end)  return NULL;
    	int middle = (start + end) / 2;
    	TreeNode* left = helper(start, middle - 1, node);
    	TreeNode* root = new TreeNode(node->val);
    	root->left = left;
    	node = node->next;
    	TreeNode* right = helper(middle + 1, end, node);
    	root->right = right;
    	return root;
    }
};