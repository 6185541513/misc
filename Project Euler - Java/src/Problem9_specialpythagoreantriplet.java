
public class Problem9_specialpythagoreantriplet {
	public static void main(String [] args){	

		int sum = 1000;
		int product = 0;
		boolean goOn = true;
		for(int i = 1; i < sum; i++){
			for(int j = i + 1; j < sum; j++){
				if(sumPythagorianTriplet(i, j) == sum){
					int c = getC(i, j);
					product = getProduct(i, j, c);
					goOn = false;
					break;
				}
			}
			if(!goOn){
				break;
			}
		}
		System.out.println(product);
	}
	
	static int sumPythagorianTriplet(int a, int b){
		int aToTwo = (int)Math.pow(a, 2);
		int bToTwo = (int)Math.pow(b, 2);
		double c = Math.sqrt(aToTwo + bToTwo);
		int cToTwo = (int)Math.pow(c, 2);
		if(c % 1 == 0 && cToTwo == aToTwo + bToTwo){
			return a + b + (int)c;
		}
		return 0;
	}
	
	static int getC(int a, int b){
		int aToTwo = (int)Math.pow(a, 2);
		int bToTwo = (int)Math.pow(b, 2);
		return (int)Math.sqrt(aToTwo + bToTwo);
	}
	
	static int getProduct(int a, int b, int c){
		return a * b * c;
	}
}
