#ifndef STRUCTS_H
#define STRUCTS_H

typedef unsigned __int16 scr_string_t;

#pragma region Address

enum func_addrs : unsigned __int64
{
	//Ptrs
	scrVmPub_a = 0xB7AE3C0,
	gentity_a = 0x71F19E0,
	levelTime_a = 0x7361F9C,

	//Hooks
	VM_Notify_a = 0x514560,

	//Scr
	Scr_AddString_a = 0x50EC50,
	Scr_AddVector_a = 0x50EE10,
	Scr_AddInt_a = 0x50EB70,
	Scr_AddFloat_a = 0x50EA80,
	Scr_AddEntity_a = 0x458D50,
	Scr_AddEntityNum_a = 0x50E9E0,
	Scr_AddUndefined_a = 0x50ED40,
	Scr_GetSelf_a = 0x50A330,
	Scr_ClearOutParams_a = 0x50F070,
	Scr_Notify_a = 0x4599C0,
	Scr_FreeHudElem_a = 0x458E40,

	//GSC
	iprintln_a = 0xb8450,
	iclientprintln_a = 0x40ffd0,
	magicbullet_a = 0x44b740,
	geteye_a = 0x438c20,

	//HudElem
	HudElem_Alloc_a = 0x41A420,

	//General
	SL_ConvertToString_a = 0x507CD0,
	G_MaterialIndex_a = 0x8B930,
	G_LocalizeStringIndex_a = 0x90CA0,
	CL_IsLocalClientInGame_a = 0x135890,
	Cmd_ResgisterNotification_a = 0x157550,

};

#pragma endregion

#pragma region ScrVmPub

enum classType
{
	CLASS_ENTITY = 0x0,
	CLASS_HUDELEM = 0x1,
	CLASS_PATHNODE = 0x2,
	CLASS_VEHICLENODE = 0x3,
	CLASS_VEHTRACK_SEGMENT = 0x4,
	CLASS_FXENTITY = 0x5,
	CLASS_COUNT = 0x6,
};

enum scrVarType
{
	VAR_UNDEFINED = 0x0,
	VAR_BEGIN_REF = 0x1,
	VAR_POINTER = 0x1,
	VAR_STRING = 0x2,
	VAR_ISTRING = 0x3,
	VAR_VECTOR = 0x4,
	VAR_END_REF = 0x5,
	VAR_FLOAT = 0x5,
	VAR_INTEGER = 0x6,
	VAR_CODEPOS = 0x7,
	VAR_PRECODEPOS = 0x8,
	VAR_FUNCTION = 0x9,
	VAR_BUILTIN_FUNCTION = 0xA,
	VAR_BUILTIN_METHOD = 0xB,
	VAR_STACK = 0xC,
	VAR_ANIMATION = 0xD,
	VAR_PRE_ANIMATION = 0xE,
	VAR_THREAD = 0xF,
	VAR_NOTIFY_THREAD = 0x10,
	VAR_TIME_THREAD = 0x11,
	VAR_CHILD_THREAD = 0x12,
	VAR_OBJECT = 0x13,
	VAR_DEAD_ENTITY = 0x14,
	VAR_ENTITY = 0x15,
	VAR_ARRAY = 0x16,
	VAR_DEAD_THREAD = 0x17,
	VAR_COUNT = 0x18,
	VAR_FREE = 0x18,
	VAR_THREAD_LIST = 0x19,
	VAR_ENDON_LIST = 0x1A,
	VAR_TOTAL_COUNT = 0x1B,
};

struct scr_entref_t
{
	unsigned __int16 entnum;
	unsigned __int16 classnum;
};

struct VariableStackBuffer
{
	const char* pos;
	unsigned __int16 size;
	unsigned __int16 bufLen;
	unsigned __int16 localId;
	unsigned __int8 time;
	char buf[1];
};

union VariableUnion
{
	int intValue;
	unsigned int uintValue;
	float floatValue;
	unsigned int stringValue;
	const float* vectorValue;
	const char* codePosValue;
	unsigned int pointerValue;
	VariableStackBuffer* stackValue;
	unsigned int entityOffset;
	int64_t entityPtr;
};

struct VariableValue
{
	VariableUnion u;
	int type;
};

struct function_stack_t
{
	const char* pos;
	unsigned int localId;
	unsigned int localVarCount;
	VariableValue* top;
	VariableValue* startTop;
};

struct function_frame_t
{
	function_stack_t fs;
	int topType;
};

struct scrVmPub_t
{
	unsigned int* localVars;
	VariableValue* maxstack;
	int function_count;
	function_frame_t* function_frame;
	VariableValue* top;
	unsigned int inparamcount;
	unsigned int outparamcount;
	function_frame_t function_frame_start[32];
	VariableValue stack[2048];
};

#pragma endregion

#pragma region HElem

enum he_type_t
{
	HE_TYPE_FREE = 0x0,
	HE_TYPE_TEXT = 0x1,
	HE_TYPE_VALUE = 0x2,
	HE_TYPE_PLAYERNAME = 0x3,
	HE_TYPE_MATERIAL = 0x4,
	HE_TYPE_TIMER_DOWN = 0x5,
	HE_TYPE_TIMER_UP = 0x6,
	HE_TYPE_TIMER_STATIC = 0x7,
	HE_TYPE_TENTHS_TIMER_DOWN = 0x8,
	HE_TYPE_TENTHS_TIMER_UP = 0x9,
	HE_TYPE_TENTHS_TIMER_STATIC = 0xA,
	HE_TYPE_CLOCK_DOWN = 0xB,
	HE_TYPE_CLOCK_UP = 0xC,
	HE_TYPE_WAYPOINT = 0xD,
	HE_TYPE_COUNT = 0xE,
};

enum he_font_t {
	HE_FONT_DEFAULT = 0x0,
	HE_FONT_BIGFIXED = 0x1,
	HE_FONT_SMALLFIXED = 0x2,
	HE_FONT_OBJECTIVE = 0x3,
	HE_FONT_BIG = 0x4,
	HE_FONT_SMALL = 0x5,
	HE_FONT_HUDBIG = 0x6,
	HE_FONT_HUDSMALL = 0x7,
	HE_FONT_BUTTONPROMPT = 0x7,
	HE_FONT_SUBTITLE = 0x7,
	HE_FONT_COUNT = 0x8,
};

enum he_align_horz {
	HORZ_SUBLEFT,
	HORZ_LEFT,
	HORZ_CENTER,
	HORZ_FULLSCREEN,
	HORZ_NOSCALE,
	HORZ_ALIGNTO640,
	HORZ_CENTER_SAFEAREA,
	HORZ_LEFT_ADJUSTABLE,
	HORZ_CENTER_ADJUSTABLE,
	HORZ_RIGHT_ADJUSTABLE,
};

enum he_align_vert {
	VERT_SUBTOP,
	VERT_TOP,
	VERT_MIDDLE,
	VERT_BOTTOM,
	VERT_FULLSCREEN,
	VERT_NOSCALE,
	VERT_ALIGNTO480,
	VERT_CENTER_SAFEAREA,
	VERT_TOP_ADJUSTABLE,
	VERT_MIDDLE_ADJUSTABLE,
	VERT_BOTTOM_ADJUSTABLE,
};

struct hudelem_color_t
{
	uint8_t r, g, b, a;

	hudelem_color_t(uint8_t val[3]);
};

struct hudelem_s
{
	short targetent1;
	short targetent2;
	int font; //4
	int alignOrg; //8
	int alignScreen; // c
	float x; //10
	float y; //14
	float z; //18
	int type; //1C
	float FontScale; //20
	int FromFontScale; //24
	int FontScaleStartTime; //28
	int FontScaleTime; //2C
	hudelem_color_t color; //30
	hudelem_color_t fromColor; //34
	int fadeStartTime; //38
	int fadeTime; // 3C
	int label; // 4
	int Width; // 44
	int Height; //48
	int MaterialIndex; //4C
	int fromWidth; //50
	int fromHeight; //54
	int scaleStartTime; //58
	int scaleTime; //5C
	float fromX; //60
	float fromY; //64
	int fromAlignOrg; //68
	int fromAlignScreen; //6C
	int moveStartTime; //70
	int moveTime; //74
	int time; //78
	int duration; //7C
	float value; // 80
	int text; //84
	float sort; //88
	hudelem_color_t glowColor; //8C
	int fxBirthTime; //90
	int fxLetterTime; // 94
	int fxDecayStartTime; //98
	int fxDecayDuration; //9C
	int soundID; // A0
	int unknown; //A4
	int unknown2; //A8
	char pad_00AC[24]; //0x00AC
	int flags; //0x00C4
	char pad_0x00C8[8];
};

#pragma endregion

#pragma region gentity

struct gentity_s
{
	int16_t entityNum; //0x0000
	char pad_0002[142]; //0x0002
	float viewAngles[3]; //0x0090
	char pad_009C[156]; //0x009C
	float origin[3]; //0x0138
	char pad_0144[412]; //0x0144
};

#pragma endregion

#define scrVmPub ((scrVmPub_t*)(ResolveImport() + scrVmPub_a))
#define g_entities ((gentity_s*)(ResolveImport() + gentity_a))
#define LevelTime (*(uint32_t*)(ResolveImport() + levelTime_a))


#endif