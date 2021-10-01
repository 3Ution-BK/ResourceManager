#include "ResourceManager/ResourceBase.hpp"
#include "ResourceManager/ResourceLoadException.hpp"
#include "ResourceManager/ResourceManager.hpp"

#include "gtest/gtest.h"

#include <memory>

namespace Resource
{

class FooResource : public ResourceBase
{
public:
    static std::shared_ptr<ResourceBase> create(const std::string &)
    {
        return std::static_pointer_cast<ResourceBase>(
            std::make_shared<FooResource>());
    }
};

class BarResource : public ResourceBase
{
public:
    static std::shared_ptr<ResourceBase> create(const std::string &)
    {
        return std::static_pointer_cast<ResourceBase>(
            std::make_shared<BarResource>());
    }
};

TEST(DuplicateResourceTest,
     Get_GetDifferentResourceWithSameNameAfterCleanUp_ExpectNotThrow)
{
    ResourceManager manager;
    std::string key{"Key"};

    auto willNotThrow{[&]() {
        {
            auto resource = manager.get<FooResource>(key);
        }
        {
            auto resource = manager.get<BarResource>(key);
        }
    }};

    EXPECT_NO_THROW(willNotThrow());
}

TEST(DuplicateResourceTest,
     Get_GetDifferentResourceWithSameNameBeforeCleanUp_ExpectThrow)
{
    ResourceManager manager;
    std::string key{"Key"};

    auto willThrow{[&]() {
        auto resource1 = manager.get<FooResource>(key);
        auto resource2 = manager.get<BarResource>(key);
    }};

    EXPECT_THROW(willThrow(), ::Resource::ResourceLoadException);
}

} // namespace Resource
