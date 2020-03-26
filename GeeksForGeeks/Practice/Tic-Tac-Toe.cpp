#include <iostream>
#include <vector>

using namespace std;

bool count(vector<vector<char> >& board){
    int x = 0, o = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'O'){
                o++;
            }
            else{
                x++;
            }
        }
    }
    
    return x-o == 1;
}

bool winRow(char c, vector<char>& vec){
    for(int i = 1; i < 3; i++){
        if(vec[i] != c){
            return false;
        }    
    }
    
    return true;
}

bool winCol(char c, int col, vector<vector<char> >& board){
    for(int i = 1; i < 3; i++){
        if(board[i][col] != c){
            return false;
        }
    }
    
    return true;
}

bool checkDiagonal(char c, vector<vector<char> >& board){
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c){
        return true;
    }
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c){
        return true;
    }
    
    return false;
}

bool valid(vector<vector<char> >& board){
    if(!count(board)){
        return false;
    }
    
    bool xrow = false, xcol = false;
    
    for(int i = 0; i < 3; i++){
        if(board[i][0] == 'O' && winRow('O', board[i])){
            return false;
        }
        if(board[i][0] == 'X' && winRow('X', board[i])){
            if(xrow){
                return false;
            }
            xrow = true;
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(board[0][i] == 'O' && winCol('O', i, board)){
            return false;
        }
        if(board[0][i] == 'X' && winCol('X', i, board)){
            if(xcol){
                return false;
            }
            xcol = true;
        }
    }
    
    if(checkDiagonal('O', board)){
        return false;
    }
    
    return true;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    vector<vector<char> > board(3, vector<char>(3));
	    
	    for(int i = 0; i < 3; i++){
	        for(int j = 0; j < 3; j++){
	            cin >> board[i][j];
	        }
	    }
	    
	    string ans = "Invalid";
	    
	    if(valid(board)){
	        ans = "Valid";
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
