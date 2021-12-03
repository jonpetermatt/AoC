using System;
using System.Linq;

namespace AoC_2016_04_01
{
	class Program
	{
		static void Main(string[] args)
		{
			char[] chars = new char[26] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
			int[] count = new int[26];
			int[] order = new int[5];
			string[] lines = args[0].Split("\n");
			foreach (var line in lines)
			{
				for (var i = 0; i < chars.Length; i++)
				{
					count[i] = line.Count(c => (c == chars[i]));
				}
			}
			for (var i = 0; i < order.Length; i++)
			{
				int max = 0;
				int pos = 0;
				for (var j = 0; j < count.Length; j++)
				{
					if (count[j] > max)
					{
						max = count[j];
						pos = j;
					}
				}
				order[i] = pos;
				count[pos] = 0;
			}
			Console.WriteLine("{0}{1}{2}{3}{4}", order[0], order[1], order[2], order[3], chars[order[4]]);
		}
	}
}
