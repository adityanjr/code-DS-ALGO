//  https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > res;
    auto size = A.size();
    for (auto i = 0; i<size-3; ++i)
    {
        if (i>0 && A[i] == A[i-1])
            continue;
        for (auto j = i+1; j<size-2; ++j)
        {
            if (j>i+1 && A[j] == A[j-1])
                continue;
                
            int ptr1 = j+1, ptr2 = size-1;
            while (ptr1 < ptr2)
            {
                auto sum = A[i] + A[j] + A[ptr1] + A[ptr2];
                if (sum == B)
                {
                    vector<int> temp;
                    temp.emplace_back(A[i]);
                    temp.emplace_back(A[j]);
                    temp.emplace_back(A[ptr1]);
                    temp.emplace_back(A[ptr2]);
                    res.emplace_back(temp);
                    ++ptr1;
                    while (ptr1<ptr2 && A[ptr1] == A[ptr1-1])
                        ++ptr1;
                }
                else if (sum > B)
                    --ptr2;
                else if (sum < B)
                    ++ptr1;
            }
        }
    }
    return res;
}
