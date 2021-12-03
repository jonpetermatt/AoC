var fs = require('fs');

var counter = 0;
function password(pass) {
	var passData = pass.split(" ");
	var userPassword = passData[2];
	var numbers = passData[0].split("-");
	var one = parseInt(numbers[0]) - 1;
	var two = parseInt(numbers[1]) - 1;
	var char = String(passData[1]).charAt(0);
	if (userPassword.charAt(one) != char && userPassword.charAt(two) == char) {
		counter++;
		return;
	}
	if (userPassword.charAt(one) == char && userPassword.charAt(two) != char) {
		counter++;
		return;
	}
}
var data = fs.readFileSync('input', 'utf8');
var lines = data.split('\n');
for (var i = 0; i < lines.length - 1; i++) {
	password(lines[i]);
}

console.log(counter);
