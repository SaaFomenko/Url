#ifndef URL_H
#define URL_H

#include <string>


class Url()
{
	private:
		std::string url;

	public:
		Url(std::string& url);
		virtual ~Url();

		std::strig to_way();
		std::strig to_root();
}

#endif
