#include <bits/stdc++.h>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char** argv)
{
	auto t1 = high_resolution_clock::now();
    std::string fileLoc = "./" + std::string(argv[1]) + ".txt";

    std::fstream inFile(fileLoc);
    std::string line;

	long long res = 0;
	if (!std::getline(inFile, line))
	{
		std::cout << "no input" << std::endl;
		return 1;
	}
	std::cout << line << std::endl;
	std::cout << "line char count = " << line.length() << std::endl;
	int id = 0;
	std::string new_line("");
	int N = line.length();
	for (int i=0; i<N; i++)
	{
		int num = line[i] - '0';
		if (i % 2 == 0)
		{
			// even index
			for (int j=0; j<num; j++)
			{
				new_line.append(std::to_string(id));
			}
		}
		else
		{
			// odd index
			for (int j=0; j<num; j++)
			{
				new_line.push_back('.');
			}
			id++;
		}
	}
	//std::cout << new_line.length() << std::endl;
	
	line = new_line;
	int l = 0;
	int r = line.length() - 1;
	while (l!=r)
	{
		if (line[l] != '.')
		{
			res += (l * (int)(line[l] - '0')); 
			//std::cout << l << " * " << (int)line[l] - '0' << std::endl;
			l++;
			continue;
		}
		
		if (line[r] == '.')
		{
			r--;
			continue;
		}

		line[l] = line[r];
		line[r] = '.';
		res += (l * (int)(line[l] - '0'));
		//std::cout << l << " * " << (int)line[l] - '0' << std::endl;
		l++;
		r--;
		if (l==r)
			res += (l* (int)(line[l] - '0'));
		//std::cout << line << std::endl;
	}
	// std::cout << line << std::endl;
	long long sum = 0;
	for(int i=0; line[i]!='.'; i++)
	{
		int num = line[i] - '0';
		//std::cout << i << " * " << num << std::endl;
		sum += num * i;
	}
	std::cout << "sum = " << sum << std::endl;
	

	auto t2 = high_resolution_clock::now();
	auto ms_int = std::chrono::duration_cast<milliseconds>(t2 - t1);

	std::cout << "Day 9" << "\n";
    std::cout << "Part 1: " << res << std::endl;
    std::cout << "Time taken: " << ms_int.count() << "ms" << std::endl;

	return 0;
}
