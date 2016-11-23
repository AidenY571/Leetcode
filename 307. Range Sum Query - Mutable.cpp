class NumArray {
private:
    vector<int> num;
    vector<int> tree;
    int len = 0;
public:
    NumArray(vector<int> &nums) 
    {
        len = nums.size();
        
        num = vector<int>(len,0);
        
        tree = vector<int>(len+1,0);

        for(int i = 0; i < len; ++i)
        {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) 
    {
        if(!len) return;
        
        int diff = val - num[i];
        
        num[i] = val;
        
        for(int j = i+1; j <= len; j += (j & -j))
        {
            tree[j] += diff;
        }
    }

    int sumRange(int i, int j) 
    {
        if(!len) return 0;
        return -sum(i) + sum(j) + num[i];
    }
    
    int sum(int i)
    {
        int res = 0;
        
        for(int j = i + 1; j > 0; j -= (j & -j))
        {
            res += tree[j];
        }
        
        return res;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);