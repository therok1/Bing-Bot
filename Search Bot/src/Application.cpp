#include <iostream>
#include <string>
#include <Windows.h>

void searchWeb(const std::wstring& searchQuery)
{
	HRESULT result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
	std::wstring searchURL = L"microsoft-edge:https://www.bing.com/search?q=" + searchQuery;
	SHELLEXECUTEINFOW sei = { sizeof(sei) };
	sei.lpVerb = L"open";
	sei.lpFile = searchURL.c_str();
	ShellExecuteExW(&sei);
}

int main()
{
	searchWeb(L"a");
	return 0;
}