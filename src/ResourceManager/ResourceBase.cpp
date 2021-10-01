#include "ResourceManager/ResourceBase.hpp"

namespace Resource
{

ResourceBase::ResourceBase() = default;

ResourceBase::ResourceBase(const ResourceBase &other) = default;

ResourceBase::ResourceBase(ResourceBase &&other) noexcept = default;

ResourceBase &ResourceBase::operator=(const ResourceBase &other) = default;

ResourceBase &ResourceBase::operator=(ResourceBase &&other) noexcept = default;

ResourceBase::~ResourceBase() = default;

} // namespace Resource
