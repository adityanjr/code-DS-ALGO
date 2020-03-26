/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
// Your code goes here
    map<char, pair<int, int> > m;
    
    for(int i = 0; i < str1.size(); i++){
        if(m.find(str1[i]) == m.end()){
            pair<int, int> p(1, 0);
            m[str1[i]] = p;
        }
        else{
            m[str1[i]].first++;
        }
    }

    for(int i = 0; i < str2.size(); i++){
        if(m.find(str2[i]) == m.end()){
            pair<int, int> p(0, 1);
            m[str2[i]] = p;
        }
        else{
            m[str2[i]].second++;
        }
    }

    map<char, pair<int, int> > :: iterator it = m.begin();
    
    int ans = 0;
    
    while(it != m.end()){
        ans += abs((it->second).first - (it->second).second);
        it++;
    }
    
    return ans;
}
