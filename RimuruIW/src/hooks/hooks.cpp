#include "../pch.h"
#include <iostream>

cl_write_t Cl_WritePacket_stub;
r_endframe_t R_EndFrame_stub;

void Cl_WritePacket(int a)
{

	Cl_WritePacket_stub(a);
}


void R_EndFrame()
{
	BasicDrawing();
	R_EndFrame_stub();
}

void CG_DrawRotatedPicPhysical_Hook(void* scrPlace, float x, float y, float width, float height, float angle, float* color, void* material)
{
	
	std::cout << scrPlace << material << x << y << width << height << "\n";

	CG_DrawRotatedPicPhysical(scrPlace, x, y, width, height, angle, color, material);
}

