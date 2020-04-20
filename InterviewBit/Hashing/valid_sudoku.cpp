//  https://www.interviewbit.com/problems/valid-sudoku/

bool validRow(const vector<string> &A) {
    
    for(int i=0;i<A.size();i++) {
        
        vector<int> row(10, 0);
        
        for(int j=0;j<A[i].size();j++) {
            
            int d = A[i][j]-'0';
            if(d>0 && d<=9) {
                row[d]++;
                if(row[d]>1)
                    return false;
            }
            else if(A[i][j]!='.')
                return false;
        }
        
    }
    return true;
}

bool validColumn(const vector<string> &A) {
    
    for(int i=0;i<A.size();i++) {
        
        vector<int> row(10, 0);
        
        for(int j=0;j<A[i].size();j++) {
            
            int d = A[j][i]-'0';
            if(d>0 && d<=9) {
                row[d]++;
                if(row[d]>1)
                    return false;
            }
            else if(A[j][i]!='.')
                return false;
        }
       
    }
    return true;
}

bool validGrid(const vector<string> &A) {
    
    int k = 0, a=0, b=0;
    while(k<9) {
        vector<int> row(10, 0);
        int a = 3*(k/3);
        int b;
        if(k%3==0)
            b = 0;
        else 
            b += 3;
        for(int i=a;i<3+a;i++) {
            
            for(int j=b;j<3+b;j++) {
                
                int d = A[i][j]-'0';
                if(d>0 && d<=9) {
                    row[d]++;
                    if(row[d]>1)
                        return false;
                }
                else if(A[i][j]!='.')
                    return false;
            }
        }
        
        k++;
        
    }
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    
    if(validRow(A) && validColumn(A) && validGrid(A))
        return 1;
    return 0;
}



############ OR ###########


void clearMap(unordered_map<char, int> &mp) {
    unordered_map<char, int>::iterator it = mp.begin();
    while(it!=mp.end()) {
        mp.erase(it);
        it=mp.begin();
    }
}

bool validRow(const vector<string> &A) {
    int n = A.size();
    
    for(int i=0;i<n;i++) {
        unordered_map<char, int> mp;
        for(int j=0;j<n;j++) {
            if(A[i][j]!='.') {
                if(A[i][j]-'0'<0 || A[i][j]-'0'>9 || mp.find(A[i][j])!=mp.end())
                    return false;
                else
                    mp.insert(make_pair(A[i][j], 1));
            }
        }
        clearMap(mp);
    }
    return true;
}

bool validColumn(const vector<string> &A) {
    int n = A.size();
    
    for(int i=0;i<n;i++) {
        unordered_map<char, int> mp;
        for(int j=0;j<n;j++) {
            if(A[j][i]!='.') {
                if(A[j][i]-'0'<0 || A[j][i]-'0'>9 || mp.find(A[j][i])!=mp.end())
                    return false;
                else
                    mp.insert(make_pair(A[j][i], 1));
            }
        }
        /*
        for(auto it=mp.begin();it!=mp.end();it++)
            cout << it->first << " ";
        cout << endl;
        */
        clearMap(mp);
    }
    return true;
}

bool validGrid(const vector<string> &A) {
    int n = A.size();
    int a;
    for(int k=0;k<n;k++) {
        if(k<3)
            a = 0;
        else if(k<6)
            a = 3;
        else 
            a = 6;
        unordered_map<char, int> mp;
        for(int i=a;i<a+3;i++) {
            for(int j=3*(k%3);j<3*(k%3)+3;j++) {
                if(A[i][j]!='.') {
                    if(A[i][j]-'0'<0 || A[i][j]-'0'>9 || mp.find(A[i][j])!=mp.end())
                        return false;
                    else
                        mp.insert(make_pair(A[i][j], 1));
                }
            }
        }
        
        
        clearMap(mp);
    }
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    
    if(validRow(A) && validColumn(A) && validGrid(A))
        return 1;
    return 0;
    
}


