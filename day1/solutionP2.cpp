#include <map>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <chrono>
#include <tuple>
#include <algorithm>
#include <cstdlib>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

void split(std::string& line, std::vector<std::string>& result)
{
	size_t i = 0;
	std::string value("");
	while (i != line.length())
	{
		if (std::isspace(line[i]))
		{
			if (value.empty())
			{
				i++;
				continue;
			}
			result.push_back(value);
			value.clear();
		}
		else
		{
			value += line[i];
		}
		i++;
	}
	result.push_back(value);

	return;
}

std::tuple<std::vector<int>, std::vector<int>> readInput(std::string fileName)
{
	std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode/2024/day1/" + fileName + ".txt";
	std::fstream inFile(fileLoc);
	
	std::string line;
	std::vector<int> listA;
	std::vector<int> listB;
	std::vector<std::string> tmp;
	while (std::getline(inFile, line))
	{
		split(line, tmp);
		listA.push_back(std::stoi(tmp[0]));
		listB.push_back(std::stoi(tmp[1]));
		tmp.clear();
	}
	inFile.close();

	return std::tuple(listA, listB);
}

void setOrAdd(std::unordered_map<int, int>& map, int key)
{
	if (map.find(key) == map.end())
	{
		map[key] = 1;
	}
	else
	{
		map[key]++;
	}
}

int solution(char** argv)
{
	auto [listA, listB] = readInput(argv[1]); 
	std::unordered_map<int, int> mapA = {};
	std::unordered_map<int, int> mapB = {};

	for (int j=0; j < listA.size(); j++)
	{
		setOrAdd(mapA, listA[j]);
		setOrAdd(mapB, listB[j]);
	}

	int sum = 0;
	for (std::unordered_map<int, int>::iterator it = mapA.begin(); it != mapA.end(); it++)
	{
		sum += (it->first * mapA[it->first] * mapB[it->first]);
	}

	return sum;
}

int main(int argc, char** argv)
{
	auto t1 = high_resolution_clock::now();
	int res = solution(argv);
	auto t2 = high_resolution_clock::now();

	auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

	std::cout << "Part 2: " << res << std::endl;
	std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;
	
	return 0;
}

