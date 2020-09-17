class Solution
{
public:
    bool checkValidString(string s)
    {

        int stable = 0;
        for (char x : s)
        {
            if (x == '(' || x == '*')
            {
                stable++;
            }
            else if (--stable == -1)
            {
                return false;
            }
        }
        stable = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == ')' || s[i] == '*')
            {
                stable++;
            }
            else if (--stable == -1)
            {
                return false;
            }
        }
        return true;
    }
};