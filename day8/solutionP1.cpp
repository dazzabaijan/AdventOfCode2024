#include <bits/stdc++.h>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;


int main(int argc, char** argv)
{

	auto t1 = high_resolution_clock::now();
    std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode2024/day8/" + std::string(argv[1]) + ".txt";

    std::fstream inFile(fileLoc);
    std::string line;

	std::vector<std::string> v;
	while (std::getline(inFile, line))
	{
		v.push_back(line);
		//std::cout << line << std::endl;
	}

	
	std::map<char, std::vector<std::pair<int, int>>> map;
	int rows = v.size();
	int cols = v[0].length();
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (v[i][j] != '.')
			{
				if (map.find(v[i][j]) == map.end())
            	{
               		map[v[i][j]] = {};
            	}
            	map[v[i][j]].push_back(std::make_pair(i,j));
			}
		}
	}

    int res = 0;
	std::vector<std::vector<bool>> counted(rows, std::vector<bool>(cols));
	for (auto& [key, pos] : map)
	{
		for (int i=0; i < (int) pos.size(); i++)
		{
			for(int j=0; j < (int) pos.size(); j++)
			{
				if (i == j) // no need to compute distance with itself
				{
					continue;
				}
				int r = pos[i].first;
				int c = pos[i].second;
				int r2 = pos[j].first;
				int c2 = pos[j].second;

				// vector arithmetic
				int row = r2 + (r2 - r);
				int col = c2 + (c2 - c);

				if (0 <= row && row < rows && 0 <= col && col < cols)
				{
					if (!counted[row][col])
					{
						counted[row][col] = true;
						res++;
					}
				}
			}
		}
	}

	auto t2 = high_resolution_clock::now();

	auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

	std::cout << "Day 8" << "\n";
    std::cout << "Part 1: " << res << std::endl;
	std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;

}
