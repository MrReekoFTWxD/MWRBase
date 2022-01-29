#include "pch.h"

hudelem_color_t::hudelem_color_t(uint8_t val[3])
{
	this->r = val[0];
	this->g = val[1];
	this->b = val[2];
	this->a = val[3];
}
