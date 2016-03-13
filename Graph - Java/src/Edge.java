
public class Edge<T> implements Comparable<Edge<T>>
	{
		private T node1;
		private T node2;
		private int cost;

		public Edge(T node1, T node2, int cost){
			this.node1 = node1;    
			this.node2 = node2;    
			this.cost = cost;
		}
		
		public T getNode1(){
			return node1;
		}

		public T getNode2(){
			return node2;
		}
		
		public int getCost(){
			return cost;
		}
		
		public void setCost(int newCost){
			cost = newCost;
		}

		public int compareTo(Edge<T> otherEdge){
			if(this.cost > otherEdge.cost)
				return 1;
			else if (this.cost < otherEdge.cost)
				return -1;
			else
				return 0;
		}

		public String toString()
		{
			return "The road between " + node1 + " and " + node2 + " is worth " + cost + ".";
		}
	}
