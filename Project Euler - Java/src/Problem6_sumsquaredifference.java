
public class Problem6_sumsquaredifference {
	public static void main(String [] args){
		int sumOfSqures = 0;
		int squareOfSums = 0;
		
		for(int i = 1; i < 101; i++){
			sumOfSqures += (i*i);
			squareOfSums += i;
		}
		squareOfSums *= squareOfSums;
		
		System.out.print(squareOfSums-sumOfSqures);
	}
}
