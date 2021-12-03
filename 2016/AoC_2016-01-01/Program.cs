using System;

namespace Taxi
{
    class Program
    {
        static void Main(string[] args)
        {
            int NorthSouth = 0;
	    int EastWest = 0;
	    int direct = 0;
	    string[] dir = args[0].Split(", ");
	    foreach (var item in dir) {
		if (item[0] == 'L') {
			if (direct == 0) {
				direct = 3;
			}
			else {
				direct--;
			}
		}
		else {
			if (direct == 3) {
				direct = 0;
			}
			else {
				direct++;
			}
		}
		int distance = (int) Int64.Parse(item.Substring(1));
		switch (direct) {
			case 0:
				NorthSouth = NorthSouth + distance;
				break;
			case 1:
				EastWest = EastWest + distance;
				break;
			case 2:
				NorthSouth = NorthSouth - distance;
				break;
			default:
				EastWest = EastWest - distance;
				break;
		}
	    }
	    int total = Math.Abs(NorthSouth) + Math.Abs(EastWest);
	    Console.WriteLine(total);
        }
    }
}
