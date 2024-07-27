#include <util/util.h>
#include "include/main.h"
#include "include/shaiya/include/CCharacter.h"
using namespace shaiya;

void user_ctor_hook(CCharacter* user)
{
    user->title.text = nullptr;
    user->title.pointX = 0;
    user->title.effectDataId = 0;
}

unsigned u0x419E79 = 0x419E79;
void __declspec(naked) naked_0x419E73()
{
    __asm
    {
        // original
        mov [esi+0x434],ebx

        pushad

        push esi // user
        call user_ctor_hook
        add esp,0x4

        popad

        jmp u0x419E79
    }
}

void Main()
{
    // CCharacter::CCharacter
    util::detour((void*)0x419E73, naked_0x419E73, 6);

    //hook::costume_effect();
    hook::gui();
    hook::item_icon();
    hook::name_color();
    hook::packet();
    hook::quick_slot();
    hook::title();
    hook::vehicle();

    // character memory (0x43C to 0x448)
    util::write_memory((void*)0x41CC97, 0x48, 1);
    util::write_memory((void*)0x41F055, 0x48, 1);
    util::write_memory((void*)0x476F9F, 0x48, 1);
    util::write_memory((void*)0x490250, 0x48, 1);
    util::write_memory((void*)0x4EFE68, 0x48, 1);
    util::write_memory((void*)0x4F7318, 0x48, 1);
    util::write_memory((void*)0x59A3F3, 0x48, 1);
    util::write_memory((void*)0x59A6DD, 0x48, 1);
}
