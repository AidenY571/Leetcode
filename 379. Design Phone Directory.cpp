class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    vector<int> num;
    vector<int> avai;
    int len,index;
    PhoneDirectory(int maxNumbers) 
    {
        for (int i = 0; i < maxNumbers; ++i) num.push_back(i);
        avai = vector<int>(maxNumbers,1);
        len = maxNumbers;
        index = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() 
    {
        if(index < len) 
        {
            avai[num[index]] = 0;
            return num[index++];
        }
        
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) 
    {
        if(avai[number])return true;
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) 
    {
        if(number<len && number>=0 && !avai[number])
        {    
            num[--index] = number;
            avai[number] = 1;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */