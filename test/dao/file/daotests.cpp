#include <dao/file/excursiondaofileimpl.h>
#include <gtest/gtest.h>

TEST(ExcursionDaoFileTest, test1)
{
    ExcursionDao* dao = new ExcursionDaoFileImpl();
    std::vector<Excursion*> excursions = dao->getByDates("2023-10-15", "");

    for (Excursion* excursion : excursions)
    {
    }
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
