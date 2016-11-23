/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) 
    {
        while(root)
        {
            s.push(root);
            
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        auto tmp = s.top()->right;

        int smallest = s.top()->val;
        
        s.pop();
        while(tmp)
        {
            s.push(tmp);

            tmp = tmp->left;
        }
        
        return smallest;
        
    }
private:
    stack<TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */