#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <atomic>

typedef unsigned long long int uint64;



std::atomic<uint64> GenTo(0);
std::atomic<uint64> MinPrime(0);
std::atomic<uint64> CurIndex(0);
std::atomic<bool> Working(false);

void ProgressFunction();



int main(){

    std::ios::sync_with_stdio(false);

    //=========================

    std::vector<bool> Sieve;

    std::string InStr("");

    std::thread* ProgressThread;


    //=========================


    std::cout << "Enter the amount to generate: " ;

    InStr = "10";
    while(![&]()-> bool{
        std::getline(std::cin, InStr);
		try {
			GenTo = std::stoull(InStr);
			return true;
		}
		catch (...) {
			std::cout << "Enter an interger." << std::endl;
			return false;
		}
    }());

    std::cout << "Allocating sieve..." << std::endl;

    Sieve.resize(GenTo);

    std::cout << "Enter a minium prime: ";

    InStr = "0";
	while(![&]()->bool{
		std::getline(std::cin, InStr);
		try {
			MinPrime = std::stoull(InStr);
			if (MinPrime >= GenTo) {
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

    Working = true;

    ProgressThread = new std::thread(ProgressFunction);
 
    CurIndex = 1;

    while(++CurIndex < GenTo){
        if (!Sieve[CurIndex]) {
			for (uint64 r = CurIndex + CurIndex; r < GenTo; r += CurIndex) {
				Sieve[r] = true;
			}
		}
    }

    /*for (uint64 i = 2; i < Sieve.size(); i++) {
		if (!Sieve[i]) {
			for (uint64 r = i + i; r < Sieve.size(); r += i) {
				Sieve[r] = true;
			}
		}
		CurIndex = i;
	}*/

    Working = false;

    ProgressThread->join();

    delete ProgressThread;

	std::string OutputFileName = "GeneratedPrimesFrom" + std::to_string(MinPrime) + "To" + std::to_string(GenTo) + ".txt";

	std::ofstream OutputFile;
	OutputFile.open(OutputFileName);

	std::cout << "Writing to file..." << std::endl;

    Working = true;

    ProgressThread = new std::thread(ProgressFunction);

    CurIndex = static_cast<uint64>(MinPrime);

    while(++CurIndex < GenTo){
        if (!Sieve[CurIndex] && CurIndex >= MinPrime) {
			OutputFile << CurIndex << '\n';
		}
    }

    /*for (uint64 i = 0; i < Sieve.size(); i++) {
		if (!Sieve[i] && i >= MinPrime) {
			OutputFile << i << '\n';
		}
        CurIndex = i;
	}*/

    Working = false;

    ProgressThread->join();

    delete ProgressThread;

    std::cout << "Done" << std::endl;

    return 0;

}

void ProgressFunction(){

    std::cout << "                                 \r";

    while(Working){
        std::cout << "Progress: " << (static_cast<float>(CurIndex) / static_cast<float>(GenTo) * 100.f) << "%                       \r";
    }

    std::cout << "                                  \r";

}