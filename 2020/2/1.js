var fs = require('fs');

var counter = 0;
function password(pass) {
	var passData = pass.split(" ");
	var userPassword = passData[2];
	var numbers = passData[0].split("-");
	var min = parseInt(numbers[0]);
	var max = parseInt(numbers[1]);
	var char = String(passData[1]).charAt(0);
	var pos = userPassword.indexOf(char, 0);
	var i = 0;
	while (pos != -1) {
		i++;
		pos = userPassword.indexOf(char, pos+1);
	}
	if (i >= min && i <= max) {

		counter++;
	}
}
var data = fs.readFileSync('input', 'utf8');
var lines = data.split('\n');
for (var i = 0; i < lines.length - 1; i++) {
	password(lines[i]);
}

console.log(counter);
