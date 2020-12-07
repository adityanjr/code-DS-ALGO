class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0;
        int carry = 0;
        
        int n = (int) a.size() - 1;
        int m = (int) b.size() - 1;
        
        string op = "";
        
        while(n >=0 || m >= 0) {
            sum = carry;
            
            if(n >= 0) {
                sum += a[n--] - '0';
            }
            
            if(m >= 0) {
                sum += b[m--] - '0';
            }
            
            op += (sum % 2 + '0');
            
            carry = floor(sum / 2);
        }
        
        if(carry > 0) {
            op += "1";
        }
        
        reverse(op.begin(), op.end());
        
        return op;
    }
};