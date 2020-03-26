package L23;

public class Board {
	char board[][];
	char p1Symbol;
	char p2Symbol;
	
	 final static int INCOMPLETE = 0;
	 final static int Player1_WON = 1;
	 final static int Player2_Won = 2;
	 final static int DRAW = 3;
	
	public Board(char p1Symbol, char p2Symbol) {
		board = new char[3][3];
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				board[i][j] = '0';
			}
		}
		this.p1Symbol = p1Symbol;
		this.p2Symbol = p2Symbol;
	}

	public boolean makeMove(int x, int y, char symbol) {
		if(x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != '0') {
			return false;
		}
		board[x][y] = symbol;
		return true;
	}

	public int gameStatus() {
		
		// Check if P1 won ?
		// Check for Rows
		for(int i = 0; i < 3; i++) {
			if(board[i][0] != '0' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
				if(board[i][0] == p1Symbol) {
					return Player1_WON;
				}
				else {
					return Player2_Won;
				}
			}
		}
		
		// Check for columns
		for(int j = 0; j < 3; j++) {
			if((board[0][j] != '0') && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
				if(board[0][j] == p1Symbol) {
					return Player1_WON;
				}
				else {
					return Player2_Won;
				}
			}
		}
		
		// Check for diagonals
		if((board[0][0] != '0') && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
			if(board[0][0] == p1Symbol) {
				return Player1_WON;
			}
			else {
				return Player2_Won;
			}
		}
		if((board[0][2] != '0') && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
			if(board[0][2] == p1Symbol) {
				return Player1_WON;
			}
			else {
				return Player2_Won;
			}
		}
 		
		// Check for Incomplete
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(board[i][j] == '0') {
					return INCOMPLETE;
				}
			}
		}
		
		return DRAW;
	}

	public void print() {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				System.out.print(board[i][j] + "  ");
			}
			System.out.println();
		}
		
	}
}
