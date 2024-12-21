#include <bits/stdc++.h>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char** argv)
{
	auto t1 = high_resolution_clock::now();
    std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode2024/day6/" + std::string(argv[1]) + ".txt";

    std::fstream inFile(fileLoc);
	
    std::string line;
	std::vector<std::string> v;
	while (std::getline(inFile, line))
    {
		v.push_back(line);
		//std::cout << line << '\n';
	}

	std::pair<int, int> guard;
	int dir = 0;
	int rows = v.size();
	int cols = v[0].length();
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (v[i][j] == '^')
			{
				guard = {i, j};
				v[i][j] = '.';
			}
		}
	}

	// adding:
	// {-1, 0} makes guard go up
	// {0, 1} makes guard go right
	// {1, 0} makes guard go down
	// {0, -1} makes guard go left 
	std::vector<std::pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

	std::set<std::pair<int,int>> visited;
	while (true)
	{
		visited.insert(guard);
		int r2 = guard.first + dirs[dir].first;
		int c2 = guard.second + dirs[dir].second;
		if (!(0 <= r2 && r2 < rows && 0 <= c2 && c2 < cols))
			break; // outside bounds
		
		if (v[r2][c2] == '.')
		{
			// update position in the direction we're currently travelling in
			guard = {r2, c2};
			//std::cout << " " << std::endl;
			//for (int i=0; i<rows; i++)
			//{
			//	for (int j=0; j<cols; j++)
			//	{
			//		if (i == r2 && j == c2)
			//			std::cout << '^';
			//		else
			//			std::cout << v[i][j];
			//	}
			//	std::cout << '\n';
			//}
		}
		else
		{
			// we hit a '#' and need to turn 90 degrees which is the next index
			// in the direction list
			dir = (dir + 1) % 4;
		}
	}
	
	auto t2 = high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

    std::cout << "Day 5" << "\n";
    std::cout << "Part 1: " << visited.size() << std::endl;
    std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;

    return 0;
}
