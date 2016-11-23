class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        vector<int>res(length,0);
        
        for (auto i : updates)
        {
            res[i[0]] += i[2];
            if(i[1]+1<length)res[i[1]+1] -= i[2];
        }
        
        int tmp = 0;
        for (int i = 0; i < length ; ++i)
        {
            tmp += res[i];
             res[i] = tmp;
        }
        return res;
    } 
};