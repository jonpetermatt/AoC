let mem = new Array(1);
mem[0] = 1;
let number = process.argv[2];
number++;
let size = 1;
let x = 0;
let y = 0;
let move = 0;
for (let i = 2; i < number; i++) {
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
			}
			mem[size*y + x] = i;
			break;
		case 1:
			y--;
			mem[size*y + x] = i;
			if (y == 0) {
				move = 2;
			}
			break;
		case 2:
			x--;
			mem[size*y + x] = i;
			if (x == 0) {
				move = 3;
			}
			break;
		default:
			y++;
			mem[size*y + x] = i;
			if (y == size-1) {
				move = 0;
			}
			break;
	}
}

console.log((Math.abs(x-(size-1)/2)) + Math.abs(y-(size-1)/2));
