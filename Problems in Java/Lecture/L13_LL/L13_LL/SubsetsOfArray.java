package L13;

public class SubsetsOfArray {

	public static int[][] subsets(int[] a) {
		if(a.length == 0) {
			int[][] output = new int[1][0];
			return output;
		}
		
		int small[] = new int[a.length-1];
		for(int i = 1; i < a.length; i++) {
			small[i-1] = a[i];
		}
		int smallOutput[][] = subsets(small);
		int output[][] = new int[2*smallOutput.length][];
		
		int k = 0;
		for(int i = 0; i < smallOutput.length; i++) {
			output[k] = new int[smallOutput[i].length];
			for(int j = 0; j < smallOutput[i].length; j++) {
				output[k][j] = smallOutput[i][j];
			}
			k++;
		}
		
		for(int i = 0; i < smallOutput.length; i++) {
			output[k] = new int[smallOutput[i].length+1];
			output[k][0] = a[0];
			for(int j = 0; j < smallOutput[i].length; j++) {
				output[k][j+1] = smallOutput[i][j];
			}
			k++;
		}
		return output;
	}
	
	public static void main(String[] args) {
		int input[] = {1,2,3, 4};
		int output[][] = subsets(input);
		for(int i = 0; i < output.length; i++) {
			for(int j = 0; j < output[i].length; j++) {
				System.out.print(output[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}
