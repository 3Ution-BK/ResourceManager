#include "ResourceManager/ResourceManager.hpp"

namespace Resource
{

ResourceManager::ResourceManager() : resources{} {}

ResourceManager::ResourceManager(ResourceManager &&other) = default;

ResourceManager &ResourceManager::operator=(ResourceManager &&other) = default;

ResourceManager::~ResourceManager() = default;

} // namespace Resource
