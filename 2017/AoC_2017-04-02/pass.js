let lines = process.argv[2].split("\n");
let passwords = 0;
for (let i = 0; i < lines.length; i++) {
	let line_content = lines[i].split(" ");
	let anagram = true;
	for (let j = 0; j < line_content.length - 1; j++) {
		let first = line_content[j];
		anagram = true;
		let first_letters = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
		for (let k = 0; k < first.length; k++) {
			switch(first.charAt(k)) {
				case 'a':
					first_letters[0]++;
					break;
				case 'b':
					first_letters[1]++;
					break;
				case 'c':
					first_letters[2]++;
					break;
				case 'd':
					first_letters[3]++;
					break;
				case 'e':
					first_letters[4]++;
					break;
				case 'f':
					first_letters[5]++;
					break;
				case 'g':
					first_letters[6]++;
					break;
				case 'h':
					first_letters[7]++;
					break;
				case 'i':
					first_letters[8]++;
					break;
				case 'j':
					first_letters[9]++;
					break;
				case 'k':
					first_letters[10]++;
					break;
				case 'l':
					first_letters[11]++;
					break;
				case 'm':
					first_letters[12]++;
					break;
				case 'n':
					first_letters[13]++;
					break;
				case 'o':
					first_letters[14]++;
					break;
				case 'p':
					first_letters[15]++;
					break;
				case 'q':
					first_letters[16]++;
					break;
				case 'r':
					first_letters[17]++;
					break;
				case 's':
					first_letters[18]++;
					break;
				case 't':
					first_letters[19]++;
					break;
				case 'u':
					first_letters[20]++;
					break;
				case 'v':
					first_letters[21]++;
					break;
				case 'w':
					first_letters[22]++;
					break;
				case 'x':
					first_letters[23]++;
					break;
				case 'y':
					first_letters[24]++;
					break;
				case 'z':
					first_letters[25]++;
					break;
			}
		}
		for (let k = j+1; k < line_content.length; k++) {
			let second = line_content[k];
			anagram = true;
			let second_letters = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
			for (let l = 0; l < second.length; l++) {
				switch(second.charAt(l)) {
					case 'a':
						second_letters[0]++;
						break;
					case 'b':
						second_letters[1]++;
						break;
					case 'c':
						second_letters[2]++;
						break;
					case 'd':
						second_letters[3]++;
						break;
					case 'e':
						second_letters[4]++;
						break;
					case 'f':
						second_letters[5]++;
						break;
					case 'g':
						second_letters[6]++;
						break;
					case 'h':
						second_letters[7]++;
						break;
					case 'i':
						second_letters[8]++;
						break;
					case 'j':
						second_letters[9]++;
						break;
					case 'k':
						second_letters[10]++;
						break;
					case 'l':
						second_letters[11]++;
						break;
					case 'm':
						second_letters[12]++;
						break;
					case 'n':
						second_letters[13]++;
						break;
					case 'o':
						second_letters[14]++;
						break;
					case 'p':
						second_letters[15]++;
						break;
					case 'q':
						second_letters[16]++;
						break;
					case 'r':
						second_letters[17]++;
						break;
					case 's':
						second_letters[18]++;
						break;
					case 't':
						second_letters[19]++;
						break;
					case 'u':
						second_letters[20]++;
						break;
					case 'v':
						second_letters[21]++;
						break;
					case 'w':
						second_letters[22]++;
						break;
					case 'x':
						second_letters[23]++;
						break;
					case 'y':
						second_letters[24]++;
						break;
					case 'z':
						second_letters[25]++;
						break;
				}
			}
			for (let l = 0; l < 26; l++) {
				if (first_letters[l] !== second_letters[l]) {
					anagram = false;
					break;
				}
			}
			if (anagram) {
				k = line_content.length;
			}
		}
		if (anagram) {
			j = line_content.length;
		}
	}
	if (!anagram) {
		passwords++;
	}
}
console.log(passwords);
