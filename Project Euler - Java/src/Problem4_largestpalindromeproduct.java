import java.util.*;

public class Problem4_largestpalindromeproduct {	
	
	public static void main(String [] args){	
		List<Integer> palindromes = new ArrayList<Integer>();
		int potentialPal = 0;
		for(int i = 999; i > 100; i--){
			for(int j = i - 1; j > 99; j--){
				potentialPal = i * j;
				if(isPalindrome(potentialPal)){
					palindromes.add(potentialPal);
				}
			}
		}
		Collections.sort(palindromes);
		System.out.print(palindromes.get(palindromes.size()-1));
	}
	
	static boolean isPalindrome(int i){
		String potentiaPal = String.valueOf(i);
		char[] potentialPalArray = potentiaPal.toCharArray();
		int indexA = 0;
		int indexO = potentiaPal.length()-1;
		while(indexA < indexO){
			if(potentialPalArray[indexA] != potentialPalArray[indexO]){
				return false;
			}
			++indexA;
			--indexO;
		}		
		return true;
	}
}
