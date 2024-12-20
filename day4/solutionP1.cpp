#include <bits/stdc++.h>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

void split(std::string& line, std::vector<std::string>& result)
{
	size_t i = 0;
	std::string value;
	
	for (int i=0; i<line.length(); i++)
	{
		value = line[i];
		result.push_back(value);
	}
	// for (int j=0; j<result.size(); j++) std::cout << result[j] << " "; std::cout << "\n";
	return;
}

int solution(std::string filename)
{
	std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode2024/day4/" + filename + ".txt";
	std::fstream inFile(fileLoc);
	
	std::cout << "file Location : " << fileLoc << std::endl;	
	std::string line;
	std::vector<std::vector<std::string>> v;
	while (std::getline(inFile, line))
	{
		//std::cout << " line = " << line << std::endl;
		std::vector<std::string> row;
		split(line, row);
		v.push_back(row);
		row.clear();
	}

	int xmasCount = 0;
	int row = (int) v.size();
	int col = (int) v[0].size();
	const std::string xmas("XMAS");
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			// check left
			if (j > 2 && v[i][j]+v[i][j-1]+v[i][j-2]+v[i][j-3] == xmas)
				xmasCount++;
			// check diag top left
			if (i > 2 && j > 2 && v[i][j]+v[i-1][j-1]+v[i-2][j-2]+v[i-3][j-3] == xmas)
				xmasCount++;			
			// check top
			if (i > 2 && v[i][j]+v[i-1][j]+v[i-2][j]+v[i-3][j] == xmas) 
				xmasCount++;
			// check diag top right
			if (i > 2 && j+3 < col && v[i][j]+v[i-1][j+1]+v[i-2][j+2]+v[i-3][j+3] == xmas)
				xmasCount++;
			// check right
			if (j+3 < col && v[i][j]+v[i][j+1]+v[i][j+2]+v[i][j+3] == xmas)
				xmasCount++;
			// check diag bottom right
			if (i+3 < row && j+3 < col && v[i][j]+v[i+1][j+1]+v[i+2][j+2]+v[i+3][j+3] == xmas)
				xmasCount++;	
			// check bottom
			if (i+3 < row && v[i][j]+v[i+1][j]+v[i+2][j]+v[i+3][j] == xmas)
				xmasCount++;
			// check bottom left
			if (i+3 < row && j>2 && v[i][j]+v[i+1][j-1]+v[i+2][j-2]+v[i+3][j-3] == xmas)
				xmasCount++;
		}
	}	


	inFile.close();

	return xmasCount;
}

int main(int argc, char** argv)
{
	auto t1 = high_resolution_clock::now();
	int res = solution(argv[1]);
	auto t2 = high_resolution_clock::now();

	auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

	std::cout << "Day 5" << std::endl;
	std::cout << "Part 1: " << res << std::endl;
	std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;
	
	return 0;
}

