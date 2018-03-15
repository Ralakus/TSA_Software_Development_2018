#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define PRINT_STATUS 0

using uint64 = unsigned long long int;

int main() {
	std::cout << "Enter the amount to generate: ";
	uint64 genTo = 10;
	uint64 minPrime = 0;

	std::string inStr = "10";
	while(![&]()->bool{
		std::getline(std::cin, inStr);
		try {
			genTo = std::stoull(inStr);
			return true;
		}
		catch (...) {
			std::cout << "Enter an interger." << std::endl;
			return false;
		}
	}());

	std::cout << "Enter a minimium prime: ";

	inStr = "0";
	while(![&]()->bool{
		std::getline(std::cin, inStr);
		try {
			minPrime = std::stoull(inStr);
			if (minPrime >= genTo) {
				std::cout << "Minimium must be below generate to." << std::endl;
				return false;
			}
			else {
				return true;
			}
		}
		catch (...) {
			std::cout << "Enter an interger." << std::endl;
			return false;
		}
	}());

	std::cout << "Generating..." << std::endl;
	std::vector<bool> primes;
	[&]() -> void
	{
		primes.resize(genTo);
		for (uint64 i = 2; i < primes.size(); i++) {
			if (!primes[i]) {
				for (uint64 r = i + i; r < primes.size(); r += i) {
					primes[r] = true;
#if PRINT_STATUS
					printf("Marking off index:  %i\n", r);
#endif
				}
			}
		}
		return;
	}();

	std::string outputFileName = "GeneratedPrimesTo" + std::to_string(genTo) + ".txt";

	std::ofstream outputFile;
	outputFile.open(outputFileName);

	std::cout << "Writing to file..." << std::endl;

	for (uint64 i = 0; i < primes.size(); i++) {
#if PRINT_STATUS
		printf("Index: %i is %i\n", i, primes[i]);
#endif
		if (!primes[i] && i >= minPrime) {
			outputFile << i << '\n';
		}
	}

	printf("Done\n");
}