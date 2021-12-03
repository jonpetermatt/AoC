var fs = require("fs");
var ans = "abcdefghijklmnopqrstuvwxyz".split("");

var total = 0;
function counter(group) {
	var persons = group.split("\n");
	var count = 0;
	for (let i = 0; i < ans.length; i++) {
		var all = true;
		for (let j = 0; j < persons.length; j++) {
			if (persons[j].search(ans[i]) == -1) {
				all = false;
				break;
			}
		}
		if (all) {
			count++;
		}
	}
	total += count;
}

var data = fs.readFileSync("6k6iyj.txt", "utf8").trim();
var groups = data.split("\n\n");
groups.forEach(counter);
console.log(total);
