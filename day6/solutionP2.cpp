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

	std::pair<int, int> start_guard;
	int dir = 0;
	int rows = v.size();
	int cols = v[0].length();
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (v[i][j] == '^')
			{
				start_guard = {i, j};
				v[i][j] = '.';
			}
		}
	}

	auto solveCycle = [&]() {
		std::pair<int,int> guard = start_guard;
		int dir = 0;

		std::vector<bool> visited(rows*cols*4);
		//std::set<std::pair<int,int>> visited;
		int turns = 0;

		std::vector<std::pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    	// std::set<std::pair<int,int>> visited;
    	while (true)
    	{
			turns++;
			if (turns == rows*cols*4 + 1)
				return true;
			int hash = (guard.first*cols + guard.second) * 4 + dir;
    	    if (visited[hash])
				return true;

			visited[hash] = true;

    	    int r2 = guard.first + dirs[dir].first;
    	    int c2 = guard.second + dirs[dir].second;
    	    if (!(0 <= r2 && r2 < rows && 0 <= c2 && c2 < cols))
    	        return false; // outside bounds

    	    if (v[r2][c2] == '.')
    	    {
    	        // update position in the direction we're currently travelling in
    	        guard = {r2, c2};
    	        //std::cout << " " << std::endl;
    	        //for (int i=0; i<rows; i++)
    	        //{
    	        //  for (int j=0; j<cols; j++)
    	        //  {
    	        //      if (i == r2 && j == c2)
    	        //          std::cout << '^';
    	        //      else
    	        //          std::cout << v[i][j];
    	        //  }
    	        //  std::cout << '\n';
    	        //}
    	    }
    	    else
    	    {
    	        // we hit a '#' and need to turn 90 degrees which is the next index
    	        // in the direction list
    	        dir = (dir + 1) % 4;
    	    }
    	}
	};

	int res = 0;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (v[i][j] == '.' && start_guard != std::make_pair(i,j))
			{
				v[i][j] = '#';
				if (solveCycle())
					res++;	
				v[i][j] = '.';
			}
		}
	}
	
	auto t2 = high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

    std::cout << "Day 5" << "\n";
    std::cout << "Part 1: " << res << std::endl;
    std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;

    return 0;
}
