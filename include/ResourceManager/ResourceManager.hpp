#ifndef RESOURCEMANAGER_RESOURCEMANAGER_HPP_
#define RESOURCEMANAGER_RESOURCEMANAGER_HPP_

#include "ResourceBase.hpp"
#include "ResourceLoadException.hpp"

#include "ResourceManager/Detail/IsCreateExist.hpp"

#include <memory>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>

namespace Resource
{

/**
 * \brief Represent the resource manager
 *
 * This class can manage any resource that derived from ResourceBase.
 *
 * \sa ResourceBase
 */
class ResourceManager
{
    using Map = std::unordered_map<std::string, std::weak_ptr<ResourceBase>>;

public:
    /**
     * \brief Initializes a new instance of the ResourceManager class
     */
    explicit ResourceManager();

    ResourceManager(const ResourceManager &other) = delete;
    ResourceManager(ResourceManager &&other);
    ResourceManager &operator=(const ResourceManager &other) = delete;
    ResourceManager &operator=(ResourceManager &&other);
    ~ResourceManager();

    /**
     * \brief Get the correspond resource by \a name.
     *
     * \tparam ResourceType Requested resource type.
     * \param name Name of the resource
     *
     * \return Shared pointer which point to the requested resource.
     */
    template <typename ResourceType>
    std::shared_ptr<ResourceType> get(const std::string &name);

private:
    Map resources;
};

template <typename ResourceType>
std::shared_ptr<ResourceType> ResourceManager::get(const std::string &name)
{
    static_assert(std::is_base_of<ResourceBase, ResourceType>::value,
                  "ResourceType should be derived from ResourceBase.");

    static_assert(
        Detail::IsCreateExist<ResourceType, std::shared_ptr<ResourceBase>(
                                                const std::string &)>::value,
        "Cannot find the proper instantiate factory method. "
        "Resource class should have a factory method define as "
        "'std::shared_ptr<ResourceBase> ResourceType::create(const "
        "std::string &)'.");

    auto location{resources[name].lock()};

    if (!location)
    {
        location = ResourceType::create(name);
        resources[name] = location;
    }

    auto resource{std::dynamic_pointer_cast<ResourceType>(location)};
    if (!resource)
    {
        throw ResourceLoadException(name, typeid(ResourceType).name(),
                                    typeid(*(location)).name());
    }
    return resource;
}

} // namespace Resource

#endif // RESOURCEMANAGER_RESOURCEMANAGER_HPP_
