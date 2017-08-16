#pragma once

#include "../settings.h"
#include "../SDK/SDK.h"
#include "../Hooks/hooks.h"
#include "../interfaces.h"
#include "aimbot.h"
#include <lua.hpp>

namespace AntiAim
{
	bool GetBestHeadAngle(QAngle& angle);
	void LuaInit();
	void LuaCleanup();
	void CreateMove(CUserCmd* cmd);
}
