#ifndef URL_H
#define URL_H

#include <string>


class Url
{
	private:
		std::string url;
		std::string scheme;
		std::string way;
		std::string host;

	public:
		Url(std::string url);
		virtual ~Url();

		std::string get();
		std::string get_scheme();
		std::string to_way();
};

#endif