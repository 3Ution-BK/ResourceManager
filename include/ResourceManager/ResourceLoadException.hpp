#ifndef RESOURCEMANAGER_RESOURCELOADEXCEPTION_HPP_
#define RESOURCEMANAGER_RESOURCELOADEXCEPTION_HPP_

#include <stdexcept>
#include <string>

namespace Resource
{

/**
 * \brief Represent error that occur during loading resource.
 *
 * This class reports errors when the resource loading failed at run time.
 */
class ResourceLoadException : public std::runtime_error
{
public:
    /**
     * \brief Initializes a new instance of the resource load exception class
     * with specified message.
     *
     * \param message report message.
     */
    ResourceLoadException(const std::string &message);

    /**
     * \brief Initializes a new instance of the resource load exception class
     * with specified object name, expect type and original type.
     *
     * \param name Name of the object.
     * \param expect Expect class type.
     * \param original Actual original class type.
     */
    ResourceLoadException(const std::string &name, const std::string &expect,
                          const std::string &original);
};

} // namespace Resource

#endif // RESOURCEMANAGER_RESOURCELOADEXCEPTION_HPP_
