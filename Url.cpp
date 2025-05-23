//#define DEBUG
//#ifdef DEBUG
//#define DEBUG_CSTR_SIZE
#ifdef DEBUG_CSTR_SIZE
#include <iostream>
#endif

#include "Url.h"

static const std::string http_str = "http";
static const std::string https_str = "https";
static const char* url_empty = "Url empty.";
static const char* scheme_host_div = "://";
static const char* url_fail_size = "Url shceme don`t valid size.";

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
    if(url.length() == 0) throw MyException(url_empty);
    char scheme_end_pos = url.find(scheme_host_div);
    if(scheme_end_pos > 5) throw MyException(url_fail_size);
    const std::string test_scheme = url.substr(0, scheme_end_pos);
    bool is_scheme { test_scheme == http_str || test_scheme == https_str };
    
    
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

    if(is_scheme)
    {
        scheme = test_scheme;
    }
    else throw MyException("The url scheme must match http or https protocols.");

    unsigned int start_host_pos = scheme.length() + 3; // scheme.length = : + / + / + e 
    way = url.substr(start_host_pos);

#ifdef DEBUG_CSTR_SIZE
    std::cout << "!!! FIRST SYMVOL HOST: " << url[start_host_pos] << '\n';
#endif

}

Url::~Url()
{
}

std::string Url::get()
{
    return url;
}

std::string Url::get_scheme()
{
    return scheme;
}