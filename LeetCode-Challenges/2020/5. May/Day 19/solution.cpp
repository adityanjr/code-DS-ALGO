class StockSpanner {
public:
    stack <pair<int,int>> s;
    StockSpanner() {
        
        
    }
    
    int next(int price) {
        int val=1;
        if(s.empty())
        {
            s.push(make_pair(1,price));
            return 1;
        }
        if(price<s.top().second)
        {
            s.push(make_pair(1,price));
            return 1;
        }
        
       
        while(!s.empty() && price>=(s.top()).second)
        {
            val=val+(s.top()).first;
            s.pop();
        }
        s.push(make_pair(val,price));
        
        return val;
        
    }
};
