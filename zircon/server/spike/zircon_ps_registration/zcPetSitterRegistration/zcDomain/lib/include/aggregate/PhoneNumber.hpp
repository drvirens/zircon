//
//  PhoneNumber.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/2/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef PhoneNumber_hpp
#define PhoneNumber_hpp

#include <string>

namespace domain
{
class PhoneNumber
{
private:
  const std::string countryCode_;
  const std::string areaCode_;
  const std::string number_;

public:
  explicit PhoneNumber(const std::string &countryCode,
                       const std::string &areaCode,
                       const std::string &number);
  const std::string &GetCountryCode() const;
  const std::string &GetAreaCode() const;
  const std::string &GetNumber() const;
};
} // namespace domain

#endif /* PhoneNumber_hpp */
