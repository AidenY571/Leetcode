class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        int len = stones.size();

        unordered_map<int,unordered_set<int>>m;

        m[1].insert(1);

        for (int i = 1; i < len; ++i)
        {
            for (auto j : m[stones[i]])
            {
                m[stones[i] + j].insert(j);
                m[stones[i] + j+1].insert(j+1);
                m[stones[i] + j-1].insert(j-1);
            }
        }

        return !m[stones.back()].empty();
    }
};

class Solution {
public:
    bool canCross(vector<int>& stones, int pos = 0, int k = 0) 
    {
        for (int i = pos + 1; i < stones.size(); i++) 
        {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1) continue;
            if (gap > k + 1) return false;
            if (canCross(stones, i, gap)) return true;
        }
        return pos == stones.size() - 1;
    }
};