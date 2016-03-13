
public class Problem5_smallestmultiple {
	public static void main(String [] args){
		int smallestPositive = 0;
		for(int i = 2520; i < Integer.MAX_VALUE; i++){
			if(isDivisible(i)){
				smallestPositive = i;
				break;
			}
		}
		System.out.println(smallestPositive);
	}
	
	static boolean isDivisible(int current){
		for(int i = 1; i < 21; i++){
			if(current % i != 0){
				return false;
			}
		}
		return true;
	}
}
