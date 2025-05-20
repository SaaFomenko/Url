#include "Url.h"


Url::Url(std::string url) : url(url)
{
}

Url::~Url()
{
}

std::string Url::get()
{
    return url;
}