#ifndef DEFINES_H
#define DEFINES_H


typedef void(*VM_Notify_t)(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue* top);
typedef hudelem_s* (*HudElem_Alloc_t)(int index, int team);
typedef char* (*SL_ConvertToString_t)(unsigned int stringValue);
typedef int(*G_MaterialIndex_t)(const char* shader);
typedef int(*G_LocalizeStringIndex_t)(const char* text);

typedef void(*Scr_AddString_t)(const char* value);
typedef void(*Scr_AddVector_t)(const float* value);
typedef void(*Scr_AddInt_t)(int value);
typedef void(*Scr_AddEntity_t)(gentity_s* value);
typedef void(*Scr_AddFloat_t)(float value);
typedef void(*Scr_AddEntityNum_t)(int entnum, classType classnum);
typedef void(*Scr_AddUndefined_t)();
typedef unsigned int(*Scr_GetSelf_t)(uint32_t threadId);
typedef void(*Scr_ClearOutParams_t)();
typedef void(*Scr_Notify_t)(gentity_s* ent, scr_string_t value, int param);
typedef void(*Scr_FreeHudElem_t)(hudelem_s* elem);

typedef bool(*CL_IsLocalClientInGame_t)(int local);
typedef void(*Cmd_ResgisterNotification_t)(int client, const char* cmd, const char* notify);


extern VM_Notify_t VM_Notify;
extern HudElem_Alloc_t HudElem_Alloc;
extern SL_ConvertToString_t SL_ConvertToString;
extern G_MaterialIndex_t G_MaterialIndex;
extern G_LocalizeStringIndex_t G_LocalizeStringIndex;

extern Scr_AddString_t Scr_AddString;
extern Scr_AddVector_t Scr_AddVector;
extern Scr_AddInt_t Scr_AddInt;
extern Scr_AddEntity_t Scr_AddEntity;
extern Scr_AddFloat_t Scr_AddFloat;
extern Scr_AddEntityNum_t Scr_AddEntityNum;
extern Scr_AddUndefined_t Scr_AddUndefined;
extern Scr_GetSelf_t Scr_GetSelf;
extern Scr_ClearOutParams_t Scr_ClearOutParams;
extern Scr_Notify_t Scr_Notify;
extern Scr_FreeHudElem_t Scr_FreeHudElem;

extern CL_IsLocalClientInGame_t CL_IsLocalClientInGame;
extern Cmd_ResgisterNotification_t Cmd_ResgisterNotification;



#endif