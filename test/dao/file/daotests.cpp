#include <dao/file/excursiondaofileimpl.h>
#include <gtest/gtest.h>
#include <memory>

TEST(ExcursionDaoFileTest, test1)
{
    std::unique_ptr<ExcursionDao> excursionDao = std::make_unique<ExcursionDaoFileImpl>();
    std::vector<std::shared_ptr<Excursion>> excursions = excursionDao->getByDates("2023-10-15", "");
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
