#include "StringUtility.h"
using namespace std; void IndicesOf(const string& str, const string& sign, vector<int>& v)
{
	int count = str.length() - sign.length() + 1;
	v.clear();
	v.reserve(10);
	for (int i = 0; i < count; ++i)
	{
		bool success = true;
		for (int j = 0; j < sign.length(); ++j)
		{
			if (sign[j] != str[i + j])
			{
				success = false;
				break;
			}
		}
		if (success)
			v.push_back(i);
	}
}

void IndicesOf(const std::string& str, char sign, std::vector<int>& v)
{
	int count = str.length();
	v.clear();
	v.reserve(10);
	for (int i = 0; i < count; ++i)
	{
		if (sign == str[i])
		{
			v.push_back(i);
		}
	}
}

int GetFirstIndexOf(const std::string& str, char sign)
{
	int count = str.length();
	for (int i = 0; i < count; ++i)
	{
		if (sign == str[i])
		{
			return i;
		}
	}
	return -1;
}

int GetFirstIndexOf(const std::string& str, const std::string& sign)
{
	int count = str.length() - sign.length() + 1;
	for (int i = 0; i < count; ++i)
	{
		bool success = true;
		for (int j = 0; j < sign.length(); ++j)
		{
			if (sign[j] != str[i + j])
			{
				success = false;
				break;
			}
		}
		if (success)
			return i;
	}
	return -1;
}

void Split(const std::string& str, char sign, std::vector<std::string>& v)
{
	vector<int> indices;
	IndicesOf(str, sign, indices);
	v.clear();
	v.reserve(10);
	string s;
	s.reserve(str.size());
	int startPos = 0;
	for (auto index = indices.begin(); index != indices.end(); ++index)
	{
		s.clear();
		for (int i = startPos; i < *index; ++i)
		{
			s.push_back(str[i]);
		}
		startPos = *index + 1;
		if (!s.empty())
			v.push_back(s);
	}
	s.clear();
	for (int i = startPos; i < str.length(); ++i)
	{
		s.push_back(str[i]);
	}
	if (!s.empty())
		v.push_back(s);
}

void Split(const string& str, const string& sign, vector<string>& v)
{
	vector<int> indices;
	IndicesOf(str, sign, indices);
	v.clear();
	v.reserve(10);
	string s;
	s.reserve(str.size());
	int startPos = 0;
	for (auto index = indices.begin(); index != indices.end(); ++index)
	{
		s.clear();
		for (int i = startPos; i < *index; ++i)
		{
			s.push_back(str[i]);
		}
		startPos = *index + 1;
		if (!s.empty())
			v.push_back(s);
	}
	s.clear();
	for (int i = startPos; i < str.length(); ++i)
	{
		s.push_back(str[i]);
	}
	if (!s.empty())
		v.push_back(s);
}
void GetDataFromAttribute(const std::string& str, std::string& result)
{
	int firstIndex = GetFirstIndexOf(str, '[');
	result.clear();
	if (firstIndex < 0) return;
	result.reserve(5);
	for (int i = firstIndex + 1; str[i] != ']' && i < str.length(); ++i)
	{
		result.push_back(str[i]);
	}
}

void GetDataFromBrackets(const std::string& str, std::string& result)
{
	int firstIndex = GetFirstIndexOf(str, '(');
	result.clear();
	if (firstIndex < 0) return;
	result.reserve(5);
	for (int i = firstIndex + 1; str[i] != ')' && i < str.length(); ++i)
	{
		result.push_back(str[i]);
	}
}

int StringToInteger(const std::string& str)
{
	if (str.empty()) return 0;
	if (str[0] == '-')
	{
		int value = 0;
		for (int i = 1; i < str.length(); ++i)
		{
			value *= 10;
			value += (int)str[i] - 48;
		}
		return value * -1;
	}
	else
	{
		int value = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			value *= 10;
			value += (int)str[i] - 48;
		}
		return value;
	}
}