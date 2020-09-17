class Solution
{

    string filter(string s1)
    {
        string s = "";
        for (char x : s1)
        {
            if (x == '#')
            {
                if (!s.empty())
                {
                    s.pop_back();
                }
            }
            else
            {
                s += x;
            }
        }
        return s;
    }

public:
    bool backspaceCompare(string S, string T)
    {
        return filter(S) == filter(T);
    }
};