/*
MIT License

Copyright (c) 2021 Christopher William Driggers-Ellis

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "../src/HashWrapper.hpp"
#include "../src/MapWrapper.hpp"
#include "../src/includes.hpp"

//AVLMap Tests

TEST_CASE("AVLMap Insert 100k Words", "[insert AVLMAP]") //tests insertion of the AVLMap
{
	std::string words = std::to_string(0); //This test inserts 0-9 100k times into an AVLMap. Returns true if the size is equal to 100k
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}
	tacl::Map<unsigned int, std::string> avlMap;

	std::istringstream iss(words);
	int counter = 0;

	std::string word;
	while (std::getline(iss, word, ' ')) {
		avlMap.insert(counter, word);
		counter++;
	}

	REQUIRE(avlMap.size() == 100000);
	//Passes if the AVLMap size is equal to 100k

}

TEST_CASE("AVLMap Search Value", "[insert AVLMAP][search value AVLMAP]") //tests insertion and search value of the AVLMap
{

	std::string words = std::to_string(0);
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}
	tacl::Map<unsigned int, std::string> avlMap;

	std::istringstream iss(words);
	int counter = 0;

	std::string word;
	while (std::getline(iss, word, ' ')) {
		avlMap.insert(counter, word);
		counter++;
	}

	std::vector<int> positionVector;

	for (int i = 0; i < avlMap.size(); ++i) {
		if (avlMap.search(i) == "1") {
			positionVector.push_back(i);
		}
	}

	REQUIRE(avlMap.size() == 100000);
	REQUIRE(positionVector.size() == 10000);
	//Passes if the AVLMap size is equal to 100k and positionVector size is equal to 10k

}

TEST_CASE("AVLMap Remove Value", "[insert AVLMAP][remove value AVLMAP]") //tests insertion and remove value of the AVLMap
{

	std::string words = std::to_string(0);
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}
	tacl::Map<unsigned int, std::string> avlMap;

	std::istringstream iss(words);
	int counter = 0;

	std::string word;
	while (std::getline(iss, word, ' ')) {
		avlMap.insert(counter, word);
		counter++;
	}


	int sizeBefore = avlMap.size();

	for (int i = 0; i < sizeBefore; ++i) {
		if (avlMap.search(i) == "1") {
			avlMap.remove(i);
		}
	}

	REQUIRE(avlMap.size() == 90000);
	//Passes if the AVLMap size is equal to 90k after removing 10k 1s.

}

TEST_CASE("AVLMap Replace Value", "[insert AVLMAP][insert value AVLMAP][search value AVLMAP][remove value AVLMAP]") //tests insertion and replace value of the AVLMap
{

	std::string words = std::to_string(0);
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}
	tacl::Map<unsigned int, std::string> avlMap;

	std::istringstream iss(words);
	int counter = 0;

	std::string word;
	while (std::getline(iss, word, ' ')) {
		avlMap.insert(counter, word);
		counter++;
	}

	int replacedCount = 0;
	std::vector<int> posVecBefore;
	std::vector<int> posVecAfter;

	for (int i = 0; i < avlMap.size(); ++i) {
		if (avlMap.search(i) == "1") {
			posVecBefore.push_back(i);
		}
	}

	for (int i = 0; i < avlMap.size(); ++i) {
		if (avlMap.search(i) == "1") {
			avlMap.remove(i);
			avlMap.insert(i, "1 replacement string");
			++replacedCount;
		}
	}

	for (int i = 0; i < avlMap.size(); ++i) {
		if (avlMap.search(i) == "1 replacement string") {
			posVecAfter.push_back(i);
		}
	}

	REQUIRE(avlMap.size() == 100000);
	REQUIRE(replacedCount == 10000);
	REQUIRE(posVecAfter.size() == posVecBefore.size());
	//Passes if the AVLMap size is equal to 100k, replacedCount is equal to 10k, and posVecBefore and posVecAfter sizes are the same.

}

TEST_CASE("AVLMap Remove 100k Words", "[insert AVLMAP][remove key AVLMAP]") //tests removal of the AVLMap
{
	std::string words = std::to_string(0); //This test inserts 0-9 100k times into an AVLMap, and then removes all 100k elements. Returns true if the size is equal to 0.
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}
	tacl::Map<unsigned int, std::string> avlMap;

	std::istringstream iss(words);
	int counter = 0;

	std::string word;
	while (std::getline(iss, word, ' ')) {
		avlMap.insert(counter, word);
		counter++;
	}
	for (int i = 0; i < 100000; i++) {
		avlMap.remove(i);
	}
	REQUIRE(avlMap.size() == 0);
	//Passes if the AVLMap size is equal to 0 (or empty)

}

TEST_CASE("AVLMap Search Value Remove Value Replace Value", "[insert AVLMAP][insert value AVLMAP][search value AVLMAP][remove value AVLMAP]") //tests insertion, replace value, search value of the AVLMap
{

	std::string words = std::to_string(0);
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}
	tacl::Map<unsigned int, std::string> avlMap;

	std::istringstream iss(words);
	int counter = 0;

	std::string word;
	while (std::getline(iss, word, ' ')) {
		avlMap.insert(counter, word);
		counter++;
	}


	int replacedCount = 0;
	std::vector<int> posVecBefore;
	std::vector<int> posVecAfter;

	for (int i = 0; i < avlMap.size(); ++i) {
		if (avlMap.search(i) == "2") {
			posVecBefore.push_back(i);
		}
	}

	for (int i = 0; i < avlMap.size(); ++i) {
		if (avlMap.search(i) == "2") {
			avlMap.remove(i);
			avlMap.insert(i, "2 replacement string");
			++replacedCount;
		}
	}

	for (int i = 0; i < avlMap.size(); ++i) {
		if (avlMap.search(i) == "2 replacement string") {
			posVecAfter.push_back(i);
		}
	}

	REQUIRE(avlMap.size() == 100000); //Passes if the AVLMap size is equal to 100k

	int sizeBefore = avlMap.size();

	for (int i = 0; i < sizeBefore; ++i) {
		if (avlMap.search(i) == "1") {
			avlMap.remove(i);
		}
	}

	REQUIRE(avlMap.size() == 90000);
	REQUIRE(replacedCount == 10000);
	REQUIRE(posVecAfter.size() == posVecBefore.size());
	//Passes if the AVLMap size is equal to 90k, replacedCount is equal to 10k, and posVecBefore and posVecAfter sizes are the same.

}

//HashTable Tests

TEST_CASE("HashTable Insert 100k Words", "[insert HashTable]") //tests insertion into HashTable
{
	std::string words = std::to_string(0); //This test inserts 0-9 100k times into an AVLMap, and then removes all 100k elements. Returns true if the size is equal to 0.
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}

	tacl::HashTable<std::string> hashedTable;
	int counter = tacl::getStringData(words, hashedTable);

	REQUIRE(hashedTable.size() == 10);

}

TEST_CASE("HashTable Remove 100k Words", "[insert HashTable][remove key HashTable]") //tests removal of the HashTable
{
	std::string words = std::to_string(0); //This test inserts 0-9 100k times into an AVLMap, and then removes all 100k elements. Returns true if the size is equal to 0.
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}

	tacl::HashTable<std::string> hashedTable;
	int counter = tacl::getStringData(words, hashedTable);

	for (int i = 0; i < 10; i++) {
		hashedTable.remove(std::to_string(i));
	}

	hashedTable.remove(" ");

	REQUIRE(hashedTable.size() == 0);
	//Passes if the HashTable size is 0 (or empty)

}

TEST_CASE("HashTable Search Value Remove Value Replace Value", "[insert HashTable][replace value HashTable][search value HashTable][remove value HashTable]") //tests all functionality of the HashTable
{
	std::string words = std::to_string(0);
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i % 10);
	}

	tacl::HashTable<std::string> hashedTable;
	int counter = tacl::getStringData(words, hashedTable);

	// remove the 2 from the heap
	REQUIRE(hashedTable.remove("2"));
    REQUIRE(hashedTable.insert("2 replacement string"));
	REQUIRE(hashedTable.search("2 replacement string") == "2 replacement string");
	REQUIRE(hashedTable.size() == 10);

	bool removed = hashedTable.remove("2 replacement string") && !hashedTable.remove("2");

	REQUIRE(removed);
	REQUIRE(hashedTable.size() == 9);
	//Passes tests if "2 replacement string" is successfully removed from the hash table and the table size drops down to 90k.
}

TEST_CASE("HashTable Remove Value", "[insert HashTable][remove value HashTable]") //tests remove value functionality of the HashTable
{
	std::string words = std::to_string(0);
	for (int i = 1; i < 100000; i++) {
		words = words + " " + std::to_string(i);
	}

	tacl::HashTable<std::string> hashedTable;
	int counter = tacl::getStringData(words, hashedTable);


	bool removed = hashedTable.remove("22");

	REQUIRE(removed);
	REQUIRE(hashedTable.size() == 99999);
}