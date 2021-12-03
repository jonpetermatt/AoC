using System.Security.Cryptography;
using System.Text;
using System;

namespace AoC_20150401
{
	class MainClass
	{
		public static string MD5hash(string input)
		{
			MD5 md5 = MD5.Create();
			byte[] inputbytes = Encoding.ASCII.GetBytes(input);
			byte[] hash = md5.ComputeHash(inputbytes);
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < hash.Length; i++)
			{
				sb.Append(hash[i].ToString("x2"));
			}
			return sb.ToString();
		}
		public static void Main (string[] args)
		{
			int i = 0;
			string puzzle = args[0];
			bool state = true;
			while (state)
			{
				string value = i.ToString();
				string ToHash = puzzle + value;
				string final = MD5hash(ToHash);
				if (final[0] == '0' && final[1] == '0' && final[2] == '0' && final[3] == '0' && final[4] == '0' && final[5] == '0')
				{
					state = false;
				}
				else 
				{
					i++;
				}
			}
			Console.WriteLine(i);
		}
	}
}
