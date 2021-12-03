using System;

namespace Return
{
    class Program
    {
	
	static bool[,] increase(bool[,] map, int size) {
	    	int new_size = size * 2;
	    	int mapped_size_old = new_size + 1;
	    	int mapped_size_new = (new_size * 2) + 1;
	    	bool[,] new_map = new bool[mapped_size_new,mapped_size_new];
 		for (int y = 0; y < mapped_size_old; y++) {
			for (int x = 0; x < mapped_size_old; x++) {
				new_map[y+size,x+size] = map[y,x];
			}
		}
		return new_map;
	}

        static void Main(string[] args)
        {
            	int NorthSouth = 0;
            	int EastWest = 0;
	    	int map_size = 1;
            	int direct = 0;
		int current_y_pos = 1;
		int current_x_pos = 1;
		int new_y_pos = 0;
		int new_x_pos = 0;
            	string[] dir = args[0].Split(", ");
	    	bool[,] map = new bool[3,3];
	    	map[1,1] = true;
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
					while (NorthSouth > map_size) {
						map = increase(map, map_size);
						current_x_pos = current_x_pos + map_size;
						current_y_pos = current_y_pos + map_size;
						map_size = map_size * 2;
					}
        	                        break;
        	                case 1:
        	                        EastWest = EastWest + distance;
					while (EastWest > map_size) {
						map = increase(map, map_size);
						current_x_pos = current_x_pos + map_size;
						current_y_pos = current_y_pos + map_size;
						map_size = map_size * 2;
					}
        	                        break;
        	                case 2:
        	                        NorthSouth = NorthSouth - distance;
					while (Math.Abs(NorthSouth) > map_size) {
						map = increase(map, map_size);
						current_x_pos = current_x_pos + map_size;
						current_y_pos = current_y_pos + map_size;
						map_size = map_size * 2;
					}
        	                        break;
                	        default:
                        	        EastWest = EastWest - distance;
					while (Math.Abs(EastWest) > map_size) {
						map = increase(map, map_size);
						current_x_pos = current_x_pos + map_size;
						current_y_pos = current_y_pos + map_size;
						map_size = map_size * 2;
					}
                   	             	break;
                	}

			switch(direct) {
				case 0:
					new_y_pos = current_y_pos - distance;
					while (current_y_pos != new_y_pos) {
						current_y_pos--;
						if (map[current_y_pos, current_x_pos]) {
							Console.WriteLine(Math.Abs(current_y_pos - map_size) + Math.Abs(current_x_pos - map_size));

							return;
						}

						map[current_y_pos, current_x_pos] = true;
					}
					break;
				case 1:
					new_x_pos = current_x_pos + distance;
					while (current_x_pos != new_x_pos) {
						current_x_pos++;
						if (map[current_y_pos,current_x_pos]) {
							Console.WriteLine(Math.Abs(current_y_pos - map_size) + Math.Abs(current_x_pos - map_size));
							return;
						}
						map[current_y_pos,current_x_pos] = true;
					}
					break;
				case 2:
					new_y_pos = current_y_pos + distance;
					while (current_y_pos != new_y_pos) {
						current_y_pos++;
						if (map[current_y_pos, current_x_pos]) {
							Console.WriteLine(Math.Abs(current_y_pos - map_size) + Math.Abs(current_x_pos - map_size));
							return;
						}
						map[current_y_pos, current_x_pos] = true;
					}
					break;
				default:
					new_x_pos = current_x_pos - distance;
					while (current_x_pos != new_x_pos) {
						current_x_pos--;
						if (map[current_y_pos,current_x_pos]) {
							Console.WriteLine(Math.Abs(current_y_pos - map_size) + Math.Abs(current_x_pos - map_size));
							return;
						}
						map[current_y_pos,current_x_pos] = true;
					}
					break;
			}
		}
	}
    }
}
