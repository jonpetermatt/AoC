#include <iostream>
#include <vector>
#include <string>

int main (int argc, char *argv[])
{
	std::vector<std::string> input;
	for (auto i = 1; i < argc; i++) {
		input.push_back(std::string(argv[i]));
	}
	std::vector<int> config;
	for (auto i = 0; i < input.size(); i++) {
		config.push_back(stoi(input.at(i)));
	}

	std::vector<std::vector<int>> configs;
	configs.push_back(config);
	int counter = 0;
	bool found = false;
	while (!found) {
		counter++;
		int highest = 0;
		for (auto i = 1; i < config.size(); i++) {
			if (config.at(i) > config.at(highest)) {
				highest = i;
			}
		}
		auto share = config.at(highest);
		config.at(highest) = 0;
		auto next = highest + 1;
		while (share > 0) {
			if (next == config.size()) {
				next = 0;
			}
			config.at(next)++;
			share--;
			next++;
		}
		bool match = true;
		auto copy = 0;
		for (auto i = 0; i < configs.size(); i++) {
			match = true;
			for (auto j = 0; j < config.size(); j++) {
				if (config.at(j) != (configs.at(i)).at(j)) {
					match = false;
					break;
				}
			}
			if (match) {
				copy = i;
				break;
			}
		}
		found = match;
		configs.push_back(config);
	}
	std::cout << counter << "\n";
	return 0;
}
