class FirstUnique
{
public:
    unordered_map<int, list<int>::iterator> m;
    list<int> unique;

    FirstUnique(vector<int> &nums)
    {
        for (int x : nums)
        {
            if (m.find(x) != m.end())
            {
                list<int>::iterator it = m[x];
                if (it != unique.end())
                {
                    unique.erase(it);
                    m[x] = unique.end();
                }
            }
            else
            {
                unique.emplace_back(x);
                list<int>::iterator it = unique.end();
                it--;
                m[x] = it;
            }
        }
    }

    int showFirstUnique()
    {
        if (unique.size())
        {
            return unique.front();
        }
        return -1;
    }

    void add(int value)
    {
        if (m.find(value) != m.end())
        {
            list<int>::iterator it = m[value];
            if (it != unique.end())
            {
                unique.erase(it);
                m[value] = unique.end();
            }
        }
        else
        {
            unique.emplace_back(value);
            list<int>::iterator it = unique.end();
            it--;
            m[value] = it;
        }
    }
};