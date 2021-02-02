// Copyright (c) 2017-2021, Mudita Sp. z.o.o. All rights reserved.
// For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

#ifndef _TS0710_TEST_H
#define _TS0710_TEST_H

#include <vector>
#include "stdint.h"
// control channel - Test Command (Test)

class TS0710_TEST
{
  public:
    TS0710_TEST()
    {}
    ~TS0710_TEST()
    {}

  private:
    /**
     * @param TestData
     */
    void request(std::vector<uint8_t> TestData);

    /**
     * @param TestData
     */
    void confirm(std::vector<uint8_t> TestData);
};

#endif //_TS0710_TEST_H
