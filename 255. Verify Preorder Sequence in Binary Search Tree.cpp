class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) 
    {
        stack<int> s;
        int min_v = INT_MIN;

        for (int i = 0; i < preorder.size(); ++i)
        {
            while(!s.empty() && preorder[i] > s.top())
            {
                min_v = max(min_v,s.top());
                s.pop();
            }
            
            if(preorder[i] < min_v) return false;

            s.push(preorder[i]);
        }

        return true;
    }
};