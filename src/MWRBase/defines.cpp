#include "pch.h"
#include "defines.h"

VM_Notify_t VM_Notify = VM_Notify_t(ResolveImport() + VM_Notify_a);

HudElem_Alloc_t HudElem_Alloc = HudElem_Alloc_t(ResolveImport() + HudElem_Alloc_a);

SL_ConvertToString_t SL_ConvertToString = SL_ConvertToString_t(ResolveImport() + SL_ConvertToString_a);
G_MaterialIndex_t G_MaterialIndex = G_MaterialIndex_t(ResolveImport() + G_MaterialIndex_a);
G_LocalizeStringIndex_t G_LocalizeStringIndex = G_LocalizeStringIndex_t(ResolveImport() + G_LocalizeStringIndex_a);

Scr_AddString_t Scr_AddString = Scr_AddString_t(ResolveImport() + Scr_AddString_a);
Scr_AddVector_t Scr_AddVector = Scr_AddVector_t(ResolveImport() + Scr_AddVector_a);
Scr_AddInt_t Scr_AddInt = Scr_AddInt_t(ResolveImport() + Scr_AddInt_a);
Scr_AddEntity_t Scr_AddEntity = Scr_AddEntity_t(ResolveImport() + Scr_AddEntity_a);
Scr_AddFloat_t Scr_AddFloat = Scr_AddFloat_t(ResolveImport() + Scr_AddFloat_a);
Scr_AddEntityNum_t Scr_AddEntityNum = Scr_AddEntityNum_t(ResolveImport() + Scr_AddEntityNum_a);
Scr_AddUndefined_t Scr_AddUndefined = Scr_AddUndefined_t(ResolveImport() + Scr_AddUndefined_a);
Scr_GetSelf_t Scr_GetSelf = Scr_GetSelf_t(ResolveImport() + Scr_GetSelf_a);
Scr_ClearOutParams_t Scr_ClearOutParams = Scr_ClearOutParams_t(ResolveImport() + Scr_ClearOutParams_a);
Scr_Notify_t Scr_Notify = Scr_Notify_t(ResolveImport() + Scr_Notify_a);
Scr_FreeHudElem_t Scr_FreeHudElem = Scr_FreeHudElem_t(ResolveImport() + Scr_FreeHudElem_a);

CL_IsLocalClientInGame_t CL_IsLocalClientInGame = CL_IsLocalClientInGame_t(ResolveImport() + CL_IsLocalClientInGame_a);
Cmd_ResgisterNotification_t Cmd_ResgisterNotification = Cmd_ResgisterNotification_t(ResolveImport() + Cmd_ResgisterNotification_a);

