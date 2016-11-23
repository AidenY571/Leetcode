//Method 1 map
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int>m;
        
        int len = 0;
        
        for(int i : nums)
        {
            if(m[i]) continue;
            
            int l = m[i-1], r = m[i+1];
            
            int sum = l + r + 1;
            
            len = max(sum,len);
            
            if(l) m[i-m[i-1]] = sum;
            
            if(r) m[i+m[i+1]] = sum;
            
            m[i] = sum;
        }
        return len;
    }
};

//Method 2 set
class Solution {
public:
    int longestConsecutive(vector<int> &num) 
    {
        unordered_set<int> record(num.begin(),num.end());
        int res = 1;
        for(int n : num)
        {
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};