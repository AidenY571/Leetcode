class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    set<pair<int, int>> s;
    vector<pair<int, int>> f;
    int w,h,index = 0,size = 0;
    
    struct snake
    {
        snake *front;
        snake *next;
        int x,y;
        snake():x(0),y(0),front(NULL),next(NULL){}
    };
    
    snake *head;
    snake *end;
    
    SnakeGame(int width, int height, vector<pair<int, int>> food) 
    {
        f = food;
        w = width-1;
        h = height-1;
        head = new snake();
        end = head;
        s.insert({0,0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) 
    {
        int a = head->x, b = head->y;

        switch(direction[0])
        {
            case 'U': --a;break;
            case 'L': --b;break;
            case 'R': ++b;break;
            case 'D': ++a;break;
        }

        if(a<0 || b<0 || a>h || b>w) return -1;
        snake *tmp = new snake();
        tmp->next = head;
        head->front = tmp;
        tmp->x = a;
        tmp->y = b;
        head = tmp;
        if(index < f.size() && make_pair(a,b) == f[index])
        {
            index++;
            size++;
        }
        else
        {
            s.erase(s.find(make_pair(end->x,end->y)));
            if(s.find(make_pair(a,b))!=s.end()) return -1;
            end = end->front;
            end->next = NULL;
            
        }
        
        
        s.insert({a,b});
        
        return size;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */