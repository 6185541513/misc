import java.util.*;
public class Problem7_10001stprime {
	public static void main(String [] args){
		boolean isPrime = true;
		int count = 0;
		List<Integer> primes = new ArrayList<Integer>();
		for(int i = 2; i < Integer.MAX_VALUE; i++){
			isPrime = true;
			for(int j = 2; j < i; j++){
				if(i % j == 0){
					isPrime = false;
					break;
				}
			}
			if(isPrime){
				primes.add(i);
				count++;
			}

			if(count > 10001){
				break;
			}
		}
		System.out.println(primes.get(10000));
	}
}
