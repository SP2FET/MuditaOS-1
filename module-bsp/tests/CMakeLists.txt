﻿add_catch2_executable(
    NAME
        module-bsp
    SRCS
        tests-main.cpp
        test-battery-charger-utils.cpp
    LIBS
        module-sys
        module-bsp
)
