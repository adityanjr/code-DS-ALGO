//  https://www.interviewbit.com/problems/gray-code/

void generateCode(int A, int index, vector<string> &G) {
    if(index>A)
        return;
    vector<string> R(G);
    reverse(R.begin(), R.end());
    for(auto i=0;i<G.size();i++)
        G[i] = "0"+G[i];
    for(auto i=0;i<R.size();i++)
        R[i] = "1"+R[i];
    G.insert(G.end(), R.begin(), R.end());
    generateCode(A, index+1, G);
}
vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> result;
    vector<int> ans;
    if(A<2) {
        if(A==0)
            ans.push_back(0);
        else if(A==1) {
            ans.push_back(0);
            ans.push_back(1);
        }
        return ans;
    }
    result.push_back("0");
    result.push_back("1");
    generateCode(A, 2, result);
    
    for(auto res: result)
        ans.push_back(stoi(res, nullptr, 2));
        //cout << stoi(res, nullptr, 2) << endl;
    
    return ans;
}

