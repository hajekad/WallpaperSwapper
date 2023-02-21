#include <stdexcept>
#include <string>

class IsRelevantException : public std::exception {
    const char * message;
public:
    explicit IsRelevantException(const std::string & message) {
        this->message = message.c_str();
    }

    const char * what() {
        return message;
    }
};