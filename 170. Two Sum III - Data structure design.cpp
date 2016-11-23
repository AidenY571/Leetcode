class TwoSum {
public:
    unordered_map<int,int>num;
    // Add the number to an internal data structure.
    void add(int number) 
    {
        num[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) 
    {
        for (auto i : num)
        {
            if(i.second < 1) continue;
            
            int tmp = value - i.first;

            if(tmp == i.first && i.second > 1) return true;

            if(tmp != i.first && num.count(tmp) > 0) return true;
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);