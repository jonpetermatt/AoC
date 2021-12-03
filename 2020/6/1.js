var fs = require("fs");
var ans = "abcdefghijklmnopqrstuvwxyz".split("");

var total = 0;
function counter(group) {
	var count = 0;
	for (let i = 0; i < ans.length; i++) {
		if (group.search(ans[i]) > -1) {
			count++;
			total++;
		}
	}
}

var data = fs.readFileSync("6k6iyj.txt", "utf8");
var groups = data.split("\n\n");
groups.forEach(counter);
console.log(total);
