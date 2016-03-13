
public class ExpressionNode implements INode{
	public INode leftChild = null;
	public Lexeme operator = null;
	public INode rightChild = null;

	@Override
	public Object evaluate(Object[] args) throws Exception {
		double sum = (double) leftChild.evaluate(null);
		
		if(operator == null){
			return sum;
		}
		
		if(operator.token() == Token.ADD_OP){
			sum += (double)rightChild.evaluate(null);
		}else if(operator.token() == Token.SUB_OP){
			sum -= (double)rightChild.evaluate(null);
		}
		
		return sum;
	}

	@Override
	public void buildString(StringBuilder builder, int tabs) {		
		if(leftChild == null){
			throw new NullPointerException("Nullpointer | Expression #1");
		}else{
			builder.append(addTabs(tabs++));
			builder.append("ExpressionNode\n");
			leftChild.buildString(builder, tabs);
			
			if(operator != null){
				builder.append(buildersLittleHelper(operator, tabs));
				
				if(rightChild == null){
					throw new NullPointerException("Nullpointer | Expression #2");
				}else{
					rightChild.buildString(builder, tabs);
				}
			}
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
