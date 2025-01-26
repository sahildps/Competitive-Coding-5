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

/*
TC : O(N)
SC: O(N) where n is the elements in the level of the tree
*/
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> store;
        vector<int> result;

        store.push(root);

        while (!store.empty())
        {
            int qSize = store.size();
            int curMax = INT_MIN;

            for (int i = 0; i < qSize; i++)
            {
                TreeNode *curRoot = store.front();
                if (curRoot->val > curMax)
                {
                    curMax = curRoot->val;
                }

                if (curRoot->left)
                {
                    store.push(curRoot->left);
                }

                if (curRoot->right)
                {
                    store.push(curRoot->right);
                }
                store.pop();
            }
            result.push_back(curMax);
        }

        return result;
    }
};