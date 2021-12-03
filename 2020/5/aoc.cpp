#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
	std::fstream newFile{};
	newFile.open("./input");
	std::vector<std::string> lowerUpper{};
	std::vector<std::string> leftRight{};
	std::vector<int> id{};
	const auto rows{128};
	const auto columns{8};

	std::string line{};
	while (std::getline(newFile, line)) {
		lowerUpper.emplace_back(line.substr(0, 7));
		leftRight.emplace_back(line.substr(7));
	}
	for (auto i = 0; i < lowerUpper.size(); i++) {
		int bottom{rows};
		int top{1};
		for (auto& c : lowerUpper.at(i)) {
			if (c == 'F') {
				bottom = bottom - (bottom-top+1)/2;
			}
			else {
				top = top + (bottom-top+1)/2;

			}
		}
		if (lowerUpper.at(i).back() == 'B') {
			id.emplace_back((bottom-1)*8);
		}
		else {
			id.emplace_back((top-1)*8);
		}
	}
	for (auto i = 0; i < leftRight.size(); i++) {
		int left{1};
		int right{columns};
		for (auto& c : leftRight.at(i)) {
			if (c == 'L') {
				right = right - (right-left+1)/2;
			}
			else {
				left = left + (right-left+1)/2;

			}
		}
		if (lowerUpper.at(i).back() == 'B') {
			id.at(i) = id.at(i) + right -1;
		}
		else {
			id.at(i) = id.at(i) + left -1;
		}
	}
	std::sort(id.begin(), id.end(), std::less<int>());
	std::cout << id.back()<< "\n";
	for (auto i = 0; i < id.size()-1; i++) {
		if ((id.at(i) + 2)== id.at(i+1)) {
			std::cout << id.at(i)+1;
			break;
		}
	}

}
