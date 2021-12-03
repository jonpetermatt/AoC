public class nice
{
	public static void main(String[] args)
	{
		String[] words = args[0].split("\n");
		int total_words  = words.length;
		int good_words = 0;
		for (int i = 0; i < total_words; i++)
		{
			boolean pair = false;
			String current_word = words[i];
			for (int j = 0; j < current_word.length() - 2; j++)
			{
				String sub_1 = current_word.substring(j, j + 2);
				for (int k = j + 2; k < current_word.length() - 1; k++)
				{
					String sub_2 = current_word.substring(k, k + 2);
					pair = sub_1.equalsIgnoreCase(sub_2);
					if (pair)
					{
						break;
					}
				}
				if (pair)
				{
					break;
				}
			}
			if (!pair)
			{
				continue;
			}
			boolean repeats = false;
			for (int j = 0; j < current_word.length() - 2; j++)
			{
				char letter_1 = current_word.charAt(j);
				char letter_2 = current_word.charAt(j + 2);
				if (letter_2 == letter_1) 
				{
					repeats = true;
					break;
				}
			}
			if (repeats)
			{
				good_words++;
			}
		}
		System.out.println(good_words);
	}
}
