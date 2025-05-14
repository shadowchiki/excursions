#include <dao/file/federationdaofileimpl.h>
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<FederationDao> federationDao = std::make_unique<FederationDaoFileImpl>();
    for (auto federation : federationDao->getAllFederations())
    {
        std::cout << federation->getName() << std::endl;
    }

    return 0;
}
