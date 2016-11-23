class MinStack {
public:
    stack<int>s;
    
    stack<int>min;
    
    void push(int x) 
    {
    	s.push(x); 
    	
    	if(min.empty() || x<=min.top())
    	{
    		min.push(x);
    	}    
    }

    void pop() 
    {
        if (s.top() == min.top())
        {
        	s.pop();
        	min.pop();
        }
        else
        {s.pop();}
    }

    int top() 
    {
        return s.top();
    }

    int getMin() 
    {    
        return min.top();
    }
};
