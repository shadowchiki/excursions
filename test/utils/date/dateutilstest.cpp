#include <gtest/gtest.h>
#include <utils/date/datefilterfactory.h>

TEST(DateFilterFactoryTests, FactoryTesting)
{
    DateFilterFactory factory;
    DateFilter* filter = factory.getFilter("", "");
    ASSERT_EQ(filter, nullptr);
}

TEST(DateFilterFactoryTest, FactoryStartDateFilterOk)
{
    DateFilterFactory factory;
    DateFilter* filter = factory.getFilter("2024-23-01", "");
    ASSERT_TRUE(filter != nullptr);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
