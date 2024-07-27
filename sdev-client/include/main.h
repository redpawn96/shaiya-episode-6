#pragma once

void Main();
extern "C" __declspec(dllexport) void DllExport();

namespace hook
{
    void costume_effect();
    void gui();
    void item_icon();
    void name_color();
    void packet();
    void quick_slot();
    void title();
    void vehicle();

}
