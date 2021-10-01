#ifndef RESOURCEMANAGER_RESOURCEBASE_HPP_
#define RESOURCEMANAGER_RESOURCEBASE_HPP_

#include <memory>
#include <string>

namespace Resource
{

/**
 * \brief Represent the base of the resource.
 *
 * Any resource class should be derived from this class if it should be managed
 * by ResourceManager.
 *
 * \sa ResourceManager
 */
class ResourceBase
{
public:
    /**
     * \brief Initializes a new instance of the empty ResourceBase class.
     */
    explicit ResourceBase();

    ResourceBase(const ResourceBase &other);
    ResourceBase(ResourceBase &&other) noexcept;
    ResourceBase &operator=(const ResourceBase &other);
    ResourceBase &operator=(ResourceBase &&other) noexcept;
    virtual ~ResourceBase();
};

} // namespace Resource

#endif // RESOURCEMANAGER_RESOURCEBASE_HPP_
