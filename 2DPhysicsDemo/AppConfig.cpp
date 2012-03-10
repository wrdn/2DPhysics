#include "AppConfig.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "strutils.h"

AppConfig::AppConfig(void)
{
}

AppConfig::~AppConfig(void)
{
}

bool AppConfig::ParseConfigFile(const std::string &filename)
{
	// Read each line and try to parse each into the form "ParameterName = Value"
	std::ifstream out(filename);
	if(!out.good()) { return false; }

	configMap.clear();

	while(!out.eof())
	{
		std::string inp;
		std::getline(out, inp);

		if(!inp.size()) continue;
		if(inp.find('=') == std::string::npos) continue;

		TrimLeadingWhitespace(inp);

		std::vector<std::string> res;
		split(inp, '=', res);

		if(!res.size()) continue;
		if(!res.front().size() || !res.back().size()) continue;
		if(res.front()[0] == '#') continue;

		std::string paramName = strtoupper(res.front());
		std::string &value = res.back();

		TrimLeadingWhitespace(paramName);
		TrimLeadingWhitespace(value);
		TrimTrailingWhitespace(paramName);

		size_t hash_pos = value.find_first_of('#'); // remove comments on same line
		if(hash_pos != std::string::npos)
		{
			value = value.substr(0, hash_pos);
		}

		// If we get here there is a valid parameter name and value with an equals symbol seperating them
		configMap[paramName] = value;
	}

	out.close();

	return true;
};

bool AppConfig::Exists(const std::string &param) const
{
	return configMap.count(param) > 0;
};

bool AppConfig::ConfigParameterExists(const std::string &param) const
{
	return Exists(strtoupper(param));
};

std::string AppConfig::Read(const std::string &param, const char* default_val)
{
	return Read<std::string>(param, default_val);
};