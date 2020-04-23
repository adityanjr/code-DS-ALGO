//  https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int A) {
    string result = "";
    
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    result = M[A/1000] + C[(A%1000)/100] + X[(A%100)/10] + I[A%10];
    return result;
}

