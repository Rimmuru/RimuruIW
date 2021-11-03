#pragma once

void DrawGameText(const char* text, const char* font, float x, float y, float xScale, float yScale, float rotation, float* color);
void DrawShader(float x, float y, float w, float h, float a, float* color, const char* material = "white");
void BoundingBox(float x, float y, float width, float height, float* color, float thickness);
void DrawTextInBox(const char* text, int x, int y, float* backgroundColour, float* mainColour);

void BasicDrawing();

struct Font
{
	const char* name;
	int pixelHeight;
};

typedef void (*R_AddCmdDrawText_t)(const char* text, int maxChars, void* font, int fontHeight, float x, float y, float xScale, float yScale, float rotation, const float* color, int64_t style, int flag1, int flag2, int flag3, int flag4); extern R_AddCmdDrawText_t R_AddCmdDrawText;

typedef void(*CG_DrawRotatedPicPhysical_t)(void* scr, float x, float y, float w, float h, float angle, float* color, void* material); 
extern CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;

typedef void* (*Material_RegisterHandle_t)(const char* shader, int imgTrack);
extern Material_RegisterHandle_t Material_RegisterHandle;

typedef Font*(*CL_RegisterFont_t)(const char* a1, int a2);
extern CL_RegisterFont_t CL_RegisterFont;

typedef void*(*Get_ActiveScreenPlacement_t)(int a);
extern Get_ActiveScreenPlacement_t Get_ActiveScreenPlacement;

typedef int64_t(*r_RenderFlags_t)(int a);
extern r_RenderFlags_t r_RenderFlags;

typedef int(*R_TextWidth_t)(const char* text, int MaxChars, Font* font);
extern R_TextWidth_t R_TextWidth;