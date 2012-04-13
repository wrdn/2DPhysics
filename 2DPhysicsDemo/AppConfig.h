#pragma once

#include <map>
#include <string>
#include "ctypes.h"
#include <sstream>
#include "util.h"

// Config file in format:
// ParameterName =  Value
// Example: Name = Bob
// The AppConfig class is generic and will read the entire config file, with Parameter Names and Values, both
// as strings. At read time, the AppConfig class will NOT parse the data fully (i.e. it will not create
// a vector from the Velocity example above). The class will overwrite rather than storing multiple copies of data
// E.g. if "speed" appears twice, the final value in the map will be the second one
// Blank space in lines will be safely ignored. Lines starting with "#" will also be ignored as comments
// A templated Read<T> function is provided, so you can read into any class, as long as >> operator is overloaded
// To avoid issues with char* and strings, Read(const std::string &param, const char* default_val) is also provided
// The parser is CASE INSENSITIVE for parameter names
class AppConfig
{
private:
	std::map<std::string, std::string> configMap; // holds strings for the keys (config parameter names) and results

	bool Exists(const std::string &param) const;
public:
	AppConfig(void);
	~AppConfig(void);

	// Clears configMap then parses filename into configMap (parameterName, value)
	// Format: ParameterName = Value
	bool ParseConfigFile(const std::string &filename);

	// returns true if configMap contains the key param
	bool ConfigParameterExists(const std::string &param) const;

	template<class T>
	T Read(const std::string &param, T default_val)
	{
		std::string paramName = strtoupper(param);
		if(Exists(paramName))
		{
			T out;
			std::stringstream st(configMap[paramName]);
			st >> out;
			if(!st.fail())
			{
				return out;
			}
		}
		return default_val;
	};

	// returns true if it succeeded, otherwise returns false and sets output_var to default_var
	template<class T>
	bool TryRead(const std::string &param, T &output_var, const T &default_var)
	{
		std::string paramName = strtoupper(param);
		if(Exists(paramName))
		{
			T out;
			std::stringstream st(configMap[paramName]);
			st >> out;
			if(!st.fail())
			{
				output_var = out;
				return true;
			}
		}
		output_var = default_var;
		return false;
	};

	std::string Read(const std::string &param, const c8* default_val);
};