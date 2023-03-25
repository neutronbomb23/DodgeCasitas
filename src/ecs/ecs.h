#pragma once

namespace ecs {
	using cmpId_type = unsigned __int8;
	enum cmpId : cmpId_type {
		_TRANSFORM = 0,
		_CTRL = 1,
		_DEACCELERATION = 2,
		_OPPOSITESIDE = 3,
		_DISABLEONEXIT = 4,
		_FOLLOW = 5,
		_DRAW = 6,
		_SCREENBOUNCE = 7,

		// do not remove this
		_LAST_CMP_ID
	};
	constexpr cmpId_type maxComponentId = _LAST_CMP_ID;

	using grpId_type = unsigned __int8;
	enum grpId : grpId_type {
		_grp_PLAYERS = 0,
		_grp_ENEMIES = 1,
		_LAST_GRP_ID
	};
	constexpr grpId_type maxGroupId = _LAST_GRP_ID;
}