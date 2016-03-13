

public class TermNode implements INode{
	public INode leftChild = null;
	public Lexeme operator = null;
	public INode rightChild = null;
	
	@Override
	public Object evaluate(Object[] args) throws Exception {
		double sum = (double)leftChild.evaluate(null);
		
		if(operator == null){
			return sum;
		}
		
		if(operator.token() == Token.MULT_OP){
			sum *= (double)rightChild.evaluate(null);
		}else if(operator.token() == Token.DIV_OP){
			sum /= (double)rightChild.evaluate(null);
		}
		
		return sum;
	}

	@Override
	public void buildString(StringBuilder builder, int tabs) {		
		if(leftChild == null){
			throw new NullPointerException("Nullpointer | Term #1");
		}else{
			builder.append(addTabs(tabs++));
			builder.append("TermNode\n");
			leftChild.buildString(builder, tabs);
			
			if(operator != null){
				builder.append(buildersLittleHelper(operator, tabs));
				
				if(rightChild == null){
					throw new NullPointerException("Nullpointer | Term #2");
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
