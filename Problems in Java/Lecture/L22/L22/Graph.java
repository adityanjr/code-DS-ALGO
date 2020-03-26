package L22;

import java.util.ArrayList;

public class Graph {
	private String name;
	private ArrayList<Vertex> vertices;
	
	public Graph(String name) {
		this.name = name;
		vertices = new ArrayList<Vertex>();
	}
	
	public boolean isEmpty() {
		return vertices.size() == 0;
	}
	
	public int numVertices() {
		return vertices.size();
	}
	
	public int totalNumEdgesInGraph() {
		int count = 0;
		for(Vertex v : vertices) {
			count += v.numEdgesOfVertex();
		}
		return count / 2;
	}
	
	private Vertex getVertexFromName(String name) {
		for(Vertex v : vertices) {
			if(v.name.equals(name)) {
				return v;
			}
		}
		return null;
	}
	
	public int getDegree(String name) throws VertexNoFoundException {
		Vertex v = getVertexFromName(name);
		if(v == null) {
			VertexNoFoundException e = new VertexNoFoundException();
			throw e;
		}
		return v.numEdgesOfVertex();
	}
	
	public void addVertex(String name) {
		Vertex v = getVertexFromName(name);
		if(v != null) {
//			DuplicateVertexFound e = new DuplicateVertexFound();
//			throw e;
		}
		Vertex newVertex = new Vertex(name);
		vertices.add(newVertex);
	}
	
	public void addEdge(String first, String second) throws VertexNoFoundException {
		Vertex firstVertex = getVertexFromName(name);
		Vertex secondVertex = getVertexFromName(name);
		if(firstVertex == null || secondVertex == null) {
			VertexNoFoundException e = new VertexNoFoundException();
			throw e;
		}
		Edge newEdge = new Edge(firstVertex, secondVertex);
		firstVertex.addEdge(newEdge);
		secondVertex.addEdge(newEdge);
	}
	
	public void removeVertex(String name) throws VertexNoFoundException {
		Vertex v = getVertexFromName(name);
		if(v == null) {
			VertexNoFoundException e = new VertexNoFoundException();
			throw e;
		}
		for(Vertex v1 : vertices) {
			
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
