let lines = process.argv[2].split("\n");
let passwords = 0;
for (let i = 0; i < lines.length; i++) {
	let line_content = lines[i].split(" ");
	let copy = false;
	for (let j = 0; j < line_content.length - 1; j++) {
		let first = line_content[j];
		for (let k = j+1; k < line_content.length; k++) {
			let second = line_content[k];
			if (first === second) {
				copy = true;
				break;
			}
		}
		if (copy) {
			break;
		}
	}
	if (!copy) {
		passwords++;
	}
}

console.log(passwords);

