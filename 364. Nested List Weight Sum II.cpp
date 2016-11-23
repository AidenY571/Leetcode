/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int t = 0;
    int depthSumInverse(vector<NestedInteger>& nestedList) 
    {
        vector<pair<int,int>>sum;
        int res = 0;
        for(auto i : nestedList)
        {
            check(i,1,sum);
        }
        
        for(auto i : sum)
        {
            res += i.first*(1+t -i.second);
        }
        return res;
    }

    void check(NestedInteger nestedList, int depth, vector<pair<int,int>>&sum)
    {
        if(nestedList.isInteger())
        {
            sum.push_back(make_pair(nestedList.getInteger(),depth));
            t = max(t,depth);
            return;
        }
        else
        {
            auto tmp = nestedList.getList();
            for(auto i : tmp)
            {
                check(i,depth+1,sum);
            }
        }
        return;
    }
};