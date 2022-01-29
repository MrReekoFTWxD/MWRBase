#ifndef GSC_H
#define GSC_H

void iprintln(const std::string& msg);
void iclientprintln(int client, const std::string& msg);

void Scr_MagicBullet(const char* weap, const float start[3], const float end[3]);

vec3_t PlayerCmd_GetEye(int client);

#endif