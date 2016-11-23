class Solution {
public:
    string longestPalindrome(string s) 
    {
        int len = 0, start = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            int a = i;

            while(i < s.size()-1 && s[i] == s[i+1]) i++;

            int b = i;

            while(a > 0 && b < s.size()-1 && s[a-1] == s[b+1]) {a--;b++;}

            int tmp = b - a + 1;

            if(len < tmp) {len = tmp;start = a;} 
        } 
        return s.substr(start,len);
    }
};


class Solution {
public:
    string longestPalindrome(string s) 
    {
        string res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int len1 = check(s, i-1,i+1);
            int len2 = check(s, i, i+1);

            int len = max(len1,len2);

            if(len > end-start+1)
            {
                start = i - (len-1)/2;
                end = i+len/2;
            }
        }
    }

    int check(string &s, int l, int r)
    {
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            --l;++r;
        }

        return r-l+1;
    }
};

class Solution {
public:
    string preProcess(string s) 
    {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);
    
        ret += "#$";
        return ret;
    }

    string longestPalindrome(string t) 
    {
        string s = preProcess(t);
        int *p = new int[s.size()];
        int mx = 0, id = 0, maxl = ;

        for (int i = 1; i < s.size()-1; ++i)
        {
            if(mx > i)
            {
                p[i] = p[id - (i - id)] < mx - i ? p[2*id - i] : mx-i;
            }
            else p[i] = 1;

            while(s[i-p[i]] == s[i+p[i]])
            {
                ++p[i];
            }

            if(p[i]+i > mx)
            {
                mx = p[i]+i;
                id = i;
            }
        }

        for (int i = 1; i < s.size()-1; ++i)
        {
            if (--p[i] > mx)
            {
                maxl = p[i];
                id = i;
            }
        }

        return t.substr((id - 1 - mx)/2, mx);
    }
};


