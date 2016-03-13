import java.util.*;
public class Problem10_summationofprimes {
	public static void main(String [] args){
//		int sum = 0;
//		int roof = 2000000;
////		for(int i = 2; i < roof; i++){
////			if(isPrime(i)){
////				sum += i;
////				break;
////			}
////		}
//		List<Integer> numbers = new ArrayList<Integer>();
//		numbers.add(0, 0);
//		numbers.add(1, 0);
//		for(int i = 2; i < roof; i++){
//			numbers.add(i, 1);
//		}
//		int prime = 2;
//		int j = (int)Math.pow(prime, 2);
//		while(Math.pow(prime, 2) < roof){
//			j = (int)Math.pow(prime, 2);
//			while(j < roof){
//				numbers.add(j, 0);
//				j += prime;
//			}
//			prime++;
//		}
//		
//		for(int i = 0; i < numbers.size()-1; i++){
//			if(numbers.get(i) == 1){
//				sum += i;
//			}
//		}
//		
//		System.out.println(sum);
		int roof = 2000000;
		long sum = 0;
		boolean[] isPrime  = new boolean[roof];
		isPrime[0] = false;
		for(int i = 1; i < roof; i++){
			isPrime[i] = true;
		}
		
		for(long i = 2; i < roof; i++){
			if(isPrime[(int)i-1]){
				sum += i;
				for(long j = i*i; j < roof; j += i){
					isPrime[(int)j-1] = false;
				}
			}
		}
		System.out.println(sum);
	}
	
//	static boolean isPrime(int potentialPrime){
//		for(int i = 2; i < potentialPrime; i++){
//			if(potentialPrime % i == 0){
//				return false;
//			}
//		}
//		return true;
//	}
}
