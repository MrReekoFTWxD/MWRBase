#include "pch.h"
#include "gsc.h"

void iprintln(const std::string& msg)
{
	Scr_AddString(msg.c_str());

	scrVmPub->outparamcount = 1;

	((void(*)())(ResolveImport() + iprintln_a))();
	Scr_ClearOutParams();
}

void iclientprintln(int client, const std::string& msg)
{
	scr_entref_t ref{ client, CLASS_ENTITY };

	Scr_AddString(msg.c_str());

	scrVmPub->outparamcount = 1;

	((void(*)(scr_entref_t ent))(ResolveImport() + iclientprintln_a))(ref);
	Scr_ClearOutParams();
}

vec3_t PlayerCmd_GetEye(int client)
{
	scr_entref_t ref{ client, CLASS_ENTITY };

	((void(*)(scr_entref_t ent))(ResolveImport() + geteye_a))(ref);

	float* ret = (float*)scrVmPub->top->u.vectorValue;
	Scr_ClearOutParams();
	return ret;
}

void Scr_MagicBullet(const char* weap, const float start[3], const float end[3])
{
	Scr_AddVector(end);
	Scr_AddVector(start);
	Scr_AddString(weap);

	scrVmPub->outparamcount = 3;

	((void(*)())(ResolveImport() + magicbullet_a))();
	Scr_ClearOutParams();
}
