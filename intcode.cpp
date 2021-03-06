#include <iostream>
#include <vector>

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Not the correct amount of arguments\n";
		return 1;
	}
	std::string input(argv[1]);
	std::vector<int> codes;
	auto pos = input.find(",");
	while (pos != std::string::npos) {
		std::string code = input.substr(0, pos);
		input = input.substr(pos+1, input.length() - pos-1);
		codes.push_back(std::stoi(code));
		pos = input.find(",");
	}
	codes.push_back(std::stoi(input));
	codes[1] = 12;
	codes[2] = 2;
	int opcodePos = 0;
	while (codes[opcodePos] != 99) {
		if (codes[opcodePos] == 1) {
			codes[codes[opcodePos+3]] = codes[codes[opcodePos+1]] + codes[codes[opcodePos+2]];
		}
		else if (codes[opcodePos] == 2) {
			codes[codes[opcodePos+3]] = codes[codes[opcodePos+1]] * codes[codes[opcodePos+2]];
		}
		else { 
			std::cout << "Wrong opcode\nopcodePos";
			return 1;
		}
		opcodePos += 4;
	}
	std::cout << codes[0] << "\n";
}
