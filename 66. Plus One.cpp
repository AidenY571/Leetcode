class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 ; --i)
        {
            int tmp = digits[i] + carry;
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }

        if(carry)digits.insert(digits.begin(),carry);

        return digits;
    }
};

//Tricky Method
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 9) digits[i] = 0;
            
            else {++digits[i];return;}
        }

        digits[0] =1;

        digits.push_back(0);

        return digits;
    }
};