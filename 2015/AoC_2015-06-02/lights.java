public class lights
{

	static int[][] lights = new int[1000][1000];

	public static void toggle(String[] line)
	{
		String[] start = line[1].split(",");
		String[] end = line[3].split(",");
		int startx = Integer.parseInt(start[0]);
		int starty = Integer.parseInt(start[1]);
		int endx = Integer.parseInt(end[0]);
		int endy = Integer.parseInt(end[1]);
		while (starty < endy + 1)
		{
			startx = Integer.parseInt(start[0]);
			while (startx < endx + 1)
			{
				lights[starty][startx] = lights[starty][startx] + 2;
				startx++;
			}
			starty++;
		}
	}
	public static void turn(String[] line)
	{
		String[] start = line[2].split(",");
		String[] end = line[4].split(",");
		int startx = Integer.parseInt(start[0]);
		int starty = Integer.parseInt(start[1]);
		int endx = Integer.parseInt(end[0]);
		int endy = Integer.parseInt(end[1]);
		if (line[1].equals("on"))
		{
			while (starty < endy + 1)
			{
				startx = Integer.parseInt(start[0]);
				while (startx < endx + 1)
				{
					lights[starty][startx]++;
					startx++;
				}
				starty++;
			}
		}
		else
		{
			while (starty < endy + 1)
			{
				startx = Integer.parseInt(start[0]);
				while (startx < endx + 1)
				{
					if (lights[starty][startx] > 0) 
					{
						lights[starty][startx]--;
					}
					startx++;
				}
				starty++;
			}
		}
	}
	public static void main(String[] args)
	{
		int count = 0;
		String[] lines = args[0].split("\n");
		int number_of_lines = lines.length;
		for (int i = 0; i < number_of_lines; i++)
		{
			String[] line = lines[i].split(" ");
			if (line[0].equalsIgnoreCase("turn"))
			{
				turn(line);
			}
			else 
			{
				toggle(line);
			}
		}
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				count = count + lights[j][i];
			}
		}
		System.out.println(count);
	}
}
