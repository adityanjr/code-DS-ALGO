package L12_OOPS2;

public class MyClass {

	public static Pair display() {
		Pair p = new Pair(10, 20);
		return p;
	}
	
	public static<T extends Comparable<T>> void bubbleSort(T[] a) {
		for(int j = 0; j < a.length; j++) {
			for(int i = 0; i < a.length-1-j; i++) {
				if(a[i].isGreater(a[i+1])) {
					T temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		/*Pair ans = display();
		System.out.println(ans.x);
		System.out.println(ans.y);*/
		
		/*PairGeneric<Integer> p = new PairGeneric<Integer>();
		p.x = 10;
		
		PairGeneric<Double> p2 = new PairGeneric<Double>();*/
		
		/*PairGeneric<Integer, Double> p3 = new PairGeneric<Integer, Double>();
		p3.x = 10;
		p3.y = 100.4;*/
		
//		PairGeneric<Product<Integer>, Double> p4 = new PairGeneric<Product<Integer>, Double>();
//		Object o = new Product();
		
		Product p[] = new Product[10];
		for(int i = 0; i < 10; i++) {
			p[i] = new Product();
			p[i].price = 100 - i;
		}
		bubbleSort(p);
		
		for(int i = 0; i < 10; i++) {
			System.out.println(p[i].price);
		}
		
	}

}
