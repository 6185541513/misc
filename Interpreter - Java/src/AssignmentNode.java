
public class AssignmentNode implements INode{
	public Lexeme leftChild = null;
	public Lexeme operator = null;
	public INode rightChild = null;
	public Lexeme semicolon = null;

	@Override
	public Object evaluate(Object[] args) throws Exception {
		return rightChild.evaluate(null);		
	}

	@Override
	public void buildString(StringBuilder builder, int tabs) {		
		if(leftChild == null || operator == null || rightChild == null || semicolon == null){
			throw new NullPointerException("Nullpointer | Assignment");
		}else{
			builder.append(addTabs(tabs++));
			builder.append("AssignmentNode\n");
			builder.append(buildersLittleHelper(leftChild, tabs));
			builder.append(buildersLittleHelper(operator, tabs));
			rightChild.buildString(builder, tabs);
			builder.append(buildersLittleHelper(semicolon, tabs));
		}
	}
		
	private String buildersLittleHelper(Lexeme lexeme, int tabs){			
		return (addTabs(tabs) + lexeme.token() + " " + lexeme.value() + "\n");
	}
	
	private String addTabs(int tabs){		
		String str = "";
		while(tabs > 0){
			str += "\t";
			tabs--;
		}
		
		return str;
	}

}
