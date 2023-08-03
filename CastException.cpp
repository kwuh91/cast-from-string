#include "CastException.h"

//Initializing
CastException::CastException() = default;

//Initializing with a message
CastException::CastException(std::string error_msg) : msg_(std::move(error_msg)) {
    if (msg_ == "Invalid input" || msg_ == "There is a blank space" || msg_ == "Not a number") {
        throw std::invalid_argument(msg_);
    } else if (msg_ == "Number too small") {
        throw std::underflow_error(msg_);
    } else if (msg_ == "Number too big") {
        throw std::overflow_error(msg_);
    }
}

//Error output
const char *CastException::what() const noexcept {
    return msg_.c_str();
}
