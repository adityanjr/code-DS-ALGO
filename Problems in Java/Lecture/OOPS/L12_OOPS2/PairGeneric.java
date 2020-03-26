package L12_OOPS2;

public class PairGeneric<T, V> {
	T x;
	V y;
	
	/*PairGeneric(T x, T y) {
		this.x = x;
		this.y = y;
	}*/
	
	public T getX() {
		return x;
	}
	
	public V getY() {
		return y;
	}
	
	public void setX() {
		this.x = x;
	}
	
	public void setY() {
		this.y = y;
	}
}
