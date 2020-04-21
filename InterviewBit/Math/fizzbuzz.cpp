//  https://www.interviewbit.com/problems/fizzbuzz/

vector<string> Solution::fizzBuzz(int A) {
    vector<string> data;
    
    for(int i=1;i<=A;i++)
    {
        if(i%3==0 && i%5==0)
            data.push_back("FizzBuzz");
        else if(i%3==0)
            data.push_back("Fizz");
        else if(i%5==0)
            data.push_back("Buzz");
        else
        {
            stringstream ss;
            ss << i;
            string s = ss.str();
            data.push_back(s);
        }
    }
    return data;
}

