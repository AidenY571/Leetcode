class Queue {
public:
    // Push element x to the back of queue.
    stack<int> s;
    stack<int> tmp;
    void push(int x) 
    {
        tmp.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) 
    {
        if(s.empty())
        {
            while(!tmp.empty())
            {
                s.push(tmp.top());
                tmp.pop();
            }
        }
        if(!s.empty())s.pop();
    }

    // Get the front element.
    int peek(void) 
    {
        if(s.empty())
        {
            while(!tmp.empty())
            {
                s.push(tmp.top());
                tmp.pop();
            }
        }
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) 
    {
        if(s.empty())
        {
            while(!tmp.empty())
            {
                s.push(tmp.top());
                tmp.pop();
            }
        }
        return s.empty();
    }
};