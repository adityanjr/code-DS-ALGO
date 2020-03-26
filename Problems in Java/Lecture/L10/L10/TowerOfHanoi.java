package L10;

public class TowerOfHanoi {

	public static void countSteps(int disks, char S, char A, char D) {
		if(disks == 0) {
			return;
		}
		if(disks == 1) {
			System.out.println(S + "->" + D);
			return;
		}
		countSteps(disks-1, S, D, A);
		countSteps(1, S, A, D);
		countSteps(disks-1, A, S, D);
	}
	
	public static void main(String[] args) {
		countSteps(3, 'S', 'A', 'D');
	}

}
