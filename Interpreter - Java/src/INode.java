
public interface INode {
	Object evaluate(Object[] args) throws Exception; 
	
	void buildString(StringBuilder builder, int tabs);
}