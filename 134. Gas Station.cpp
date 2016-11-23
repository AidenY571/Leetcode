class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total = 0, sum = INT_MAX, start = 0;
        
        for(int i = 0; i< gas.size(); ++i)
        {
            total+=gas[i]-cost[i];
            
            if(total < sum) {sum=total;start=i+1;}
        }
        
        return (total<0) ? -1: (start%n); 
    }
};