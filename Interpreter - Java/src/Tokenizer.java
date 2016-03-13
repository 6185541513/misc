

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Tokenizer implements ITokenizer{
	Scanner scanner = new Scanner();	
	Lexeme currentLexeme = null;
	
	enum CharClass {LETTER, DIGIT, OTHER, EOF};
	CharClass currentCharClass = null;
	
	String str = "";
	
	@Override
	public void open(String fileName) throws IOException, TokenizerException {
		scanner.open(fileName);
		scanner.moveNext();
		if(scanner.current() == Scanner.NULL){
			throw new TokenizerException("Tokenizer Error | Tokenizing unable to begin");
		}
	}

	@Override
	public Lexeme current() {
		return currentLexeme;
	}
	
	@Override
	public void moveNext() throws IOException, TokenizerException {
		findNonBlankChar();
		switch(currentCharClass){
		case LETTER:
			while(currentCharClass == CharClass.LETTER || currentCharClass == CharClass.DIGIT){
				str += scanner.current();
				scanner.moveNext();
				getChar();
			}
			currentLexeme = new Lexeme(str, Token.IDENT);
			str = "";
			break;
		case DIGIT:
			while(currentCharClass == CharClass.DIGIT){
				str += scanner.current();
				scanner.moveNext();
				getChar();
			}
			currentLexeme = new Lexeme(Double.parseDouble(str), Token.INT_LIT);
			str = "";
			break;
		case OTHER:
			handleOtherCharClass(scanner.current());
			scanner.moveNext();
			break;
		case EOF:
			currentLexeme = new Lexeme("", Token.EOF);
			break;
		}
	}
	
	public void findNonBlankChar() throws IOException{
		while(scanner.current() == ' '){
			scanner.moveNext();
		}
		getChar();
	}
	
	public void getChar(){
		if(scanner.current() != Scanner.EOF){
			if(Character.isLetter(scanner.current())){
				currentCharClass = CharClass.LETTER;
			}else if(Character.isDigit(scanner.current())){
				currentCharClass = CharClass.DIGIT;
			}else{
				currentCharClass = CharClass.OTHER;
			}
		}else{
			currentCharClass = CharClass.EOF;
		}
	}
	
	void handleOtherCharClass(char c) throws TokenizerException{
		switch(c){
		case '+':
			currentLexeme = new Lexeme(c, Token.ADD_OP);
			break;
		case '-':
			currentLexeme = new Lexeme(c, Token.SUB_OP);
			break;
		case '*':
			currentLexeme = new Lexeme(c, Token.MULT_OP);
			break;
		case '/':
			currentLexeme = new Lexeme(c, Token.DIV_OP);
			break;
		case '=':
			currentLexeme = new Lexeme(c, Token.ASSIGN_OP);
			break;
		case '(':
			currentLexeme = new Lexeme(c, Token.LEFT_PAREN);
			break;
		case ')':
			currentLexeme = new Lexeme(c, Token.RIGHT_PAREN);
			break;
		case ';':
			currentLexeme = new Lexeme(c, Token.SEMICOLON);
			break;
		case '{':
			currentLexeme = new Lexeme(c, Token.LEFT_CURLY);
			break;
		case '}':
			currentLexeme = new Lexeme(c, Token.RIGHT_CURLY);
			break;
		default:
			throw new TokenizerException("Tokenizer Error | Illegal char");
		}
	}

	@Override
	public void close() throws IOException {
		scanner.close();
	}		
}
