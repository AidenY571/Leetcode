class MovingAverage {
public:
    /** Initialize your data structure here. */

    int window_s = 0;
    queue<int> q;
    double avg = 0;
    MovingAverage(int size) 
    {
        window_s = size;
    }
    
    double next(int val) 
    {
        int len = q.size();

        if (len < window_s) avg = (avg*len + val)/(len+1);

        else
        {
            avg = (avg*len - q.front() + val)/len;
            q.pop();
        }

        q.push(val);

        return avg; 
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */