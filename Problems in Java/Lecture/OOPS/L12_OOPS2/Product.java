package L12_OOPS2;

public class Product implements Comparable<Product>{
	int ID;
	int price;
		
	public boolean isGreater(Product p) {
		if(this.price > p.price) {
			return true;
		}
		else {
			return false;
		}
	}
	
	/*public void display() {
		System.out.println(ID);
		System.out.println(price);
		System.out.println("Product");
	}*/
}
