package L3;

public class VariablesScope {

	public static void abc() {
		/*int n = 5;
		while(n > 0) {
			int a = 9;
			n = n-1;
		}
		System.out.println(n);*/
		
		int n = 4;
		n = 8;
		
		System.out.println(n);
		if(n == 4) {
			int a = 10;
//			int n = 5;
		}
		else {
			int a = 9;
//			System.out.println(a);
		}
		
	}
	
	public static void main(String[] args) {
		abc();
	}

}
