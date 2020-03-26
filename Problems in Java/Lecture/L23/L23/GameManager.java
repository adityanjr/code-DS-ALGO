package L23;

import java.util.Scanner;

public class GameManager {
	Board b;
	Player p1;
	Player p2;

	public GameManager() {
		Scanner s = new Scanner(System.in);
		Player p1 = Player.takeInput();
		Player p2 = Player.takeInput();
		boolean done = false;
		do {
			if(p1.symbol != p2.symbol) {
				done = true;
			}
			else {
				System.out.println("Please select different symbol !!");
				p2 = Player.takeInput();
			}
		} while(!done);
		
		b = new Board(p1.symbol, p2.symbol);
		
		boolean p1Turn = true;

		// 0 - Incomplete; 1 - P1 won; 2 - P2 won; 3 - Draw
		while(b.gameStatus() == Board.INCOMPLETE) {
			b.print();
			if(p1Turn) {
				boolean moved = false;
				do {
					System.out.println(p1.name + "'s turn : ");
					System.out.println("Enter x and y : ");
					int x = s.nextInt();
					int y = s.nextInt();
					moved = b.makeMove(x, y, p1.symbol);

				} while(!moved);
				p1Turn = !p1Turn;
			}
			else {
				boolean moved = false;
				do {
					System.out.println(p2.name + "'s turn : ");
					System.out.println("Enter x and y : ");
					int x = s.nextInt();
					int y = s.nextInt();
					moved = b.makeMove(x, y, p2.symbol);
					
				} while(!moved);
				p1Turn = !p1Turn;
			}
		}

		b.print();
		// Game completed
		if(b.gameStatus() == Board.Player1_WON) {
			System.out.println(p1.name + " won !!");
		}
		else if(b.gameStatus() == Board.Player2_Won) {
			System.out.println(p2.name + " won !!");
		}
		else {
			System.out.println("Draw !!");
		}
	}

	public static void main(String[] args) {
		GameManager g = new GameManager();
		//		g.start();
	}
}
