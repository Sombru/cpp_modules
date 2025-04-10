#include <iostream>
#include <string>
#include <fstream> 

std::string replaceAll(std::string &line, const std::string &to_find, const std::string &to_replace)
{
	std::string result;
	int start_pos = 0;
	int found_pos = 0;

	while (line.find(to_find, start_pos) != std::string::npos)
	{
		found_pos = line.find(to_find, start_pos);
		result.append(line, start_pos, found_pos - start_pos);
		result.append(to_replace);
		start_pos = found_pos + to_find.length();
	}
	
	result.append(line, start_pos, line.length() - start_pos);		
	return result;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " //stderr stream
				  << argv[0] 
				  << " <filename <to_find> <to_replace>\n";
		return 1; 
	}

	std::fstream file;

	file.open(argv[1], std::ios::in);
	if (file.fail())
	{
		std::cerr << "Error: cant open the file\n";
		return 1;
	}

	std::string filename = argv[1];
	std::string to_find = argv[2];
	std::string to_replace = argv[3];
	std::string filename_replace = argv[1];
	std::fstream file_replace;

	filename_replace += ".replace";
	file_replace.open(filename_replace.c_str(), std::ios::out);

	std::string line;

	while (getline(file, line))
	{
		file_replace << replaceAll(line, argv[2], argv[3]) << '\n';
	}
	file.close();
	file_replace.close();
}
