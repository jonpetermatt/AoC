let mem = new Array(1);
mem[0] = 1;
let number = process.argv[2];
number++;
let size = 1;
let x = 0;
let y = 0;
let move = 0;
let increased = false;
let value = 0;
for (let i = 2; i < number;) {
	switch(move) {
		case 0:
			x++;
			if (x == size) {
				let new_size = size + 2;
				let new_mem = new Array((new_size)*(new_size));
				for (let j = 0; j < size; j++) {
					for (let k = 0; k < size; k++) {
						new_mem[(j+1)*new_size + k+1] = mem[j*size + k];
					}
				}
				mem = new_mem;
				y++;
				size = new_size;
				move = 1;
				x++;
				increased = true;
			}
			if (size == 3 && y == 1 && x == 2) {
				mem[size*y + x] = 1;
				increased = false;
			}
			else if (x == size-1 && !increased) {
				mem[size*y + x] = mem[size*y + x-1] + mem[size*(y-1) + x-1] + mem[size*(y-1) + x];
			}
			else if (x == size-1 && increased) {
				mem[size*y + x] = mem[size*y + x-1] + mem[size*(y-1) + x-1];
				increased = false;
			}
			else {
				mem[size*y + x] = mem[size*y + x-1] + mem[size*(y-1) + x-1] + mem[size*(y-1) + x] + mem[size*(y-1) + x+1];
			}
			i = mem[size*y + x];
			break;
		case 1:
			y--;
			if (y == 0) {
				move = 2;
				mem[size*y + x] = mem[size*(y+1) + x] + mem[size*(y+1) + x-1];
			}
			else if (y == 1) {
				mem[size*y + x] = mem[size*(y+1) + x] + mem[size*(y+1) + x-1] + mem[size*y + x-1];
			}
			else {
				mem[size*y + x] = mem[size*(y+1) + x] + mem[size*(y+1) + x-1] + mem[size*y + x-1] + mem[size*(y-1) + x-1];
			}
			i = mem[size*y + x];
			break;
		case 2:
			x--;
			if (x == 0) {
				move = 3;
				mem[size*y + x] = mem[size + 1] + mem[1];
			}
			else if (x == 1) {
				mem[size*y + x] = mem[x+1] + mem[size + x+1] + mem[size + x];
			}
			else {
				mem[size*y + x] = mem[x+1] + mem[size + x+1] + mem[size + x] + mem[size + x-1];
			}
			i = mem[size*y + x];
			break;
		default:
			y++;
			if (y == size-1) {
				move = 0;
				mem[size*y + x] = mem[size*(y-1)] + mem[size*(y-1) + 1];
			}
			else if (y == size-2) {
				mem[size*y + x] = mem[size*(y-1)] + mem[size*(y-1) + 1] + mem[size*y + 1];
			}
			else {
				mem[size*y + x] = mem[size*(y-1)] + mem[size*(y-1) + 1] + mem[size*y + 1] + mem[size*(y+1) + 1];
			}
			i = mem[size*y + x];
			break;
	}
	value = i;
}
console.log(value);
