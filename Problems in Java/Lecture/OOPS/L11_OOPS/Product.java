package L11_OOPS;

public class Product {
	public String name;
	double price;
	
	final int productId;
	
	static int numProducts;
	
	/*public Product() {
		name = null;
		price = 0.0;
	}*/
	
	public Product(String name, double price, int id) {
		this.name = name;
		this.price = price;
		productId = id;
	}
	
	
	public String getName() {
		return name;
	}
	
	public void setName(String n, String pass) {
		if(pass == "xya") {
			
		}
		if(n.length() < 3) {
			name = null;
			return;
		}
		name = n;
	}
		
}
