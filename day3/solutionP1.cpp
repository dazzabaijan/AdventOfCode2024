#include <bits/stdc++.h>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char** argv)
{
	auto t1 = high_resolution_clock::now();
	std::string fileLoc = "/home/darrenng97/develop/cpp/AdventOfCode2024/day3/" + std::string(argv[1]) + ".txt";

	std::fstream inFile(fileLoc);
	std::string line;

	long long res = 0;
	const std::string mul("mul(");
	while (std::getline(inFile, line))
	{
		for (int i=0; i<(int)line.length(); i++)
		{
			// std::cout << "line[i] = " << line[i] << std::endl;		
			if (i+3 < line.length())
			{
				if (line.substr(i,4) != mul)
				{
					// std::cout << "  " << line.substr(i, 4) << std::endl;
					continue;
				}
				i += 4;
				// std::cout << "here " << std::endl;
				
				long long x = 0, y = 0;
				bool parseY = false;
				bool ok = true;
				while(line[i] != ')')
				{
					if (line[i] >= '0' && line[i] <= '9')
                	{
                    	if (parseY)
                       		y = y * 10 + line[i] - '0';
                    	else
                        	x = x * 10 + line[i] - '0';
                	}
					else if (line[i] == ',')
					{
						parseY = true;
					}
					else
					{
						ok = false;
						break;
					}
					i++;
				}
				if (ok)
				{
					// std::cout << "x: " << x << " y: " << y << std::endl;
					res += (x*y);
				}
			}	
			//std::cout << line[i] << std::endl;
		}	

		//std::cout << line << std::endl;
	}	

	auto t2 = high_resolution_clock::now();

	auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

	std::cout << "Day 3" << "\n";
	std::cout << "Part 1: " << res << std::endl;
	std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;

	return 0;
}
