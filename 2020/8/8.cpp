#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {

	std::vector<std::string> operations{};
	std::vector<int> args{};

	std::ifstream input("./input");
	std::string line{};
	while (std::getline(input, line)) {
		auto pos = line.find(' ');
		operations.emplace_back(line.substr(0, pos));
		args.emplace_back(std::stoi(line.substr(pos)));
	}
	auto lines = std::make_unique<bool[]>(args.size());
	for (auto i = 0; i < args.size(); i++) {
		lines[i] = false;
	}

	int acc{};
	int pos{};
	while (true) {
		if (lines[pos]) {
			break;
		}
		lines[pos] = true;
		if (operations.at(pos) == "nop") {
			pos++;
		}
		else if (operations.at(pos) == "acc") {
			acc += args.at(pos);
			pos++;
		}
		else {
			pos += args.at(pos);
		}
	}
	std::cout << acc << std::endl;
	std::vector<int> vis{};
	for (auto i = 0; i < args.size(); i++) {
		if (lines[i]) vis.emplace_back(i);
	}
	for (auto& i : vis) {
		if (operations.at(i) == "jmp") {
			operations.at(i) = "nop";
		}
		else if (operations.at(i) == "nop") {
			operations.at(i) = "jmp";
		}
		for (auto i = 0; i < args.size(); i++) {
			lines[i] = false;
		}
		acc = 0;
		pos = 0;
		while (pos < operations.size()) {
			if (lines[pos]) {
				break;
			}
			lines[pos] = true;
			if (operations.at(pos) == "nop") {
				pos++;
			}
			else if (operations.at(pos) == "acc") {
				acc += args.at(pos);
				pos++;
			}
			else {
				pos += args.at(pos);
			}
		}
		if (pos >= operations.size()) {
			std::cout << acc << std::endl;
			break;
		}
		if (operations.at(i) == "jmp") {
			operations.at(i) = "nop";
		}
		else if (operations.at(i) == "nop") {
			operations.at(i) = "jmp";
		}
	}
}
