class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int fop = 0;

        for (auto x : shift)
        {
            if (x[0] == 0)
            {
                fop += (-1 * x[1]);
            }
            else
            {
                fop += x[1];
            }
        }

        string result = "";
        string temp = "";
        if (fop > 0)
        {
            int n = s.length();
            fop = fop % n;
            for (int i = (n - fop); i < n; ++i)
            {
                temp += s[i];
            }
            for (int i = 0; i < fop; ++i)
            {
                result += temp[i];
            }
            for (int i = 0; i < (n - fop); ++i)
            {
                result += s[i];
            }
        }
        else
        {
            int n = s.length();
            int pf = -1 * fop;
            pf = pf % n;
            for (int i = 0; i < pf; ++i)
            {
                temp += s[i];
            }
            for (int i = pf; i < n; ++i)
            {
                result += s[i];
            }
            for (int i = 0; i < pf; ++i)
            {
                result += temp[i];
            }
        }

        return result;
    }
};