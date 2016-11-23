class Solution {
public:
    vector<int> grayCode(int n) 
    {
        bitset<32> gray;

        vector<int> code;
        
        check(gray,code,n-1);
        
        return code;
    }
    
    void check(bitset<32> &gray,vector<int>&code, int pos)
    {
        if(pos < 0)
        {
            code.push_back(gray.to_ulong());
            return;
        }
        check(gray,code,pos-1);
        gray.flip(pos);
        check(gray,code,pos-1);
    }
};

class Solution {
public:
    vector<int> grayCode(int n) 
    {
        bitset<32> gray;

        vector<int> code;
        
        check(gray,code,n-1,0,1);
        
        return code;
    }
    
    void check(bitset<32> gray,vector<int>&code, int pos,int first, int second)
    {
        if(pos < 0)
        {
            int tmp = gray.to_ulong();
            code.push_back(tmp);
            return;
        }
        if(gray[pos+1]) swap(first,second);
        gray[pos] = first;
        check(gray,code,pos-1, first, second);
        gray[pos] = second;
        check(gray,code,pos-1,first, second);
    }
};