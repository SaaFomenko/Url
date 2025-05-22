#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif

#include "Url.h"

static const char* http_str = "http";

class MyException : public std::exception
{
    private:
    const char* msg;

    public:
        MyException(const char* msg_) : msg(msg_){}
        virtual ~MyException(){}

        const char* what() const noexcept override
        {
            return msg;
        }
};

Url::Url(std::string url) : url(url)
{
    if(url.length() == 0) throw MyException("Url empty.");
    char scheme_size = url.find(":/");
    if(scheme_size > 5) throw MyException("Url shceme don`t valid size.");
    const char* test_scheme = url.substr(0, scheme_size).c_str();
    bool is_scheme = test_scheme == http_str;
    
    
#ifdef DEBUG
    // for(int i = 0; i <= scheme_size; ++i)
    // {
    //     std::cout 
    //     if()

    // }
    int i = 0;
    while(static_cast<int>(http_str[i]))
    {
        std::cout << "! " << http_str[i] << test_scheme[i] << '\n';
        is_scheme = http_str[i] == test_scheme[i];
        if(!is_scheme) break;
        ++i;
    }
    std::cout << "!!!SCHEME_SIZE: ";
    std::cout << static_cast<int>(scheme_size) << '\n';
    std::cout << "!!!IS_SCHEME: ";
    std::cout << static_cast<int>(is_scheme) << '\n';
#endif

   //bool is_scheme = test_scheme == "http";
    if(is_scheme)
    {
        scheme = test_scheme;
    }
    else throw MyException("The url scheme must match http or https protocols.");

}

Url::~Url()
{
}

std::string Url::get()
{
    return url;
}

std::string Url::to_scheme()
{
    return scheme;
}