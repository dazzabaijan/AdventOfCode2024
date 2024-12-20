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
	const std::string mas("MAS");
	const std::string a{'A'};
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			if (v[i][j] == a)
			{
				// std::cout << "v[i][j]=" << v[i][j] << " ";
				if (i>0 && i+1<row && j>0 && j+1<col)
				{
					if((v[i-1][j-1]+v[i][j]+v[i+1][j+1] == mas || v[i+1][j+1]+v[i][j]+v[i-1][j-1] == mas) &&
					   (v[i+1][j-1]+v[i][j]+v[i-1][j+1] == mas || v[i-1][j+1]+v[i][j]+v[i+1][j-1] == mas))
						xmasCount++;
				}
			}
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

