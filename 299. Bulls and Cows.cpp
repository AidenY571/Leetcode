class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int arr[150]={0}, a = 0, b = 0;
        
        for (int i = 0; i < guess.size(); ++i)
        {
            if(guess[i] == secret[i])++a;
            else ++arr[secret[i]];
        }

        for (int i = 0; i < guess.size(); ++i)
        {
            if(guess[i] == secret[i]) continue;
            if(arr[guess[i]] > 0)
            {
                --arr[guess[i]];
                ++b;
            }
        }

        return to_string(a)+"A"+to_string(b)+"B";
    }
};