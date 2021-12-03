import java.util.ArrayList;

public class Wires
{
	private int x;
        private int y;
	private int moved;

        public Wires(int x, int y, int moved)
        {
                this.x = x;
                this.y = y;
		this.moved = moved;
        }
	public static void main (String[] args)
	{
		ArrayList<Wires> wire0 = new ArrayList<Wires>();
		String[] commands = args[0].split(",");
		int xpos = 0;
		int ypos = 0;
		int moved = 0;
		for (String command : commands)
		{
			int movement = Integer.parseInt(command.substring(1));
			switch (command.charAt(0))
			{
				case 'U':
					do 
					{
						ypos--;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire0.add(wire);
					} while (movement > 0);
					break;
				case 'R':
					do 
					{
						xpos++;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire0.add(wire);
					} while (movement > 0);
					break;
				case 'D':
					do 
					{
						ypos++;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire0.add(wire);
					} while (movement > 0);
					break;
				default:
					do 
					{
						xpos--;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire0.add(wire);
					} while (movement > 0);
					break;
			}
		}
		ArrayList<Wires> wire1 = new ArrayList<Wires>();
		commands = args[1].split(",");
		xpos = 0;
		ypos = 0;
		moved = 0;
		for (String command : commands)
		{
			int movement = Integer.parseInt(command.substring(1));
			switch (command.charAt(0))
			{
				case 'U':
					do 
					{
						ypos--;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire1.add(wire);
					} while (movement > 0);
					break;
				case 'R':
					do 
					{
						xpos++;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire1.add(wire);
					} while (movement > 0);
					break;
				case 'D':
					do 
					{
						ypos++;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire1.add(wire);
					} while (movement > 0);
					break;
				default:
					do 
					{
						xpos--;
						movement--;
						moved++;
						Wires wire = new Wires(xpos, ypos, moved);
						wire1.add(wire);
					} while (movement > 0);
					break;
			}
		}
		boolean first = true;
		int distance = 0;
		for (Wires A : wire0)
		{
			for (Wires B : wire1)
			{
				if (A.x == B.x && A.y == B.y)
				{
					if (first)
					{
						distance = A.moved + B.moved;
						first = false;
					}
					else
					{
						if (distance > A.moved + B.moved)
						{
							distance = A.moved + B.moved;
						}
					}

				}
			}
		}
		System.out.println(distance);
	}
}
