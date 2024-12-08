#include <bits/stdc++.h>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

void split(std::string& line, std::vector<int>& result)
{
	size_t i = 0;
	std::string value("");
	while (i != line.length())
	{
		if (line[i] == '|' || line[i] == ',')
		{
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
	//for (int j=0; j<result.size(); j++) std::cout << result[j] << " "; std::cout << "\n";
	return;
}

int solution(std::string filename)
{
	std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode2024/day5/" + filename + ".txt";
	std::fstream inFile(fileLoc);
	
	std::cout << "file Location : " << fileLoc << std::endl;	
	std::string line;
	std::map<int, std::vector<int>> edges;
	int res = 0;
	while (std::getline(inFile, line))
	{
		if (line.empty())
			continue;
		//std::cout << " line = " << line << std::endl;
		bool hadPipe = false;
		std::vector<int> v;
		std::string value("");

		for (int i=0; i<line.length(); i++)
		{
			// split(line, v);
			//std::cout << "i = " << i << " line[i] = " << line[i] << std::endl;
			//if (line[i] == '|' || i == line.length() - 1)
			//{
			//	std::cout << "value = " << value << std::endl;
			//	v.push_back(std::stoi(value));
			//	value.clear();
			//}
			//else
			//{
			//	value += line[i];
			//	std::cout << "value = " << value << std::endl;
			//}
			if (line[i] == '|' || line[i] == ',')
        	{
            	v.push_back(std::stoi(value));
            	value.clear();
        	}
        	else
        	{
            	value += line[i];
        	}
			if (line[i] == '|')
				hadPipe = true;
		}
		v.push_back(std::stoi(value));
		//std::cout << "v[0] = " << v[0] << "v[1] = " << v[1] << std::endl;
		if (hadPipe)
		{
			// aggregate all rules into a map for the lines with pipe
			edges[v[0]].push_back(v[1]);
			// std::cout << "v[0] = " << v[0] << "v[1] = " << v[1] << std::endl;
		}
		else
		{
			std::cout << "commas now"<< std::endl;
			std::cout << "line : " << line << std::endl;
			std::set<int> earlier;
			bool ok = true;
			std::cout << "v.size() : " << v.size() << std::endl;
			for (int j = 0; j < (int)v.size(); j++)
			{
				int x = v[j];
				std::cout << "v[j] : " << v[j] << std::endl;
				for (int y : edges[x])
				{
					if (earlier.count(y))
					{
						ok = false;
					}
				}
				earlier.insert(x);
			}
			if (ok)
				res += v[v.size()/2];
		}
	}
	inFile.close();

	return res;
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

