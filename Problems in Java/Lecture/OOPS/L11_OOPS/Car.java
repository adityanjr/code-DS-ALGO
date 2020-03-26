package L11_OOPS;

public class Car extends Vehicle {
	String color;
	String companyName;
	
	public Car(String companyName, int price) {
		super(price);
		this.companyName = companyName;
	}
	
	/*public Car() {
		System.out.println("Car");
	}*/
	
	protected void abc() {
		System.out.println("Car!");
	}
}
