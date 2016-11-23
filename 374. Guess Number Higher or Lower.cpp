// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) 
    {
        int a = 1,mid = 0;

        while(a <= n)
        {
            mid = a+(n-a)/2; // important to get the average
            
            int tmp = guess(mid);

            if(tmp==0) return mid;
            
            else if(tmp>0) a = mid+1;
            
            else
                n = mid - 1;
        }

        return mid;
    }
};