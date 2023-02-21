#include <stdexcept>
#include <string>

class NetworkException : public std::runtime_error {
public:
    explicit NetworkException(const std::string & message)
        : std::runtime_error(message) {}
};