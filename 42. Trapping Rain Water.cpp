class Solution {
public:
    int trap(vector<int>& height) 
    {
        auto l = height.begin(), r = height.end()-1;

        int low = 0, res = 0;

        while(l != r+1)
        {
            int tmp = *l > *r? *r--:*l++;
            res += max(0,low-tmp);
            low = max(low,tmp);
            
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int len = height.size(),res = 0;
        if(!len) return res;
        int left[len]={0}, right[len]={0};

        for (int i = 1; i < len; ++i)
        {
            if(i==1)
            {
                left[i] = height[0];
                right[len-1-i] = height[len-1];
                continue;
            }
            left[i] = max(left[i-1],height[i-1]);
            right[len-1-i] = max(right[len-i],height[len-i]);
        }

        for (int i = 1; i < len; ++i)
        {
            int tmp = min(left[i],right[i]) -height[i];
            if(tmp > 0) res+= tmp;
        }

        return res;

    }
};