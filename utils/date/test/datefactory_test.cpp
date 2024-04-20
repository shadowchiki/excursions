#include "../datefilterfactory.h"
#include <gtest/gtest.h>

TEST(DateFilterFactoryTests, FactoryTesting)
{

    DateFilterFactory factory;
    DateFilter* filter = factory.getFilter("", "");
    ASSERT_EQ(filter, nullptr);

}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
