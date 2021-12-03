var fs = require("fs");

function checkUp(current, next) {
	if (next === current.toLowerCase()) {
		return true;
	}
	return false;
}

function checkLow(current, next) {
	if (next === current.toUpperCase()) {
		return true;
	}
	return false;
}

function transfer(i, current_input) {
	if (i === 0) {
		return current_input.substring(2, current_input.length);
	}
	let temp_input = current_input.substring(0, i);
	let next_input = temp_input.concat(current_input.substring(i + 2, current_input.length));
	return next_input;
}

let triggered = true
let up = RegExp("[A-Z]", "u");

let filename = process.argv[2].toString();
let temp_input = fs.readFileSync(filename, "utf8");
let current_input = temp_input.substring(0, temp_input.length - 1);
while (triggered) {
	triggered = false;
	for (let i = 0; i < current_input.length - 1; i++) {
		let current_char = current_input.charAt(i)
		let next_char = current_input.charAt(i + 1);
		if (up.test(current_char)) {
			if (checkUp(current_char, next_char)) {
				current_input = transfer(i, current_input);
				triggered = true;
				break;
			}
		}
		else {
			if (checkLow(current_char, next_char)) {
				current_input = transfer(i, current_input);
				triggered = true;
				break;
			}
		}
	}
}
console.log(current_input.length);
