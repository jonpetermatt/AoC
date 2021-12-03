
public class nice
{
	public static void main(String[] args)
	{
		char[] vowels = {'a', 'e', 'i', 'o', 'u'};
		String[] bad = {"ab", "cd", "pq", "xy"};
		String[] words = args[0].split("\\r?\\n");
		int total_words = words.length;
		int good_words = 0;
		for (int i = 0; i < total_words; i++)
		{
			String current_word = words[i];
			int vowel_counter = 0;
			for (int j = 0; j < current_word.length(); j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (current_word.charAt(j) == vowels[k])
					{
						vowel_counter++;
						k = 5;
					}
				}
			}
			if (vowel_counter < 3)
			{
				continue;
			}
			boolean bad_string = false;
			for (int j = 0; j < bad.length; j++)
			{
				for (int k = 0; k < current_word.length() - 1; k++)
				{
					String sub = current_word.substring(k, k + 2);
					bad_string = sub.equalsIgnoreCase(bad[j]);
					if (bad_string)
					{
						break;
					}
				}
				if (bad_string)
				{
					break;
				}
			}
			if (bad_string)
			{
				continue;
			}
			boolean repeat = false;
			for (int j = 0; j < current_word.length() - 1; j++)
			{
				int k = j + 1;
				char a = current_word.charAt(j);
				char b = current_word.charAt(k);
				if (a == b)
				{
					repeat = true;
				}
			}
			if (!repeat) 
			{
				continue;
			}
			else 
			{
				good_words++;
			}
		}
		System.out.println(good_words);
	}
}
