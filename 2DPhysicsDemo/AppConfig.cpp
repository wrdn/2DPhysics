#include "AppConfig.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "strutils.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
using namespace std;

AppConfig::AppConfig(void)
{
}

AppConfig::~AppConfig(void)
{
}

bool AppConfig::ParseConfigFile(const std::string &filename)
{
	// Read each line and try to parse each into the form "ParameterName = Value"
	ifstream out(filename);
	if(!out.good()) { return false; }

	configMap.clear();

	while(!out.eof())
	{
		string inp;
		getline(out, inp);

		if(!inp.size()) continue;
		if(inp.find('=') == string::npos) continue;

		TrimLeadingWhitespace(inp);

		std::vector<string> res;
		split(inp, '=', res);

		if(!res.size()) continue;
		if(!res.front().size() || !res.back().size()) continue;
		if(res.front()[0] == '#') continue;
		
		string &paramName = res.front();
		string &value = res.back();

		TrimLeadingWhitespace(paramName);
		TrimLeadingWhitespace(value);
		// dont trim trailing whitespace from value, as it may be a string that needs it
		TrimTrailingWhitespace(paramName);

		// If we get here there is a valid parameter name and value with an equals symbol seperating them
		configMap[paramName] = value;
	}

	out.close();

	return true;
};

const bool AppConfig::ConfigParameterExists(const std::string &param) const
{
	return configMap.count(param) > 0;
};

bool AppConfig::GetString(const std::string &param, std::string &out)
{
	if(ConfigParameterExists(param))
	{
		out = configMap[param];
		return true;
	}
	return false;
};

bool AppConfig::GetInt(const std::string &param, i32 &out)
{
	string str;
	if(GetString(param, str))
	{
		TrimTrailingWhitespace(str);
		i32 ret = atoi(str.c_str());
		if(ret)
		{
			out = ret;
			return true;
		}
	}
	return false;
};

bool AppConfig::GetFloat(const std::string &param, f32 &out)
{
	string str;
	if(GetString(param, str))
	{
		TrimTrailingWhitespace(str);

		f32 ret=0;
		stringstream buff(str);
		buff >> ret;
		if(!buff.fail())
		{
			out = ret;
			return true;
		}
	}
	return false;
};

bool AppConfig::GetVec2(const std::string &param, float2 &out)
{
	string str;
	if(GetString(param, str))
	{
		TrimTrailingWhitespace(str);

		float2 ret;
		stringstream buff(str);
		c8 open_bracket, comma, close_bracket;
		buff >> open_bracket >> ret.GetVec()[0] >> comma >> ret.GetVec()[1] >> close_bracket;
		if(open_bracket != '(' || close_bracket != ')' || comma != ','
			|| buff.fail()) { return false; }
		out = ret;
		return true;
	}
	return false;
};

bool AppConfig::GetVec3(const std::string &param, float3 &out)
{
	string str;
	if(GetString(param, str))
	{
		TrimTrailingWhitespace(str);

		float3 ret;
		stringstream buff(str);
		c8 open_bracket, comma, comma2, close_bracket;
		buff >> open_bracket >> ret.GetVec()[0] >> comma >> ret.GetVec()[1] >> comma2 >> ret.GetVec()[2] >> close_bracket;
		if(open_bracket != '(' || close_bracket != ')' || comma != ','
			|| comma2 != ',' || buff.fail()) { return false; }
		out = ret;
		return true;
	}
	return false;
};

bool AppConfig::GetVec4(const std::string &param, float4 &out)
{
	string str;
	if(GetString(param, str))
	{
		TrimTrailingWhitespace(str);

		float4 ret;
		stringstream buff(str);
		c8 open_bracket, comma, comma2, comma3, close_bracket;
		buff >> open_bracket >> ret.GetVec()[0] >> comma >> ret.GetVec()[1] >> comma2 >> ret.GetVec()[2] >> 
			comma3 >> ret.GetVec()[3] >> close_bracket;
		if(open_bracket != '(' || close_bracket != ')' || comma != ','
			|| comma2 != ',' || comma3 != ',' || buff.fail()) { return false; }
		out = ret;
		return true;
	}
	return false;
};