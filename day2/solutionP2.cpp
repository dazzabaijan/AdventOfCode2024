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

void split(std::string& line, std::vector<int>& result)
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
			result.push_back(std::stoi(value));
			value.clear();
		}
		else
		{
			value += line[i];
		}
		i++;
	}
	result.push_back(std::stoi(value));
	// for (int j=0; j<result.size(); j++) std::cout << result[j] << " ";
	// std::cout << "\n";
	return;
}

std::vector<std::vector<int>> readInput(std::string fileName)
{
	std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode/2024/day2/" + fileName + ".txt";
	std::fstream inFile(fileLoc);
	
	std::string line;
	std::vector<std::vector<int>> reports;
	std::vector<int> levels;
	while (std::getline(inFile, line))
	{
		split(line, levels);
		reports.push_back(levels);
		levels.clear();
	}
	inFile.close();

	return reports;
}

int solution(char** argv)
{
	std::vector<std::vector<int>> reports = readInput(argv[1]); 
	int safeReports = 0;

	for (const std::vector<int>& report : reports)
	{
		bool safe = true, dampenerUsed = false;
		int diff = 0, nextDiff = 0;
		for (int j=0; j<report.size()-2; j++)
		{
			diff = report[j] - report[j+1];
			nextDiff = report[j+1] - report[j+2];

			if (abs(diff) < 1 || abs(diff) > 3 ||
				abs(nextDiff) < 1 || abs(nextDiff) > 3 ||
				(diff > 0 && nextDiff < 0) || (diff < 0 && nextDiff > 0))
			{
				safe = false;
				break;
			}
			// if (diff > 0 &&)
		}
		if (safe)
			safeReports++;
		
	}
	
	return safeReports;
}

int main(int argc, char** argv)
{
	auto t1 = high_resolution_clock::now();
	int res = solution(argv);
	auto t2 = high_resolution_clock::now();

	auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

	std::cout << "Day 2" << std::endl;
	std::cout << "Part 2: " << res << std::endl;
	std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;
	
	return 0;
}

