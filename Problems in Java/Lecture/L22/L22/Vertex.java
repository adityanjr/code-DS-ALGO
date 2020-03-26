package L22;

import java.util.ArrayList;

public class Vertex {
	String name;
	ArrayList<Edge> adjacent;
	
	public Vertex(String name) {
		this.name = name;
		adjacent = new ArrayList<Edge>();
	}
}
