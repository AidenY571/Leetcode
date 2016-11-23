class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int, int>> res;
        
        int len1 = nums1.size(), len2 = nums2.size(), index[len2+1]={0};
        
        k = min(len1*len2,k);

        while(k--)
        {
            int sum = INT_MAX, pos;

            for (int j = 0; j < len2; ++j)
            {
                if(index[j] == len1) continue;
                
                int tmp = nums2[j] + nums1[index[j]];
                
                if(tmp < sum) {pos = j;sum = tmp;}
            }
            
            res.push_back({nums1[index[pos]],nums2[pos]});
            
            index[pos]++;
        }
        return res;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int, int>> res;
        auto cmp = [](pair<int,int> a,pair<int,int>b)
        {
            return a.first+a.second < b.first+b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        
        for(int i = 0; i < nums1.size(); ++i)
        {
            for(int j = 0; j < nums2.size(); ++j)
            {
                if(q.size() < k) q.push({nums1[i],nums2[j]});
                else
                {
                    if(nums1[i] + nums2[j] >= q.top().first + q.top().second) break;
                    
                    q.pop();
                    
                    q.push({nums1[i],nums2[j]});
                }
            }
        }
        
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        
        return res;
    }
};