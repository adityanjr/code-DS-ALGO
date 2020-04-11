bool comp(string a, string b) {
    return a+b > b+a;
}
 
string Solution::largestNumber(const vector<int> &A) {
    vector<string> B;
    int zf = 0;
    for(auto a: A) {
        B.push_back(to_string(a));
        if(a)
            zf++;
    }
    if(!zf)
        return "0";
        
    sort(B.begin(), B.end(), comp);
    string result = "";
    for(auto b: B)
        result += b;
    return result;
}
