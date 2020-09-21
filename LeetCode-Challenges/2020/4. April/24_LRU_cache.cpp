class LRUCache
{
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int n = 0;

    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        list<pair<int, int>>::iterator it = m[key];
        pair<int, int> p = *it;
        int val = p.second;
        cache.erase(it);
        cache.push_front({key, val});
        it = cache.begin();
        m[key] = it;
        return val;
    }

    void put(int key, int value)
    {
        bool exist = (m.find(key) != m.end());
        if (n == 0 && !exist)
        {
            list<pair<int, int>>::iterator it = cache.end();
            it--;
            pair<int, int> p = *it;
            m.erase(p.first);
            cache.pop_back();
            n++;
        }
        if (exist)
        {
            list<pair<int, int>>::iterator it = m[key];
            cache.erase(it);
            cache.push_front({key, value});
            it = cache.begin();
            m[key] = it;
        }
        else
        {
            cache.push_front({key, value});
            list<pair<int, int>>::iterator it = cache.begin();
            m[key] = it;
            n--;
        }
    }
};
