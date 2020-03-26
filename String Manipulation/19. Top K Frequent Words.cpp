// # Top K Frequent Words

// ## PROBLEM STATEMENT

// Given an array of terms `s1 s2 s3 ... sn`, length of the array `n` and a total number
//  of output terms `k`, write the top `k` frequent terms.

// ## POINT OF THIS ALGORITHM

// 1. Using `unordered_map` to store input terms. This STL Container has constant time access for adding and accessing.
// 2. Using lambda expresions to sort terms. 


#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int k;
  cin >> k;

  int n;
  cin >> n;

  unordered_map<string, int> m;
  for (size_t i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    m[s]++;
  }

  vector<pair<string, int>> v;
  for (const auto &it : m)
  {
    v.push_back(make_pair(it.first, it.second));
  }

  sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) -> bool {
    return a.second > b.second || (a.second == b.second && a.first < b.first);
  });

  for (size_t i = 0; i < k && i < v.size(); i++)
  {
    cout << v[i].first << endl;
  }
}