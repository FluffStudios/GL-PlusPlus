#include "bufferutils.h"

glpp::MapAccess glpp::operator|(const MapAccess LHS, const MapAccess RHS)
{
	return static_cast<glpp::MapAccess>(static_cast<int>(LHS) | static_cast<int>(RHS));
}
