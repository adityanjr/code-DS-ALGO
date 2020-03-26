package L23;

import java.util.Scanner;

public class Player {
	String name;
	char symbol;
	
	public static Player takeInput() {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter name : ");
		String playerName = s.next();
		System.out.println("Enter symbol"); 
		char symbol = s.next().charAt(0);
		Player newPlayer = new Player();
		newPlayer.name = playerName;
		newPlayer.symbol = symbol;
		
		return newPlayer;
	}
	
	
	
}
