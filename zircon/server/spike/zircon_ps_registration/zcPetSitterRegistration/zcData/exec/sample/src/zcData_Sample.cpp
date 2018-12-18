#include <iostream>
#include "zcData.h"
#include "zcRepo.h"
#include "zcAccountRepo.h"


class zcTestMockedAggregate : public domain::Aggregate {
private:
  dok::Version version_;
public:
  virtual const dok::Version GetVersion() const {
    return version_;
  }
  
  void tryPut() {
    zcAccountRepo accountRepo;
    zcTestMockedAggregate agg;
    auto block = [](zcStatus s){};
    accountRepo.Put(agg,block);
    accountRepo.Put(agg, [](zcStatus status) -> void {
      std::cout << "completion called with status as : [" << status.Status() << "]" << std::endl;
    });
  }
};

static void test_zcTestMockedAggregate() {
  zcTestMockedAggregate a;
  a.tryPut();
}

int main(int argC, char *argV[])
{
    std::cout << "zcData main function called boss" << std::endl;

    zcData *common = zcData::NewL();
    if (common)
    {
        std::cout << "zcData object allocated" << std::endl;
        std::string name = common->Name();
        std::cout << "zcData object Name returned => [" << name << "]" << std::endl;
    }

  test_zcTestMockedAggregate();
    return 0;
}
