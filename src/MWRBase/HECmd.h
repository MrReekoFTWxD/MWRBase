#ifndef HECMD_H
#define HECMD_H

struct HECmd
{
    hudelem_s* elem;

    HECmd();
    ~HECmd();

    void SetPosition(float x, float y, he_align_horz alignOrig, he_align_vert alignScreen);
    void SetColor(std::vector<uint8_t> color);
    void SetGlowColor(std::vector<uint8_t> color);

    void SetMaterial(const std::string& material, int width, int height);
    void SetLabel(const std::string& text, he_font_t font, float fontScale);

    void MoveOverTime(int time, float x, float y);
    void ScaleOverTime(int time, int width, int height);

    void FadeOverTime(int time, std::vector<uint8_t> color);
    void FadeAlphaOverTime(int time, uint8_t color);
    void FontScaleOverTime(int time, float scale);

    void SetVisibility(bool CanSee);

    void FreeElem();
};

HECmd* createRectangle(int client, float x, float y, float width, float height, he_align_horz horz_align, he_align_vert vert_align, std::vector<uint8_t> color, const std::string& material, int sort);
HECmd* createString(int client, const std::string& string, float x, float y, float fontScale, he_font_t font, he_align_horz horz_align, he_align_vert vert_align, std::vector<uint8_t> color, std::vector<uint8_t> glowcolor, int sort);

#endif