#include <catch2/catch.hpp>
#include <iostream>
#include "zcRepo.h"
#include "zcAccountRepo.h"

class zcTest_MockedAggregate : public domain::Aggregate {
private:
    dok::Version version_;
public:
    virtual const dok::Version GetVersion() const {
        return version_;
    }
};

TEST_CASE("zcAccountRepo is instantiated", "[zcAccountRepo]")
{
    REQUIRE(1 == 1);
    zcAccountRepo accountRepo;
    zcTest_MockedAggregate agg;
    accountRepo.Put(agg, [](zcStatus status) -> void {
        std::cout << "completion called with status as : [" << status.Status() << "]" << std::endl;
    });
}
