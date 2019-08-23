#pragma once
#include <string>

std::string erase_whitespace(std::string text) {
	int length = text.size();
	int i = 0;
	while(i < length)
	{
		if (isspace(text[i])) {
			text.erase(i);
		}
		else
		{
			i++;
		}
		std::cout << text << std::endl;
	}
	return text;
}