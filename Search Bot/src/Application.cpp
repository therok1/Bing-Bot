#include <iostream>
#include <string>

#include <Windows.h>

std::string genRandom(std::size_t length)
{
	const std::string alphanumeric =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string temp;
	temp.reserve(length);

	for (std::size_t i = 0; i < length; i++)
		temp += alphanumeric.at(rand() % (alphanumeric.size() - 1));

	return temp;
}

bool searchWeb()
{
	HRESULT result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

	std::string input = genRandom(32);
	std::wstring ws(input.begin(), input.end());
	std::wstring searchURL = L"microsoft-edge:https://www.bing.com/search?q=" + ws;

	SHELLEXECUTEINFOW sei = { sizeof(sei) };
	sei.lpVerb = L"open";
	sei.lpFile = searchURL.c_str();

	return ShellExecuteExW(&sei);
}

void changeToLower(std::string& item) 
{
	for (auto& i : item)
		i = std::tolower(i);
}

int main()
{
	std::cout << "Enter 'Lvl1', 'Lvl2' or 'Custom':" << std::endl;
	std::string searchTerm;
	std::size_t searchAmount = 0;
	std::size_t num = 0;
	while (std::getline(std::cin, searchTerm)) 
	{
		changeToLower(searchTerm);
		if (searchTerm == "lvl1") 
		{
			searchAmount = 10; // 30 points, 3 for search
			break;
		}
		else if (searchTerm == "lvl2") 
		{
			searchAmount = 30; // 90 points, 3 for search
			break;
		}
		else if (searchTerm == "custom") 
		{
			std::cout << "Enter a custom amount:" << std::endl;
			std::cin >> searchAmount;
			break;
		}
		else
			std::cout << searchTerm << " is not a search term" << std::endl;
	}

	for (std::size_t i = 0; i < searchAmount; i++)
		searchWeb();

	return 0;
}

