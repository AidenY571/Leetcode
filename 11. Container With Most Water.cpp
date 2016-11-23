class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int a = 0, b = height.size()-1,res = 0;

        while(a != b)
        {
        	int tmp = (b-a)*(min(height[a],height[b]));

        	if(tmp > res) res = tmp;

        	height[a] >= height[b] ? b--:a++;
        }

        return res;
    }
};