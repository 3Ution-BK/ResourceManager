#include "ResourceManager/ResourceBase.hpp"
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

TEST(BasicResourceTest, Get_GetSingleResource_ExpectSuccess)
{
    ResourceManager manager;
    std::string key{"Foo"};

    auto resource = manager.get<FooResource>(key);

    EXPECT_NE(resource.get(), nullptr);
}

TEST(BasicResourceTest, Get_GetSingleResourceMultipleTimes_ExpectSuccess)
{
    ResourceManager manager;
    std::string key = {"Foo"};
    const long count = {5};
    std::shared_ptr<FooResource> resource[count];

    for (long iter{0}; iter < count; ++iter)
    {
        resource[iter] = manager.get<FooResource>(key);
    }

    for (long iter{0}; iter < count; ++iter)
    {
        EXPECT_EQ(resource[iter].use_count(), count);
    }
}

} // namespace Resource
