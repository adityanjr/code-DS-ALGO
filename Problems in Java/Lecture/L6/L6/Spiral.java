package Practice;

public class Spiral {

	public static void spiralPrint(int matrix[][]){
		int row = matrix.length;
		int col = matrix[0].length;

		int i, k = 0, l = 0;

		while(k <= row-1 && l <= col-1){
			for(i = l; i <= col; ++i) {
				System.out.print(matrix[k][i]+ " ");
			}           
			k++;

			for(i = k; i <= row; ++i) {
				System.out.print(matrix[i][col] + " ");
			}
			col--;

			for(i = col; i >= l; --i) {
				System.out.print(matrix[row][i] + " ");
			}
			row--;

			for(i = row; i >= k; --i) {
				System.out.print(matrix[i][l] + " ");
			}
			l++;
		}
	}

	public static void main(String[] args) {
		int a[][] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
		spiralPrint(a);
	}

}
