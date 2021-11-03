#include "../pch.h"
#include <iostream>

CL_RegisterFont_t CL_RegisterFont;
R_AddCmdDrawText_t R_AddCmdDrawText;
Material_RegisterHandle_t Material_RegisterHandle;
CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;
Get_ActiveScreenPlacement_t Get_ActiveScreenPlacement;
r_RenderFlags_t r_RenderFlags;
R_TextWidth_t R_TextWidth;

float white[4] = { 1,1,1,1 };
float black[4] = { 0,0,0,1 };
float green[4] = { 0, 1, 304 / 255, 1 };

void BasicDrawing()
{
	DrawTextInBox("Rimuru<3", 1080 / 2, 720 / 2, green, black);
}

void DrawGameText(const char* text,const char* font, float x, float y, float xScale, float yScale, float rotation, float* color)
{
	R_AddCmdDrawText(text, 0xFFF, CL_RegisterFont(font, 48), CL_RegisterFont(font, 48)->pixelHeight, x, y, xScale, yScale, rotation, color, r_RenderFlags(0), 0, 0, 0, 0);
}

void DrawShader(float x, float y, float w, float h, float a, float* color, const char* material)
{
	CG_DrawRotatedPicPhysical(Get_ActiveScreenPlacement(0), x, y,w, h, a, color, Material_RegisterHandle(material, 7));
}

void BoundingBox(float x, float y, float width, float height, float* color, float thickness)
{
	DrawShader(x - thickness, y - thickness, width + (thickness), thickness, 0, color); // Top
	DrawShader(x - thickness, y + height, width + (thickness), thickness, 0, color); // Bottom
	DrawShader(x - thickness, y - thickness, thickness, height + thickness, 0, color); // Left
	DrawShader(x + width, y - thickness, thickness, height + (thickness), 0, color); // Right
}

void DrawTextInBox(const char* text, int x, int y, float* backgroundColour, float* mainColour)
{
	int w = R_TextWidth(text, 0xFF, CL_RegisterFont("fonts/fira_mono_bold.ttf", 48));
	int h = CL_RegisterFont("fonts/fira_mono_bold.ttf", 48)->pixelHeight;

	DrawShader(x, y, w * 0.75, h * 0.75, 0, backgroundColour);
	DrawGameText(text, "fonts/fira_mono_bold.ttf", x, y + h * 0.75, 0.65, 0.75,0, white);
	BoundingBox(x, y, w * 0.75, h * 0.75, mainColour, 1);
}

