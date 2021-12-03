var fs = require("fs");

var data = fs.readFileSync("input", "utf8");
var lines = data.split("\n");

var trees = 0;
var mult = 1;
var x = 0;
for (var i = 1; i < lines.length; i++) {
	x += 3;
	if (x >= lines[i].length) {
		mult++;
		lines[i] = lines[i].repeat(mult);
	}
	if (lines[i].charAt(x) == "#") {
		trees++;
	}
}
console.log(trees);

