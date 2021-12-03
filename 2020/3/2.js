var fs = require("fs");

var data = fs.readFileSync("test", "utf8");
var lines = data.split("\n");

var one = 0;
var mult = 1;
var x = 0;
for (let i = 1; i < lines.length; i++) {
	x++;
	if (x >= lines[i].length) {
		mult++;
		lines[i] = lines[i].repeat(mult);
	}
	if (lines[i].charAt(x) == "#") {
		one++;
	}
}
console.log(one);
var two = 0;
x = 0;
for (let i = 1; i < lines.length; i++) {
	x += 3;
	if (x >= lines[i].length) {
		mult++;
		lines[i] = lines[i].repeat(mult);
	}
	if (lines[i].charAt(x) == "#") {
		two++;
	}
}
console.log(two);
var three = 0;
x = 0;
for (let i = 1; i < lines.length; i++) {
	x += 5;
	if (x >= lines[i].length) {
		mult++;
		lines[i] = lines[i].repeat(mult);
	}
	if (lines[i].charAt(x) == "#") {
		three++;
	}
}
console.log(three);
var four = 0;
x = 0;
for (let i = 1; i < lines.length; i++) {
	x += 7;
	if (x >= lines[i].length) {
		mult++;
		lines[i] = lines[i].repeat(mult);
	}
	if (lines[i].charAt(x) == "#") {
		four++;
	}
}
console.log(four);
var five = 0;
x = 0;
for (let i = 2; i < lines.length; i += 2) {
	x += 1;
	if (x >= lines[i].length) {
		mult++;
		lines[i] = lines[i].repeat(mult);
	}
	if (lines[i].charAt(x) == "#") {
		five++;
	}
	console.log(process.memoryUsage().heapUsed / 1024 / 1024);
}

console.log(one*two*three*four*five);

