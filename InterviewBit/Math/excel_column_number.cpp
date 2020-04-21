//  https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    int id = 0;
    int len = A.size();
    int i = 0;
    while(i<len)
    {
        id += pow(26, len-i-1)*(int(A[i])-int('A')+1);
        i++;
    }
    return id;
}

