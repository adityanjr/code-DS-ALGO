class CombinationIterator {
public:
    queue<string> q;
    
    CombinationIterator(string characters, int combinationLength) {
        combinations(characters, 0, "", combinationLength);
    }
    
    string next() {
        string next = q.front();
        q.pop();
        
        return next;
    }
    
    bool hasNext() {
        return !q.empty();
    }
    
    void combinations(string characters, int pos, string soFar, int combinationLength) {
        if(soFar.size() == combinationLength) {
            q.push(soFar);
            return;
        }
        
        for(int i = pos; i < characters.size(); ++i) {
            soFar.push_back(characters[i]);
            
            combinations(characters, i + 1, soFar, combinationLength);
            
            soFar.pop_back();
        }
        
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */