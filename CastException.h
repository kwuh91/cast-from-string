#ifndef CAST_FROM_STRING_CASTEXCEPTION_H
#define CAST_FROM_STRING_CASTEXCEPTION_H

#include <exception>
#include <stdexcept>

class CastException : public std::exception {
private:
    std::string msg_;
public:
    //Initializing
    explicit CastException();

    //Initializing with a message
    explicit CastException(std::string);

    //Error output
    [[maybe_unused]]const char *what() const noexcept override;

    //Destruct
    ~CastException() override = default;
};

#endif //CAST_FROM_STRING_CASTEXCEPTION_H
