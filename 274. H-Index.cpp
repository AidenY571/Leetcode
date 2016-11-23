class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int len = citations.size(),res=0,tmp=0;
        int m[len+1]={0};

        for (int i = 0; i < len; ++i)
        {
            if(citations[i]<=len)m[citations[i]]++;
        }
    
        for (int i = 0; i <= len; ++i)
        {
            if(len - tmp >= i) res = i;
            tmp += m[i];
        }

        return res;  
    }
};