//  https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int n) {
    string data;
    data = "1";
    if(n==1)
        return data;
    for(int i=1;i<n;i++)
    {
        int freq, j = 0, num = 0;
        string s = "";
        while(j<data.size())
        {
            freq = 1;

            if(j+1>=data.size())
                j++;

            else
            {
                while(data[j]==data[j+1])
                {
                    freq++;
                    j++;
                    if(j+1>=data.size())
                        break;
                }
                j++;

            }
            //cout << int(data[j-1])-int('0') << endl;
            s = s + to_string(freq) + data[j-1];
            //num = num*100 + freq*10 + int(data[j-1])-int('0');
        }

        data = s;
    }
    return data;

}

