//
//  Zircon_Assertions.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/7/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Zircon_Assertions_hpp
#define Zircon_Assertions_hpp

#include "zc_assert/ppk_assert.h"

// custom prefix
#define ZIRCON_ASSERT PPK_ASSERT
#define ZIRCON_ASSERT_WARNING PPK_ASSERT_WARNING
#define ZIRCON_ASSERT_DEBUG PPK_ASSERT_DEBUG
#define ZIRCON_ASSERT_ERROR PPK_ASSERT_ERROR
#define ZIRCON_ASSERT_FATAL PPK_ASSERT_FATAL
#define ZIRCON_ASSERT_CUSTOM PPK_ASSERT_CUSTOM
#define ZIRCON_ASSERT_USED PPK_ASSERT_USED

#endif /* Zircon_Assertions_hpp */
