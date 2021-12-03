public class Captcha {
	public static void main(String[] args) {
		int[] numbers = new int[args[0].length()];
		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = Character.getNumericValue(args[0].charAt(i));
		}
		int match = (numbers.length)/2;
		int total = 0;
		for (int i = 0; i < numbers.length; i++) {
			if (i + match < numbers.length) {
				if (numbers[i] == numbers[i+match]) {
					total += numbers[i];
				}
			}
			else {
				if (numbers[i] == numbers[i+match-numbers.length]) {
					total += numbers[i];
				}
			}
		}
		System.out.println(total);
	}
}
