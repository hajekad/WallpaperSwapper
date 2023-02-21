#include <stdexcept>
#include <string>

class IsRelevantException : public std::runtime_error {
    const char * message;
public:
    explicit IsRelevantException (const std::string & message)
        : std::runtime_error(message) {}
};