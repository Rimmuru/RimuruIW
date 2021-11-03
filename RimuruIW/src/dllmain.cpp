#include "pch.h"
#include "detours.h"
#include <iostream>


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        R_EndFrame_stub = r_endframe_t(0x140E255F0);
        Cl_WritePacket_stub = cl_write_t(0x140375A40);
        CL_RegisterFont = CL_RegisterFont_t(0x140DFC670);
        R_AddCmdDrawText = R_AddCmdDrawText_t(0x140E25390);
        Material_RegisterHandle = Material_RegisterHandle_t(0x140E11CE0);
        CG_DrawRotatedPicPhysical = CG_DrawRotatedPicPhysical_t(0x14079C4A0);
        Get_ActiveScreenPlacement = Get_ActiveScreenPlacement_t(0x1409E4060);
        r_RenderFlags = r_RenderFlags_t(0x140DFBD00);
        R_TextWidth = R_TextWidth_t(0x140DFC770);

        AllocConsole();
        freopen("conout$", "w", stdout);
        AllocConsole();
        
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID&)R_EndFrame_stub, (LPVOID)R_EndFrame);
        DetourAttach(&(PVOID&)Cl_WritePacket_stub, (LPVOID)Cl_WritePacket);
      //  DetourAttach(&(PVOID&)CL_RegisterFont, (LPVOID)Material_RegisterHandle_Hook);
     //   DetourAttach(&(PVOID&)CG_DrawRotatedPicPhysical, (LPVOID)CG_DrawRotatedPicPhysical_Hook);
        DetourTransactionCommit();

        break;
    case DLL_PROCESS_DETACH:
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID&)R_EndFrame_stub, (LPVOID)R_EndFrame);
        DetourDetach(&(PVOID&)Cl_WritePacket_stub, (LPVOID)Cl_WritePacket);
      //  DetourDetach(&(PVOID&)CG_DrawRotatedPicPhysical, (LPVOID)CG_DrawRotatedPicPhysical_Hook);
        DetourTransactionCommit();
        break;
    }
    return TRUE;
}
