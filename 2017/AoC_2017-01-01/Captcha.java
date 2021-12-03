public class Captcha {
	public static void main(String[] args) {
		int[] numbers = new int[args[0].length()];
		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = Character.getNumericValue(args[0].charAt(i));
		}
		int total = 0;
		for (int i = 0; i < numbers.length - 1; i++) {
			if (numbers[i] == numbers[i+1]) {
				total += numbers[i];
			}
		}
		if (numbers[0] == numbers[numbers.length - 1]) {
			total += numbers[0];
		}
		System.out.println(total);
	}
}
