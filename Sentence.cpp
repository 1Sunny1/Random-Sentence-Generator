#include "pch.h"
#include "Sentence.h"
#include <iostream>
#include <algorithm>
#include <random>
std::mt19937 gen{ std::random_device{}() };
template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

Sentence::Sentence() {
	vOfPronouns = fillVectorFromFile("Pronouns.txt");
	vOfAdverbs = fillVectorFromFile("Adverbs.txt");
	vOfVerbs = fillVectorFromFile("Verbs.txt");
	vOfPrepositions = fillVectorFromFile("Prepositions.txt");
	vOfAdjectives = fillVectorFromFile("Adjectives.txt");
	vOfNouns = fillVectorFromFile("Nouns.txt");
	createSentence();
}
void Sentence::showSentence() const {
	std::cout << "Your random sentence is: " << finalSentence << '\n';
}

std::string Sentence::createSentence() {
	shuffleAllVectors();
	finalSentence = vOfPronouns[randomNumber(vOfPronouns)] + " " + vOfAdverbs[randomNumber(vOfAdverbs)]
		+ " " + vOfVerbs[randomNumber(vOfVerbs)] + " " + vOfPrepositions[randomNumber(vOfPrepositions)]
		+ " " + vOfAdjectives[randomNumber(vOfAdjectives)] + " " + vOfNouns[randomNumber(vOfNouns)];
	return finalSentence;
}

std::vector<std::string> Sentence::fillVectorFromFile(const std::string filename) {
	std::vector<std::string> tempV;
	std::fstream _file(filename);
	if (!_file)
		std::cout << "Something went wrong with " << filename << "\n";

	while (getline(_file, lineToReadFromFile))
		tempV.push_back(lineToReadFromFile);
	_file.close();
	return tempV;
}

void Sentence::shuffleAllVectors() {
	std::random_shuffle(vOfPronouns.begin(), vOfPronouns.end());
	std::random_shuffle(vOfAdverbs.begin(), vOfAdverbs.end());
	std::random_shuffle(vOfVerbs.begin(), vOfVerbs.end());
	std::random_shuffle(vOfPrepositions.begin(), vOfPrepositions.end());
	std::random_shuffle(vOfAdjectives.begin(), vOfAdjectives.end());
	std::random_shuffle(vOfNouns.begin(), vOfNouns.end());
	
}

int Sentence::randomNumber(std::vector<std::string>& v) {
	int randomNumber = random<int>(0, v.size());
	return randomNumber;
}
