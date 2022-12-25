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
	std::string input = genRandom(32);
	std::wstring ws(input.begin(), input.end());
	std::wstring searchURL = L"microsoft-edge:https://www.bing.com/search?q=" + ws;
	HRESULT result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
	SHELLEXECUTEINFOW sei = { sizeof(sei) };
	sei.lpVerb = L"open";
	sei.lpFile = searchURL.c_str();
	return ShellExecuteExW(&sei);
}

int main() 
{
	std::string searchTerm;
	while (std::getline(std::cin, searchTerm))
		if (searchTerm == "Lvl1" || searchTerm == "Lvl2")
			break;
	std::size_t searchAmount = searchTerm == "Lvl1" ? 10 : 30;
	for (std::size_t i = 0; i < searchAmount; i++)
		searchWeb();
	return 0;
}