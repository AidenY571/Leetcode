class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
        int n = 0;

        for (int i = preorder.size()-1; i >= 0; --i)
        {
            if(preorder[i]==',')continue;
            if(preorder[i]=='#')n++;
            else
            {   
                if(n < 2) return false;
                n--;
                while(i > 0 && preorder[i-1] != ',') i--;
            }
        }
        
        return n==1;
    }
};