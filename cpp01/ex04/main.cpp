#include <string>
#include <iostream>
#include <fstream>

int	replace_file(char **argv, std::string file)
{
	std::ofstream outfile;
	std::string	line_part;
	size_t	str_index;
	int	i = 0;

	outfile.open((static_cast<std::string>(argv[1]) + ".replace").c_str());
	if (outfile.is_open() == false)
	{
		std::cout << "Can't open outfile" << std::endl;
		return (1);
	}
	while (i < (int)file.size())
	{
		str_index = file.find(argv[2], i);
		if (str_index != std::string::npos && str_index == (size_t)i)
		{
			outfile << argv[3];
			i = str_index + static_cast<std::string>(argv[2]).size();;
		}
		else
		{
			line_part = file.substr(i, str_index - i);
			outfile << line_part;
			i += (int)line_part.size();
		}
	}
	outfile.close();
	return (0);
}

int main(int argc, char **argv)
{
	std::string file;
	std::string	line;

	if (argc != 4)
	{
		std::cout << "Need 4 arguments : filename, s1 and s2" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1]);
	if (infile.is_open() == false)
	{
		std::cout << "can't open the file" << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
		file += line + '\n';
	infile.close();
	return (replace_file(argv, file));
}