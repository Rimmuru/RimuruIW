#pragma once
typedef void(*cl_write_t)(int lc);
extern cl_write_t Cl_WritePacket_stub;


typedef void* (*r_endframe_t)();
extern r_endframe_t R_EndFrame_stub;

void R_EndFrame();
void Cl_WritePacket(int a);
void CG_DrawRotatedPicPhysical_Hook(void* scrPlace, float x, float y, float width, float height, float angle, const float* color, void* material);
