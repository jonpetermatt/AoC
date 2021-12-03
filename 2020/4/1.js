let fs = require("fs");

var fields = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"];



var valid = 0;
function test(passport) {
	var person = {
		byr: "",
		iyr: "",
		eyr: "",
		hgt: "",
		hcl: "",
		ecl: "",
		pid: "",
		cid: ""
	};


	passport = passport.replace(/\n/g, " ");


	for (var i = 0; i < fields.length; i++) {
		if ((!passport.includes(fields[i]))) {
			return;
		}
		var start = passport.indexOf(fields[i]);
		var end = passport.indexOf(" ", start);
		var info = " ";
		if (end != -1) {
			info = passport.slice(start+4, end);
		}
		else {
			info = passport.slice(start+4);
		}
		eval("person." + fields[i] + " = \"" + info + "\";");
	}
	if (person.byr.length != 4) {
		return;
	}
	var year = parseInt(person.byr);
	if (year < 1920 || year > 2002) {
		return;
	}
	if (person.iyr.length != 4) {
		return;
	}
	year = parseInt(person.iyr);
	if (year < 2010 || year > 2020) {
		return;
	}
	if (person.eyr.length != 4) {
		return;
	}
	year = parseInt(person.eyr);
	if (year < 2020 || year > 2030) {
		return;
	}
	var unit = (person.hgt.slice(person.hgt.length-2) == "cm");
	if (unit) {
		var len = person.hgt.slice(0, person.hgt.indexOf("c"));
		if (len < 150 || len > 193) {
			return;
		}
	}
	else {
		len = person.hgt.slice(0, person.hgt.indexOf("i"));
		if (len < 59 || len > 76) {
			return;
		}
	}
	for (let j = 0; j < 10; j++) {
		var hair = person.hcl.replace(j.toString(), "");
		while (hair != person.hcl) {
			person.hcl = hair;
			hair = person.hcl.replace(j.toString(), "");
		}
	}
	var chars = ["a", "b", "c", "d", "e", "f"];
	for (let j = 0; j < 10; j++) {
		hair = person.hcl.replace(chars[j], "");
		while (hair != person.hcl) {
			person.hcl = hair;
			hair = person.hcl.replace(chars[j], "");
		}
	}
	if (person.hcl != "#") {
		return;
	}
	var eyes = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"];
	var noMatch = true;
	for (let j = 0; j < eyes.length; j++) {
		if (person.ecl == eyes[j]) {
			noMatch = false;
			break;
		}
	}
	if (noMatch) {
		return;
	}
	if (person.pid.length != 9) {
		return;
	}
	valid++;
}

var data = fs.readFileSync("input", "utf8");
var passports = data.split("\n\n");
for (var i = 0; i < passports.length; i++) {
	test(passports[i]);
}
console.log(valid);
