

import java.io.IOException;

public class Parser implements IParser {
	Tokenizer tokenizer = new Tokenizer();
	int tabs = 0;
	
	@Override
	public void open(String fileName) throws IOException, TokenizerException {
		tokenizer.open(fileName);
	}

	@Override
	public INode parse() throws IOException, TokenizerException,
			ParserException {	
		tokenizer.moveNext();
		
		AssignmentNode rootNode = new AssignmentNode();
		Token currentToken = tokenizer.current().token(); 
		
		if(currentToken != Token.IDENT){
			throw new ParserException("Syntax Error | Identifier not found");
		}else{
			rootNode.leftChild = tokenizer.current();	
			tokenizer.moveNext();			
			currentToken = tokenizer.current().token();
			
			if(currentToken != Token.ASSIGN_OP){
				throw new ParserException("Syntax Error | Assign operator not found");
			}else{	
				rootNode.operator = tokenizer.current();
				tokenizer.moveNext();
				currentToken = tokenizer.current().token();				
				rootNode.rightChild = parseExpression();
				currentToken = tokenizer.current().token();
			
				if(currentToken != Token.SEMICOLON){
					throw new ParserException("Syntax Error | Semicolon not found");
				}else{
					rootNode.semicolon = tokenizer.current();
				}
			}
		}
		
		return rootNode;
	}
	
	public INode parseExpression() throws TokenizerException, IOException, ParserException{	
		ExpressionNode current = new ExpressionNode();
		current.leftChild = parseTerm();
		Token currentToken = tokenizer.current().token();
		
		if(currentToken != Token.ADD_OP && currentToken != Token.SUB_OP && currentToken != Token.RIGHT_PAREN && currentToken != Token.SEMICOLON){
			throw new ParserException("Syntax Error | Incorrect expression");
		}else{
			if(currentToken == Token.ADD_OP || currentToken == Token.SUB_OP){
				current.operator = tokenizer.current();
				tokenizer.moveNext();
				current.rightChild = parseExpression();
			}
		}
		
		return current;
	}
	
	public INode parseTerm() throws TokenizerException, IOException, ParserException{	
		TermNode current = new TermNode();
		current.leftChild = parseFactor();
		Token currentToken = tokenizer.current().token();
			
		if(currentToken != Token.MULT_OP && currentToken != Token.DIV_OP && currentToken != Token.ADD_OP 
				&& currentToken != Token.SUB_OP && currentToken != Token.RIGHT_PAREN && currentToken != Token.SEMICOLON){
			throw new ParserException("Syntax Error | Incorrect term");
		}else {
			if(currentToken == Token.MULT_OP || currentToken == Token.DIV_OP){
				current.operator = tokenizer.current();
				tokenizer.moveNext();			
				current.rightChild = parseTerm();
			}
		}
		
		return current;
	}
	
	public INode parseFactor() throws TokenizerException, IOException, ParserException{
		FactorNode current = new FactorNode();
		Token currentToken = tokenizer.current().token();
		
		if(currentToken != Token.INT_LIT && currentToken != Token.LEFT_PAREN){
			throw new ParserException("Syntax Error | Incorrect factor #1");
		}else{
			if(currentToken == Token.INT_LIT){
				current.lexeme = tokenizer.current();
				tokenizer.moveNext();
			}else{
				current.leftEnclosure = tokenizer.current();
				tokenizer.moveNext();				
				current.expression = parseExpression();	
				currentToken = tokenizer.current().token();
				
				if(currentToken != Token.RIGHT_PAREN){
					throw new ParserException("Syntax Error | Incorrect factor #2");
				}else{
					current.rightEnclosure = tokenizer.current();
					current.isExpression = true;
					tokenizer.moveNext();
				}
			}
		}
		
		return current;
	}

	@Override
	public void close() throws IOException {
		tokenizer.close();
	}

}
