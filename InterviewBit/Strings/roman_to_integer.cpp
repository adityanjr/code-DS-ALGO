//  https://www.interviewbit.com/problems/roman-to-integer/

int Solution::romanToInt(string A) {
    map<char, int> roman_value;
    roman_value['I'] = 1;
    roman_value['V'] = 5;
    roman_value['X'] = 10;
    roman_value['L'] = 50;
    roman_value['C'] = 100;
    roman_value['D'] = 500;
    roman_value['M'] = 1000;
    
    int num = 0, curr = 0, next = 0;
    
    if(A.size()==0)
        return 0;
    
    if(A.size()==1)
        return roman_value[A[0]];
        
    
    for(int i=0;i<A.size()-1;i++)
    {
        curr = roman_value[A[i]];
        next = roman_value[A[i+1]];
        
        if(next > curr)
            num = num - curr;
        else
            num = num + curr;
    }
    num += next;
    return num;
}

