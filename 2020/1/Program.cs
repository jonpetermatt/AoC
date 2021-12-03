using System;
using System.Collections;
using System.Collections.Generic;

namespace _1
{
	class Program
	{
		static void Main(string[] args)
		{
			System.IO.StreamReader file = new System.IO.StreamReader("input");
			string line;
			List<int> nums = new List<int>();
			while ((line = file.ReadLine()) != null)
			{
				var num = Int32.Parse(line);
				if (num < 2021)
				{
					nums.Add(num);
				}
			}
			HashTable table = new HashTable();
			var found = false;
			foreach (var num0 in nums)
			{
				foreach (var num1 in nums)
				{
					if ((num0 + num1) == 2020)
					{
						Console.WriteLine(num0*num1);
						found = true;
						break;
					}
				}
				if (found)
				{
					break;
				}
			}
			/*
			   foreach (var num0 in nums)
			   {
			   foreach (var num1 in nums)
			   {
			   foreach (var num2 in nums)
			   {
			   if ((num0 + num1 + num2) == 2020)
			   {
			   Console.WriteLine(num0*num1*num2);
			   return;
			   }
			   }
			   }
			   }
			   */
		}
	}
}
