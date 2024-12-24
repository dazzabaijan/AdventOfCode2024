#include <bits/stdc++.h>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

void print(const std::vector<std::vector<int>>& v)
{
	for (int i=0; i<(int)v.size(); i++)
	{
		for (int j=0; j<(int)v[0].size(); j++)
		{
			std::cout << v[i][j];
		}
		std::cout << '\n';
	}
}

void printVec(const std::vector<std::pair<int,int>>& v)
{
	for (int i=0; i<(int)v.size(); i++)
	{
		std::cout << "(" << v[i].first << "," << v[i].second << ")";
	}
	std::cout << '\n';
}

bool withinBounds(int& i, int&j, int& rows, int& cols)
{
	return (0 <= i && i < rows && 0 <= j && j < cols);
}

void dfs(int r, int c, std::vector<std::pair<int,int>>& dirs, const std::vector<std::vector<int>>& v, int& score, std::vector<std::vector<bool>>& visited)
{
	int rows = (int)v.size();
	int cols = (int)v[0].size();
	visited[r][c] = true;
	if (v[r][c] == 9)
	{
		score++;
		return;
	}

	for (std::pair<int,int> dir : dirs)
	{
		int r1 = r + dir.first;
		int c1 = c + dir.second;

		if (withinBounds(r1, c1, rows, cols) && (v[r1][c1] == (v[r][c]+1)) && !visited[r1][c1])
		{
			dfs(r1, c1, dirs, v, score, visited);
		}
	}
}

int main(int argc, char** argv)
{
    auto t1 = high_resolution_clock::now();
    std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode2024/day10/" + std::string(argv[1]) + ".txt";

    std::fstream inFile(fileLoc);
    std::string line;

	int res = 0;
	std::vector<std::vector<int>> v;
	std::vector<std::pair<int, int>> starts;
	int i = 0;
	while (std::getline(inFile, line))
	{
		std::vector<int> tmp;
		for(int j=0; j<(int)line.length(); j++)
		{
			int digit = line[j] - '0';
			//std::cout << "line[j]:" << line[j] << std::endl;
			//std::cout << "line[j]+2:" << ++line[j] << std::endl;
			if (line[j] == '.')
				tmp.push_back(-1);
			else
				tmp.push_back(digit);
			if (digit == 0)
				starts.push_back(std::make_pair(i,j));
		}
		v.push_back(tmp);
		i++;
	}

	print(v);
	printVec(starts);
	int rows = (int)v.size();
	int cols = (int)v[0].size();
	std::vector<std::pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
	std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
	for (std::pair<int,int>& s : starts)
	{
		dfs(s.first, s.second, dirs, v, res, visited);
		visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
	}

	auto t2 = high_resolution_clock::now();

    auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

    std::cout << "Day 3" << "\n";
    std::cout << "Part 1: " << res << std::endl;
    std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;

    return 0;

}
