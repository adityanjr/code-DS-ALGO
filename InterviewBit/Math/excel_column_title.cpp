//  https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int A) {
    string s = "";
    while(A > 0)
    {
        A--;
        s = char(A%26 + 'A') + s;
        A /= 26;
    }
    return s;
}

