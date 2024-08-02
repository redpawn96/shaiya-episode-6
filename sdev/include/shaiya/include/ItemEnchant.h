#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    struct LapisionEnchantStep16
    {
        UINT16 weapon;
        UINT16 defense;
    };

    struct LapisionEnchantStep32
    {
        UINT32 weapon;
        UINT32 defense;
    };

    struct LapisianEnchantSuccessRate
    {
        Array<LapisionEnchantStep32, 21> step;
    };

    struct LapisianEnchantAddValue
    {
        Array<LapisionEnchantStep16, 21> step;
    };

    static auto g_LapisianEnchantSuccessRate = (LapisianEnchantSuccessRate*)0x581C88;
    static auto g_LapisianEnchantAddValue = (LapisianEnchantAddValue*)0x581D30;
}
