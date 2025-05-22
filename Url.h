#ifndef URL_H
#define URL_H

#include <string>


class Url
{
	private:
		std::string url;
		std::string scheme;

	public:
		Url(std::string url);
		virtual ~Url();

		std::string get();
		//std::string to_way();
		std::string to_scheme();
};

#endif