class NumArray {
public:
    vector<int> sum;
    int len = 0;
    NumArray(vector<int> &nums) 
    {
        len = nums.size();
        
        sum.resize(len+1);
        
        for(int i = 1; i <= len;++i)
        {
            sum[i] = sum[i-1] + nums[i-1];
        }
    }

    int sumRange(int i, int j) 
    {
        return sum[j+1] - sum[i];
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);