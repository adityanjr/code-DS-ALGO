class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k)
        {
            return "0";
        }
            string final1="";
         while(k>0)
           {
             int m=k;
            for(int i=0;i<num.size()-1;i++)
            {
                if(k>0 &&  num[i]>num[i+1])
                {
                    num.erase(num.begin()+i);
                    k--;
                    break;
                }
            }
            if(k==m)
            {
                break;
            }
          }
         while(k>0)
         {
             num.erase(num.begin()+num.size()-1);
             k--;
         }
        while(num.size()>1 && num[0]=='0')
        {
            num.erase(num.begin());
        }

        return num;

    }
};
