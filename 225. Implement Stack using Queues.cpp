class Stack {
public:
    // Push element x onto stack.
    queue<int> q;
    void push(int x) 
    {
        queue<int> tmp;
        tmp.push(x);
        while(!q.empty())
        {
            tmp.push(q.front());
            q.pop();
        }
        q = tmp;
    }

    // Removes the element on top of the stack.
    void pop() 
    {
        if(!q.empty())q.pop();
    }

    // Get the top element.
    int top()  return q.front();
    
    // Return whether the stack is empty.
    bool empty() return q.empty();
};