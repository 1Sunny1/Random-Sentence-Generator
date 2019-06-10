#ifndef SENTENCE_H_
#define SENTENCE_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Sentence {
private:
	std::vector<std::string> vOfPronouns;
	std::vector<std::string> vOfAdverbs;
	std::vector<std::string> vOfVerbs;
	std::vector<std::string> vOfPrepositions;
	std::vector<std::string> vOfAdjectives;
	std::vector<std::string> vOfNouns;
	std::string finalSentence;
	std::string lineToReadFromFile;

	std::string createSentence();
	std::vector<std::string> fillVectorFromFile(const std::string);
	int randomNumber(std::vector<std::string>&);
public:
	Sentence();
	void showSentence() const;
};
#endif 
