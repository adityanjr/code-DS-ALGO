/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this function*/
void printMat(int M[MAX][MAX],int row,int col)
{
//Your code here
    map<string, vector<int> > m;
    
    for(int i = 0; i < row; i++){
        string ans = "";
        for(int j = 0; j < col; j++){
            ans += to_string(M[i][j]);
        }
        if(m.find(ans) == m.end()){
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << "$";        
        }
        m[ans].push_back(i);
    }
    
}
