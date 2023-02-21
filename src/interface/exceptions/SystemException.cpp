#include <stdexcept>
#include <string>

class SystemException : public std::runtime_error {
public:
    explicit SystemException(const std::string & message)
        : std::runtime_error(message) {}
};