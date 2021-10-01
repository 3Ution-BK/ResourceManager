#include "ResourceManager/ResourceLoadException.hpp"

#include <stdexcept>
#include <string>

namespace Resource
{

ResourceLoadException::ResourceLoadException(const std::string &message)
    : runtime_error{message}
{
}

ResourceLoadException::ResourceLoadException(const std::string &name,
                                             const std::string &expect,
                                             const std::string &original)
    : runtime_error{std::string("Resource '") + name +
                    "' is already loaded inside as different type. " +
                    "{ Except: " + expect + ", Original: " + original + " }"}
{
}

} // namespace Resource
