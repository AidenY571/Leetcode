class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int len = citations.size(),a = 1, b = len;
        int mid = 0,res=0;
        while(a <= b)
        {
            mid = (a+b)/2;

            if(citations[len - mid] >=  mid){res = mid;a = mid + 1;}
            else
                b =  mid-1;
        }
        return res;  
    }
};