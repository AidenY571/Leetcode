class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num == 1) return true;
            
        int l = 1, r = num/2;
        
        while(l <= r)
        {
            double mid = l + (r-l)/2 , tmp = num/mid;
            
            if(mid == tmp) return true;
            
            else if(mid > tmp) r = mid-1;
            
            else l = mid + 1;
        }
        
        return false;
    }
};