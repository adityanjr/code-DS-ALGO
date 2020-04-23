//  https://www.interviewbit.com/problems/compare-version-numbers/

#include <string>
int Solution::compareVersion(string A, string B) {
    int n, m;
    n = A.size();
    m = B.size();
    
    int i, j;
    i = j = 0;
    
    while(i<n || j<m) {
        string s1, s2;
        
        while(i<n && A[i]!='.') {
            s1 += A[i];
            i++;
        }
        s1.erase(0, s1.find_first_not_of('0'));
        if(s1=="0")
            s1 = "";
        int flag1 = false, flag2 = false, check = false;
        while(j<m && B[j]!='.') {
            s2 += B[j];
            s2.erase(0, s2.find_first_not_of('0'));
            if(s2.size()<=s1.size() && !check) {
                if(s2[j]>s1[j]) {
                    check = flag2 = true;
                } else if(s2[j]<s1[j]) {
                    check = true;
                    flag1 = true;
                }
            }
            j++;
        }
        
        // cout << s1 << " " << s2 << endl;
        
        if(s1.size()>s2.size())
            return 1;
        if(s2.size()>s1.size())
            return -1;
        
        if(s1==s2) {
            flag1 = flag2 = false;
        }
        
        if(flag1)
            return 1;
        else if(flag2)
            return -1;
        
        i++;
        j++;
    }
    
    return 0;
}
