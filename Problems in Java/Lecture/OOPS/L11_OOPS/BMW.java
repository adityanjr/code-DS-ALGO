package L11_OOPS;

public class BMW extends Car {
	int modelID;
	
	public BMW(String name, int price) {
		super(name, price);
	}
	
	public void abc() {
		System.out.println("BMW");
	}
}
