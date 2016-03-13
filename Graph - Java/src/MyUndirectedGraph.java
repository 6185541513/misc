
import java.util.*;

public class MyUndirectedGraph<T> implements UndirectedGraph<T> 
{
	private HashSet<T> nodeSet = new HashSet<T>();  	
	private ArrayList<Edge<T>> edgeList = new ArrayList<Edge<T>>();

	public boolean add(T newNode){
		if(nodeSet.contains(newNode)){
			return false;
		}else{
			nodeSet.add(newNode);
			return true;
		}
	}

	public boolean connect(T node1, T node2, int cost)
	{
		if(!nodeSet.contains(node1) || !nodeSet.contains(node2)){
			return false;
		}

		for(Edge<T> edge : edgeList){
			if(edge.getNode1().equals(node1) && edge.getNode2().equals(node2) || 
					edge.getNode1().equals(node2) && edge.getNode2().equals(node1)){
				edge.setCost(cost);
				return true;
			}
		}

		edgeList.add(new Edge<T>(node1, node2, cost));
		return true;
	}

	public int getCost(T node1, T node2){

		if(!nodeSet.contains(node1) || !nodeSet.contains(node2)){
			return -1;
		}

		int tmpCost = -1;
		for(Edge<T> edge : edgeList){
			if(edge.getNode1().equals(node1) && edge.getNode2().equals(node2) ||
					edge.getNode1().equals(node2) && edge.getNode2().equals(node1)){
				tmpCost = edge.getCost();
			}
		}
		return tmpCost;
	}

	public MyUndirectedGraph<T> minimumSpanningTree(){
		MyUndirectedGraph<T> graphMST = new MyUndirectedGraph<T>();

		Collections.sort(edgeList);
		for(Edge<T> edge : edgeList){
			if(!graphMST.pathExists(edge.getNode1(), edge.getNode2())){
				if(!graphMST.nodeSet.contains(edge.getNode1()) || !graphMST.nodeSet.contains(edge.getNode2()) || 
						graphMST.nodeSet.contains(edge.getNode1()) && graphMST.nodeSet.contains(edge.getNode2())) {
					addMST(edge, graphMST);
				}
			}
		}
		return graphMST;
	}

	public boolean addMST(Edge<T> edge, MyUndirectedGraph<T> graph){
		graph.add(edge.getNode1());
		graph.add(edge.getNode2());
		graph.connect(edge.getNode1(), edge.getNode2(), edge.getCost());
		return true;
	}

	public boolean pathExists(T nodeFrom, T nodeTo){
		Set<T> usedNodeSet = new HashSet<T>();
		depthFirstSearch(nodeFrom, usedNodeSet);
		return usedNodeSet.contains(nodeTo);
	}

	public void depthFirstSearch(T nodeOutset, Set<T> usedNodeSet){
		usedNodeSet.add(nodeOutset);
		for(Edge<T> edge : edgeList){			
			if(edge.getNode1().equals(nodeOutset)){
				if(!usedNodeSet.contains(edge.getNode2())){
					depthFirstSearch(edge.getNode2(), usedNodeSet);
				}
			}else if(edge.getNode2().equals(nodeOutset)){
				if(!usedNodeSet.contains(edge.getNode1())){
					depthFirstSearch(edge.getNode1(), usedNodeSet);
				}
			}
		}
	}
}

