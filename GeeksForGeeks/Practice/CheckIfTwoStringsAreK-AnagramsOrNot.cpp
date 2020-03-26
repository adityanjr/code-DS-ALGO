/*Complete the function below*/
#include <map>

struct s{
    int f;
    int s;
};

bool areKAnagrams(string str1, string str2, int k)
{
    if(str1.size() != str2.size()){
        return false;
    }
    
    map<char, s> m;
    
    for(int i = 0; i < str1.size(); i++){
        if(m.find(str1[i]) == m.end()){
            s ss;
            ss.f = 1;
            ss.s = 0;
            m[str1[i]] = ss;
        }
        else{
            m[str1[i]].f = m[str1[i]].f + 1; 
        }
        if(m.find(str2[i]) == m.end()){
            s ss;
            ss.f = 0;
            ss.s = 1;
            m[str2[i]] = ss;
        }
        else{
            m[str2[i]].s = m[str2[i]].s + 1; 
        }
    }
    
    map<char, s> :: iterator it = m.begin();
    
    int temp = 0;
    
    while(it != m.end()){
        temp = temp + abs((it->second).f - (it->second).s);
        it++;
    }
    
    if(temp/2 <= k){
        return true;
    }
    
    return false;
}
