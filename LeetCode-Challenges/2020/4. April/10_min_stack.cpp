class MinStack
{
public:
    // pair<top,min>
    stack<pair<int, int>> s;
    MinStack()
    {
    }

    void push(int x)
    {
        if (s.empty())
        {
            s.push({x, x});
        }
        else
        {
            s.push({x, min(x, s.top().second)});
        }
    }

    void pop()
    {
        if (!s.empty())
        {
            s.pop();
        }
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};
