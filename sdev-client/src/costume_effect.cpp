#include <util/util.h>
#include "include/main.h"
#include <windows.h>

LPCSTR Efeito1 = "efeito1.eft";
LPCSTR Efeito2 = "efeito2.eft";
LPCSTR Efeito3 = "efeito3.eft";
LPCSTR Efeito4 = "efeito4.eft";
LPCSTR Efeito5 = "efeito5.eft";
LPCSTR Efeito6 = "efeito6.eft";
LPCSTR Efeito7 = "efeito7.eft";
LPCSTR Efeito8 = "efeito8.eft";
LPCSTR Efeito9 = "efeito9.eft";
LPCSTR Efeito10 = "efeito10.eft";
LPCSTR Efeito11 = "efeito11.eft";
DWORD Remove_Effect = 0x00416970;
DWORD Send_Load_Effect = 0x0058C460;
DWORD Alloc_Return = 0x0042BDB4;
DWORD Effect_Address = 0x0042BC77;

_declspec(naked) void Alloc_Effects() {

	_asm {
		// 022CBA88 = efeito 2
// 022CBBB4 = efeito 3
// 022CBCE0 = efeito 4
// 022CBE0C = efeito 5
// 022CBF38 = efeito 6
// 022CC064 = efeito 7
// 022CC190 = efeito 8
// 022CC2BC = efeito 9
// 022CC3E8 = efeito 10
// 022CC514 = efeito 11


		push Efeito1
		push 0x00748864 // data/effect 
		mov ecx, 0x022CB704 // efeito1 
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue
		//
		push Efeito2
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBA88 // efeito1  // - / 022BB8B8 = DC
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue
		//
		push Efeito3
		push 0x00748864 // data/effect   
		mov ecx, 0x022CBBB4 // efeito1  - / 022BB8B8 = DD
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito4
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBCE0 // efeito1 - / 022BB8B8 
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito5
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBE0C // efeito1  - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito6
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBF38 // efeito1  - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito7
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC064 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito8
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC190 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito9
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC2BC // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito10
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC3E8 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito11
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC514 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push 0x00749E74
		push 0x00748864
		jmp Alloc_Return

		Effect_Continue :
		jmp Effect_Address



	}

}

DWORD Effect_Equip_Return = 0x0059F4A4;
DWORD Render_Effect = 0x0041A2C0;
_declspec(naked) void Effect_Costume() {
	_asm {
		//** CHECK TYPE ID OF COSTUMES **//
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 195// type ID
		je Call_Effect
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 131// type ID
		je Call_Effect2
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 192// type ID
		je Call_Effect3
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 5// type ID
		je Call_Effect4
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 6// type ID
		je Call_Effect5
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 17// type ID
		je Call_Effect6
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 106// type ID
		je Call_Effect7
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 107// type ID
		je Call_Effect8
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 108// type ID
		je Call_Effect9
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 165// type ID
		je Call_Effect10
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 173// type ID
		je Call_Effect11






		pushad
		mov ecx, esi
		call Remove_Effect
		popad

		originalcode :
		cmp dword ptr ds : [0x90E2F4] , edx
			jmp Effect_Equip_Return

			Call_Effect :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 0x00
			push 0x00
			push 0x00
			push 0x01
			push 0x01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad


			jmp originalcode
	}
}

DWORD Remove_Costume_Effect_Return = 0x0059F1DA;

_declspec(naked) void Remove_Effect_When_Remove_Costume() {
	_asm {
		pushad
		mov ecx, esi
		call Remove_Effect
		popad

		mov[edi + esi + 0x000001B9], dl
		jmp Remove_Costume_Effect_Return



	}
}

DWORD Respawn_Return = 0x005EB875;
_declspec(naked) void Show_Effect_When_Respawn() {
	_asm {
		push eax
		mov eax, 0x0059546B
		cmp[esp + 0x04], eax
		pop eax

		je Check_Costumes_ID

		originalcode :
		mov eax, 0x00002008
			jmp Respawn_Return


			Check_Costumes_ID :
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 1// type ID
			je Call_Effect
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 2// type ID
			je Call_Effect2
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 4// type ID
			je Call_Effect3
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 5// type ID
			je Call_Effect4
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 6// type ID
			je Call_Effect5
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 17// type ID
			je Call_Effect6
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 106// type ID
			je Call_Effect7
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 107// type ID
			je Call_Effect8
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 108// type ID
			je Call_Effect9
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 165// type ID
			je Call_Effect10
			cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 173// type ID
			je Call_Effect11

			jmp originalcode

			Call_Effect :
		pushad
			fldz
			push 0x00
			push 0x00
			push 0x00
			push 0x01
			push 0x01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad

			jmp originalcode


	}
}
DWORD Respawn_Return_2 = 0x0059547A;
_declspec(naked) void Show_Effect_When_Respawn_2() {
	_asm {
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 1// type ID
		je Call_Effect
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 2// type ID
		je Call_Effect2
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 4// type ID
		je Call_Effect3
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 5// type ID
		je Call_Effect4
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 6// type ID
		je Call_Effect5
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 17// type ID
		je Call_Effect6
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 106// type ID
		je Call_Effect7
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 107// type ID
		je Call_Effect8
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 108// type ID
		je Call_Effect9
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 165// type ID
		je Call_Effect10
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 173// type ID
		je Call_Effect11

		originalcode :
		mov ecx, esi
			mov[esi + 0x000002C0], bl
			jmp Respawn_Return_2

			Call_Effect :
		pushad
			fldz
			push 0x00
			push 0x00
			push 0x00
			push 0x01
			push 0x01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad

			jmp originalcode
	}
}

DWORD Effect_Map_Return = 0x004162F5;
_declspec(naked) void Effect_When_Change_Map() {
	_asm {
		push eax
		mov eax, 0x00418FA7
		cmp[esp + 0x04], eax
		pop eax
		jne originalcode

		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 1// type ID
		je Call_Effect
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 2// type ID
		je Call_Effect2
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 4// type ID
		je Call_Effect3
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 5// type ID
		je Call_Effect4
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 6// type ID
		je Call_Effect5
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 17// type ID
		je Call_Effect6
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 106// type ID
		je Call_Effect7
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 107// type ID
		je Call_Effect8
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 108// type ID
		je Call_Effect9
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 165// type ID
		je Call_Effect10
		cmp byte ptr ds : [esi + 0x0F + 0x1B9] , 173// type ID
		je Call_Effect11

		originalcode :
		mov eax, [esp + 0x04]
			push esi
			jmp Effect_Map_Return


			Call_Effect :
		pushad
			fldz
			push 0x00
			push 0x00
			push 0x00
			push 0x01
			push 0x01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad

			jmp originalcode

	}
}


void hook::costume_effect() {
	util::detour((void*)0x0042BDAA, Alloc_Effects, 5);
	util::detour((void*)0x0059F49E, Effect_Costume, 6);
	util::detour((void*)0x005EB870, Show_Effect_When_Respawn, 5);
	util::detour((void*)0x00595472, Show_Effect_When_Respawn_2, 8);
	util::detour((void*)0x004162F0, Effect_When_Change_Map, 5);
}
