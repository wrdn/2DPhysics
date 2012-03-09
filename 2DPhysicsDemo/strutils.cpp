#include "util.h"
#include "strutils.h"

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

c8* copystr(const c8 *src)
{
	if(!src) return 0;

	u32 len = strlen(src);
	if(!len) return 0;
	c8* dst = new c8[len+1];
	strncpy(dst,src,len);
	dst[len] = '\0';
	return dst;
};
c8* copystr(const c8 *src, const i32 len)
{
	if(!len) return 0;
	c8* dst = new c8[len+1];
	strncpy(dst,src,len);
	dst[len] = '\0';
	return dst;
};

c8* copystr_unsafe(const c8 *src)
{
	u32 len = strlen(src);
	c8* dst = new c8[len+1];
	strncpy(dst,src,len);
	dst[len] = '\0';
	return dst;
};

c8* copystr_unsafe(const c8 *src, const i32 len)
{
	c8* dst = new c8[len+1];
	strncpy(dst,src,len);
	dst[len] = '\0';
	return dst;
};

c8* substr(const c8*src, u32 start, u32 end)
{
	if(!src) return 0;

	u32 len = end-start;
	c8* newstr = new c8[len+1];
	u32 curr=start;
	u32 ipos=0;
	while(curr < len+1)
	{
		newstr[ipos++] = src[curr++];
	}
	newstr[len] = '\0';

	return newstr;
}

bool compare_str_lim(const c8 *src, const c8 *targ, u32 start, u32 end)
{
	u32 totA = 0, totB = 0;
	for(u32 i=start;i<end;++i)
	{
		totA += (u32)src[i];
		totB += (u32)targ[i];
	}
	return (totA == totB);
}

bool compare_str_lim(const c8 *src, const c8 *targ, u32 src_start, u32 src_end,
	u32 targ_start, u32 targ_end)
{
	u32 tota=0, totb=0;
	for(u32 i=src_start;i<src_end;++i)
		tota += src[i];
	for(u32 i=targ_start;i<targ_end;++i)
		totb += targ[i];
	return (tota == totb);
}

void split(const string &s, c8 delim, vector<string> &v)
{
	string::size_type i = 0;
	string::size_type j = s.find(delim);
	while (j != string::npos) {
		v.push_back(s.substr(i, j-i));
		i = ++j;
		j = s.find(delim, j);
		if (j == string::npos)
		{
			v.push_back(s.substr(i, s.length()));
		}
	}
}

void printf_array(f32 *arr, u32 sz)
{
	for(u32 i=0;i<sz;++i)
	{
		cout << i << ": " << arr[i] << endl;
	}
}

void printi_array(u32 *arr, u32 sz)
{
	for(u32 i=0;i<sz;++i)
	{
		cout << i << ": " << arr[i] << endl;
	}
}

std::vector<c8*> read_src_to_vec(const c8* file)
{
	return read_src_to_vec(file,true,100);
};

std::vector<c8*> read_src_to_vec(const c8* file, bool incBlankLines)
{
	return read_src_to_vec(file, incBlankLines,100);
};

std::vector<c8*> read_src_to_vec(const c8* file, bool incBlankLines, const u32 originalVecSize)
{
	vector<c8*> vec;
	vec.reserve(originalVecSize);

	ifstream infile(file);
	if(!infile.is_open()) { infile.close(); return vec; } // no file=empty vector
	infile.seekg(infile.beg);

	if(!incBlankLines)
	{
		while(!infile.eof())
		{
			std::string tmp;
			getline(infile,tmp);

			u32 len = tmp.length();
			if(tmp.length() > 0)
			{
				vec.push_back(copystr_unsafe(tmp.c_str(),len));
			}
		}
	}
	else // include blank lines
	{
		while(!infile.eof())
		{
			std::string tmp;
			getline(infile,tmp);
			vec.push_back(copystr(tmp.c_str()));
		}
	}
	infile.close();

	return vec;
};


c8 *read_src(const c8 *file)
{
	std::ifstream istream(file);

	if(!istream.is_open()) { istream.close(); return 0; }
	istream.seekg(istream.beg);

	std::string str;
	while(!istream.eof())
	{
		std::string tmp;
		getline(istream,tmp);
		str += tmp + "\n";
	}
	istream.close();

	c8 *ret = new c8[str.length()+1];
	strcpy(ret,str.c_str());
	ret[str.length()] = '\0';
	return ret;
};

c8 *read_src_raw(const c8 *file)
{
	std::ifstream istream(file);

	if(!istream.is_open()) { istream.close(); return 0; }
	istream.seekg(istream.beg);

	std::string str;
	while(!istream.eof())
	{
		std::string tmp;
		getline(istream,tmp);
		str += tmp;
	}
	istream.close();

	c8 *ret = new c8[str.length()+1];
	strcpy(ret,str.c_str());
	ret[str.length()] = '\0';
	return ret;
};

// Reads text file in binary mode. Gets the file size then reads entire contents in 
// single read, before appending NULL to terminate string
c8 *read_src_fast(const c8 *file)
{
	if(!file) { return 0; }
	ifstream fs(file, ios::binary);
	if(!fs.is_open()) return 0;

	fs.seekg(0,ios::end);
	u32 len = (u32)fs.tellg();
	fs.seekg(0,ios::beg);

	c8 *buff = new c8[len+1];
	fs.read(buff,len);
	fs.close();

	buff[len] = '\0';

	return buff;
}

void cleanup_str_vec(std::vector<c8*> &v)
{
	//for(size_t i=0;i<v.size();++i)
	//	SAFE_DELETE_ARRAY(v[i]);
	for(size_t i=0;i<v.size();++i)
	{
		delete [] v[i];
	}
	v.clear();
};

const char* bstr(const bool b)
{
	return b ? "True" : "False";
};

bool fast_strcmp(c8 *a, c8 *b)
{
	u32 len = strlen(a);
	// First check string lengths are equal
	if(len != strlen(b)) return false;

	if(!memcmp(a,b,len))
		return true;

	return false;
};

bool fast_strcmp(c8 *a, c8 *b, u32 len)
{
	// First check string lengths are equal
	if(strlen(a) != strlen(b)) return false;

	if(!memcmp(a,b,len))
		return true;

	return false;
};

void TrimLeadingWhitespace(std::string &s)
{
	if(!s.size()) return;

	// Trim leading whitespace
	u32 tmp=0;
	while(s[tmp] == ' ') ++tmp;
	s.erase(s.begin(), s.begin()+tmp);
};

void TrimTrailingWhitespace(std::string &s)
{
	if(!s.size()) return;

	u32 tmp = s.size()-1;
	while(s[tmp] == ' ') --tmp;
	s.erase(s.begin()+tmp+1, s.end());
};

u32 CountCharacterOccurrence(const c8* str, const c8 delim)
{
	u32 count=0;
	while(c8 c = *str++)
	{
		if(c == delim) { ++count; }
	}
	return count;
};

std::string strtolower(const std::string &sp)
{
	string s = sp;
	for(u32 i=0;i<s.size();++i)
		s[i] = (c8)tolower(s[i]);
	return s;
};

std::string strtoupper(const std::string &sp)
{
	string s = sp;
	for(u32 i=0;i<s.size();++i)
		s[i] = (c8)toupper(s[i]);
	return s;
};

bool stringtobool(const std::string &s)
{
	return strtolower(s) == "true" ? true : false;
};