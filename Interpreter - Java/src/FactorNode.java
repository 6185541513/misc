
public class FactorNode implements INode{
	public Lexeme lexeme = null;
	public boolean isExpression = false;
	public Lexeme leftEnclosure = null;
	public INode expression = null;
	public Lexeme rightEnclosure = null;
	
	@Override
	public Object evaluate(Object[] args) throws Exception {
		String str = "";
		
		if(isExpression){
			str += expression.evaluate(null);
		}else{
			str += lexeme.value();
		}
		
		return  Double.parseDouble(str);
	}

	@Override
	public void buildString(StringBuilder builder, int tabs) {	
		builder.append(addTabs(tabs++));
		builder.append("FactorNode\n");
		
		if(isExpression){
			builder.append(addTabs(tabs) + leftEnclosure + "\n");
			expression.buildString(builder, tabs);
			builder.append(addTabs(tabs) + rightEnclosure + "\n");
		}else{
			builder.append(buildersLittleHelper(lexeme, tabs));
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
