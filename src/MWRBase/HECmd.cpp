#include "pch.h"
#include "HECmd.h"


HECmd::HECmd()
{
	this->elem = nullptr;
}

HECmd::~HECmd()
{
}


void HECmd::SetPosition(float x, float y, he_align_horz alignOrig, he_align_vert alignScreen)
{
	this->elem->x = x;
	this->elem->y = y;
	this->elem->alignOrg = alignOrig;
	this->elem->alignScreen = alignScreen;
}

void HECmd::SetColor(std::vector<uint8_t> color)
{
	this->elem->color = &color[0];
}

void HECmd::SetGlowColor(std::vector<uint8_t> color)
{
	this->elem->glowColor = &color[0];
}

void HECmd::SetMaterial(const std::string& material, int width, int height)
{
	this->elem->type = HE_TYPE_MATERIAL;
	this->elem->MaterialIndex = G_MaterialIndex(material.c_str());
	this->elem->Width = width;
	this->elem->Height = height;
}

void HECmd::SetLabel(const std::string& text, he_font_t font, float fontScale)
{
	this->elem->type = HE_TYPE_TEXT;
	this->elem->label = G_LocalizeStringIndex(text.c_str());
	this->elem->font = font;
	this->elem->FontScale = fontScale;
}

void HECmd::MoveOverTime(int time, float x, float y)
{
	this->elem->fromX = this->elem->x;
	this->elem->fromY = this->elem->y;
	this->elem->moveStartTime = LevelTime;
	this->elem->moveTime = time;
	this->SetPosition(x, y, (he_align_horz)this->elem->alignOrg, (he_align_vert)this->elem->alignScreen);
}

void HECmd::FadeOverTime(int time, std::vector<uint8_t> color)
{
	this->elem->fromColor = this->elem->color;
	this->elem->fadeStartTime = LevelTime;
	this->elem->fadeTime = time;
	this->SetColor(color);

}

void HECmd::FadeAlphaOverTime(int time, uint8_t color)
{
	this->elem->fromColor = this->elem->color;
	this->elem->fadeStartTime = LevelTime;
	this->elem->fadeTime = time;
	this->elem->color.a = color;
}

void HECmd::FontScaleOverTime(int time, float scale)
{
	this->elem->FromFontScale = this->elem->FontScale;
	this->elem->FontScaleStartTime = LevelTime;
	this->elem->FontScaleTime = time;
	this->elem->FontScale = scale;
}

void HECmd::SetVisibility(bool CanSee)
{
	this->elem->flags = CanSee ? 2 : 1;
}

void HECmd::ScaleOverTime(int time, int width, int height)
{
	this->elem->fromWidth = this->elem->Width;
	this->elem->fromHeight = this->elem->Height;
	this->elem->scaleStartTime = LevelTime;
	this->elem->scaleTime = time;
	this->elem->Width = width;
	this->elem->Height = height;

}

void HECmd::FreeElem()
{
	if (!this->elem)
		return;
	this->elem->type = HE_TYPE_FREE;
	Scr_FreeHudElem(this->elem);
	this->elem = nullptr;
}

HECmd* createRectangle(int client, float x, float y, float width, float height, he_align_horz horz_align, he_align_vert vert_align, std::vector<uint8_t> color, const std::string& material, int sort)
{
	struct HECmd* hecmd = new HECmd();

	hecmd->elem = HudElem_Alloc(client, 0);

	if (!hecmd->elem)
		return nullptr;

	hecmd->SetPosition(x, y, horz_align, vert_align);
	hecmd->SetMaterial(material, width, height);
	hecmd->SetColor(color);

	hecmd->elem->sort = sort;
	//hecmd->elem->flags = 2;

	return hecmd;
}

HECmd* createString(int client, const std::string& string, float x, float y, float fontScale, he_font_t font, he_align_horz horz_align, he_align_vert vert_align, std::vector<uint8_t> color, std::vector<uint8_t> glowcolor, int sort)
{
	struct HECmd* hecmd = new HECmd();

	hecmd->elem = HudElem_Alloc(client, 0);

	if (!hecmd->elem)
		return nullptr;

	hecmd->SetPosition(x, y, horz_align, vert_align);
	hecmd->SetLabel(string, font, fontScale);
	hecmd->SetColor(color);
	hecmd->SetGlowColor(glowcolor);

	hecmd->elem->sort = sort;
	//hecmd->elem->flags = 2;

	return hecmd;
}
