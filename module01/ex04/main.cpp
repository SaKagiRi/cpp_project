#include <fstream>
#include <iostream>

void	searchReplace(std::string &line, std::string s1, std::string s2)
{
	std::string	res;
	std::string	before;
	int			j;
	bool		status;

	j = 0;
	status = 0;
	for (int i = line.find(s1, j); i != -1; i = line.find(s1, j))
	{
		before = line.substr(j, i - j);
		res += before;
		res += s2;
		j = i + s1.length();
		status = 1;
	}
	if (status)
	{
		res += line.substr(j, line.length());
		line = res;
	}
}

void	replaceFile(std::ifstream &fileIn, std::ofstream &fileOut, std::string s1, std::string s2)
{
	std::string	line;

	while (std::getline(fileIn, line))
	{
		searchReplace(line, s1, s2);
		fileOut << line << std::endl;
	}
}

int	main(int c, char **v)
{
	std::string	replace;

	if (c != 4)
	{
		std::cout << "input incorrect" << std::endl;
		return (1);
	}
	replace = v[1];
	replace = replace + ".replace";
	std::ifstream fileIn(v[1]);
	std::ofstream fileOut(replace.c_str());
	replaceFile(fileIn, fileOut, v[2], v[3]);
	fileIn.close();
	fileOut.close();
}
