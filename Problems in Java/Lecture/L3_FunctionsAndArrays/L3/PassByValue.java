package L3;

public class PassByValue {

	public static int check(int a) {
		a = a + 1;
		System.out.println("Inside function " + a);
		return a;
	}
	
	public static void A() {
		System.out.println("Inside A");
		B();
		System.out.println("After calling B");
	}
	
	public static void B() {
		System.out.println("Inside B");
	}
	
	
	public static void main(String[] args) {
//		int a = 10;
//		check(a);
//		System.out.println("Inside Main : " + a);
//		a = check(a);
//		System.out.println("Inside main 2 : " + a);
		
		System.out.println("Inside Main");
		A();
		
		System.out.println("After calling A");
	}

}
