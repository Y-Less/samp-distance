// Font: Roman
#if defined _inc_distance
    #undef _inc_distance
#endif

#if defined _distance_included
    #endinput
#endif
#define _distance_included

#include <a_samp>
#include <YSI_Data\y_iterate>

// Use `$` to denote a hard macro end.  So that matches don't escape their brackets.
#define _DISTANCE_E$

// Convenience macros to prepend `DISTANCE_` to everything.
#define _DISTANCE_A(%0...%1) DISTANCE_A(DISTANCE_%0..._%1)
#define _DISTANCE_B(%0...%1) DISTANCE_B(DISTANCE_%0..._%1)

/*
ooooooooo.              o8o                  .           ooooooooo.              o8o                  .   
`888   `Y88.            `"'                .o8           `888   `Y88.            `"'                .o8   
 888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo          888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo 
 888ooo88P'  d88' `88b `888  `888P"Y88b    888            888ooo88P'  d88' `88b `888  `888P"Y88b    888   
 888         888   888  888   888   888    888   8888888  888         888   888  888   888   888    888   
 888         888   888  888   888   888    888 .          888         888   888  888   888   888    888 . 
o888o        `Y8bod8P' o888o o888o o888o   "888"         o888o        `Y8bod8P' o888o o888o o888o   "888"
*/

stock Float:GetPointDistanceToPoint(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN) {
	if (_:y2 == _:FLOAT_NAN) {
		return VectorSize(x1 - z1, y1 - x2, 0.0);
	}

	return VectorSize(x1 - x2, y1 - y2, z1 - z2);
}

stock bool:IsPointInRangeOfPoint(Float:range, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN) {
	if (_:y2 == _:FLOAT_NAN) {
		return VectorSize(x1 - z1, y1 - x2, 0.0) <= range;
	}

	return VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range;
}

#define GetPointDistanceToPoint2D( GetPointDistanceToPoint(
#define GetPointDistanceToPoint3D( GetPointDistanceToPoint(

#define IsPointInRangeOfPoint2D( IsPointInRangeOfPoint(
#define IsPointInRangeOfPoint3D( IsPointInRangeOfPoint(

/*
ooooooooo.   oooo                                           
`888   `Y88. `888                                           
 888   .d88'  888   .oooo.   oooo    ooo  .ooooo.  oooo d8b 
 888ooo88P'   888  `P  )88b   `88.  .8'  d88' `88b `888""8P 
 888          888   .oP"888    `88..8'   888ooo888  888     
 888          888  d8(  888     `888'    888    .o  888     
o888o        o888o `Y888""8o     .8'     `Y8bod8P' d888b    
                             .o..P'                                                                                  
                             `Y8P'                                                                                   
*/

#if defined _ALS_GetPlayerDistanceFromPoint
	#undef GetPlayerDistanceFromPoint
#else
	#define _ALS_GetPlayerDistanceFromPoint
	native BAD_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
#endif

#if defined _ALS_IsPlayerInRangeOfPoint
	#undef IsPlayerInRangeOfPoint
#else
	#define _ALS_IsPlayerInRangeOfPoint
	native BAD_IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
#endif

stock Float:GetPlayerDistanceToPoint2D(playerid, Float:x, Float:y) {
	new Float:x2, Float:y2;

	if (GetPlayerPos(playerid, x2, y2, Float:playerid)) {
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

stock bool:IsPlayerInRangeOfPoint2D(playerid, Float:range, Float:x, Float:y) {
	new Float:x2, Float:y2;
	return GetPlayerPos(playerid, x2, y2, Float:playerid) && VectorSize(x - x2, y - y2, 0) <= range;
}

stock Float:GetPlayerDistanceToPoint3D(playerid, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x2, y2, z2)) {
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsPlayerInRangeOfPoint3D(playerid, Float:range, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;
	return GetPlayerPos(playerid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

stock Float:GetPlayerDistanceToPlayer(playerid, targetid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetPlayerPos(targetid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsPlayerInRangeOfPlayer(playerid, targetid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetPlayerPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid))
		&& (ignoreInterior || GetPlayerInterior(playerid) == GetPlayerInterior(targetid))
	;
}

stock GetClosestPlayerToPlayer(playerid, bool:ignoreVW = false, bool:ignoreInterior = false) {

	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z)) {
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	if (ignoreInterior) {

		if (ignoreVW) {

			foreach (new i : Player) {
				if (i == playerid) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}

		} else {
			new vw = GetPlayerVirtualWorld(playerid);

			foreach (new i : Player) {
				if (i == playerid || vw != GetPlayerVirtualWorld(i)) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		}

	} else {

		if (ignoreVW) {

			new interior = GetPlayerInterior(playerid);

			foreach (new i : Player) {
				if (i == playerid || interior != GetPlayerInterior(i)) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}

		} else {
			new vw = GetPlayerVirtualWorld(playerid), interior = GetPlayerInterior(playerid);

			foreach (new i : Player) {
				if (i == playerid || vw != GetPlayerVirtualWorld(i) || interior != GetPlayerInterior(i)) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		}

	}

	return closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetPlayerDistanceToPoint(%0) GetPlayerDistanceToPoint2D(%0)_DISTANCE_E$
#define GetPlayerDistanceToPoint2D(%0,%1,%2,%3)_DISTANCE_E$ GetPlayerDistanceToPoint3D(%0,%1,%2,%3)
#define GetPlayerDistanceFromPoint(%0) GetPlayerDistanceToPoint(%0)
#define _ALS_GetPlayerDistanceToPoint
#define _ALS_GetPlayerDistanceToPoint2D

#define IsPlayerInRangeOfPoint(%0) IsPlayerInRangeOfPoint2D(%0)_DISTANCE_E$
#define IsPlayerInRangeOfPoint2D(%0,%1,%2,%3,%4)_DISTANCE_E$ IsPlayerInRangeOfPoint3D(%0,%1,%2,%3,%4)
#define _ALS_IsPlayerInRangeOfPoint
#define _ALS_IsPlayerInRangeOfPoint2D

/*
oooooo     oooo           oooo         o8o            oooo            
 `888.     .8'            `888         `"'            `888            
  `888.   .8'    .ooooo.   888 .oo.   oooo   .ooooo.   888   .ooooo.  
   `888. .8'    d88' `88b  888P"Y88b  `888  d88' `"Y8  888  d88' `88b 
    `888.8'     888ooo888  888   888   888  888        888  888ooo888 
     `888'      888    .o  888   888   888  888   .o8  888  888    .o 
      `8'       `Y8bod8P' o888o o888o o888o `Y8bod8P' o888o `Y8bod8P' 
*/

#if defined _ALS_GetVehicleDistFromPoint
	#undef GetVehicleDistanceFromPoint
#else
	#define _ALS_GetVehicleDistFromPoint
	native BAD_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
#endif

stock Float:GetVehicleDistanceToPoint2D(vehicleid, Float:x, Float:y) {
	new Float:x2, Float:y2;

	if (GetVehiclePos(vehicleid, x2, y2, Float:vehicleid)) {
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

stock bool:IsVehicleInRangeOfPoint2D(vehicleid, Float:range, Float:x, Float:y) {
	new Float:x2, Float:y2;
	return GetVehiclePos(vehicleid, x2, y2, Float:vehicleid) && VectorSize(x - x2, y - y2, 0) <= range;
}

stock Float:GetVehicleDistanceToPoint3D(vehicleid, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x2, y2, z2)) {
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsVehicleInRangeOfPoint3D(vehicleid, Float:range, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;
	return GetVehiclePos(vehicleid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

stock Float:GetVehicleDistanceToVehicle(vehicleid, targetid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetVehiclePos(targetid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsVehicleInRangeOfVehicle(vehicleid, targetid, Float:range, bool:ignoreVW = false) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetVehiclePos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetVehicleVirtualWorld(vehicleid) == GetVehicleVirtualWorld(targetid))
	;
}

stock GetClosestVehicleToVehicle(vehicleid, bool:ignoreVW = false) {

	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z)) {
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	if (ignoreVW) {

		foreach (new i : Vehicle) {
			if (i == vehicleid) {
				continue;
			}

			if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
				distance = distance2;
				closestid = i;
			}
		}

	} else {
		new vw = GetVehicleVirtualWorld(vehicleid);

		foreach (new i : Vehicle) {
			if (i == vehicleid || vw != GetVehicleVirtualWorld(i)) {
				continue;
			}

			if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
				distance = distance2;
				closestid = i;
			}
		}
	}

	return closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetVehicleDistanceToPoint(%0) GetVehicleDistanceToPoint2D(%0)_DISTANCE_E$
#define GetVehicleDistanceToPoint2D(%0,%1,%2,%3)_DISTANCE_E$ GetVehicleDistanceToPoint3D(%0,%1,%2,%3)
#define GetVehicleDistanceFromPoint(%0) GetVehicleDistanceToPoint(%0)
#define _ALS_GetVehicleDistanceToPoint
#define _ALS_GetVehicleDistanceToPoint2D

#define IsVehicleInRangeOfPoint(%0) IsVehicleInRangeOfPoint2D(%0)_DISTANCE_E$
#define IsVehicleInRangeOfPoint2D(%0,%1,%2,%3,%4)_DISTANCE_E$ IsVehicleInRangeOfPoint3D(%0,%1,%2,%3,%4)
#define _ALS_IsVehicleInRangeOfPoint
#define _ALS_IsVehicleInRangeOfPoint2D

/*
  .oooooo.    .o8           o8o                         .   
 d8P'  `Y8b  "888           `"'                       .o8   
888      888  888oooo.     oooo  .ooooo.   .ooooo.  .o888oo 
888      888  d88' `88b    `888 d88' `88b d88' `"Y8   888   
888      888  888   888     888 888ooo888 888         888   
`88b    d88'  888   888     888 888    .o 888   .o8   888 . 
 `Y8bood8P'   `Y8bod8P'     888 `Y8bod8P' `Y8bod8P'   "888" 
                            888                             
                        .o. 88P                             
                        `Y888P                              
*/

stock Float:GetObjectDistanceToPoint2D(objectid, Float:x, Float:y) {
	new Float:x2, Float:y2;

	if (GetObjectPos(objectid, x2, y2, Float:objectid)) {
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

stock bool:IsObjectInRangeOfPoint2D(objectid, Float:range, Float:x, Float:y) {
	new Float:x2, Float:y2;
	return GetObjectPos(objectid, x2, y2, Float:objectid) && VectorSize(x - x2, y - y2, 0) <= range;
}

stock Float:GetObjectDistanceToPoint3D(objectid, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x2, y2, z2)) {
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsObjectInRangeOfPoint3D(objectid, Float:range, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;
	return GetObjectPos(objectid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

stock Float:GetObjectDistanceToObject(objectid, targetid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetObjectPos(targetid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsObjectInRangeOfObject(objectid, targetid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestObjectToObject(objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z)) {
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i) if (IsValidObject(i)) {
		if (i == objectid) {
			continue;
		}

		if ((distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetObjectDistanceToPoint(%0) GetObjectDistanceToPoint2D(%0)_DISTANCE_E$
#define GetObjectDistanceToPoint2D(%0,%1,%2,%3)_DISTANCE_E$ GetObjectDistanceToPoint3D(%0,%1,%2,%3)
#define _ALS_GetObjectDistanceToPoint
#define _ALS_GetObjectDistanceToPoint2D

#define IsObjectInRangeOfPoint(%0) IsObjectInRangeOfPoint2D(%0)_DISTANCE_E$
#define IsObjectInRangeOfPoint2D(%0,%1,%2,%3,%4)_DISTANCE_E$ IsObjectInRangeOfPoint3D(%0,%1,%2,%3,%4)
#define _ALS_IsObjectInRangeOfPoint
#define _ALS_IsObjectInRangeOfPoint2D

/*
oooooooooo.                                                        o8o                    .oooooo.    .o8           o8o                         .   
`888'   `Y8b                                                       `"'                   d8P'  `Y8b  "888           `"'                       .o8   
 888      888 oooo    ooo ooo. .oo.    .oooo.   ooo. .oo.  .oo.   oooo   .ooooo.        888      888  888oooo.     oooo  .ooooo.   .ooooo.  .o888oo 
 888      888  `88.  .8'  `888P"Y88b  `P  )88b  `888P"Y88bP"Y88b  `888  d88' `"Y8       888      888  d88' `88b    `888 d88' `88b d88' `"Y8   888   
 888      888   `88..8'    888   888   .oP"888   888   888   888   888  888             888      888  888   888     888 888ooo888 888         888   
 888     d88'    `888'     888   888  d8(  888   888   888   888   888  888   .o8       `88b    d88'  888   888     888 888    .o 888   .o8   888 . 
o888bood8P'       .8'     o888o o888o `Y888""8o o888o o888o o888o o888o `Y8bod8P'        `Y8bood8P'   `Y8bod8P'     888 `Y8bod8P' `Y8bod8P'   "888" 
              .o..P'                                                                                                888                             
              `Y8P'                                                                                             .o. 88P                             
                                                                                                                `Y888P                              
*/

stock Float:GetDynObjectDistanceToPoint2D(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y) {
	new Float:x2, Float:y2;

	if (GetDynamicObjectPos(objectid, x2, y2, Float:objectid)) {
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

stock bool:IsDynObjectInRangeOfPoint2D(STREAMER_TAG_OBJECT:objectid, Float:range, Float:x, Float:y) {
	new Float:x2, Float:y2;
	return GetDynamicObjectPos(objectid, x2, y2, Float:objectid) && VectorSize(x - x2, y - y2, 0) <= range;
}

stock Float:GetDynObjectDistanceToPoint3D(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x2, y2, z2)) {
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsDynObjectInRangeOfPoint3D(STREAMER_TAG_OBJECT:objectid, Float:range, Float:x, Float:y, Float:z) {
	new Float:x2, Float:y2, Float:z2;
	return GetDynamicObjectPos(objectid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

stock Float:GetDynObjectDistanceToDynObject(STREAMER_TAG_OBJECT:objectid, STREAMER_TAG_OBJECT:targetid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetDynamicObjectPos(targetid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsDynObjectInRangeOfDynObject(STREAMER_TAG_OBJECT:objectid, STREAMER_TAG_OBJECT:targetid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetDynamicObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock STREAMER_TAG_OBJECT:GetClosestDynObjectToDynObject(STREAMER_TAG_OBJECT:objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z)) {
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = 0, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i) if (IsValidDynamicObject(i)) {
		if (STREAMER_TAG_OBJECT:i == objectid) {
			continue;
		}

		if ((distance2 = (Streamer_GetDistanceToItem( x,  y,  z, STREAMER_TYPE_OBJECT, i, Float:I@), Float:I@)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return STREAMER_TAG_OBJECT:closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetDynObjectDistanceToPoint(%0) GetDynObjectDistanceToPoint2D(%0)_DISTANCE_E$
#define GetDynObjectDistanceToPoint2D(%0,%1,%2,%3)_DISTANCE_E$ GetDynObjectDistanceToPoint3D(%0,%1,%2,%3)
#define _ALS_GetDynObjectDistanceToPoint
#define _ALS_GetDynObjectDistanceToPoint2D

#define IsDynObjectInRangeOfPoint(%0) IsDynObjectInRangeOfPoint2D(%0)_DISTANCE_E$
#define IsDynObjectInRangeOfPoint2D(%0,%1,%2,%3,%4)_DISTANCE_E$ IsDynObjectInRangeOfPoint3D(%0,%1,%2,%3,%4)
#define _ALS_IsDynObjectInRangeOfPoint
#define _ALS_IsDynObjectInRangeOfPoint2D

/*
oooooooooo.   ooooo oooooooooooo oooooooooooo 
`888'   `Y8b  `888' `888'     `8 `888'     `8 
 888      888  888   888          888         
 888      888  888   888oooo8     888oooo8    
 888      888  888   888    "     888    "    
 888     d88'  888   888          888         
o888bood8P'   o888o o888o        o888o        
*/

stock Float:GetVehicleDistanceToPlayer(vehicleid, playerid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetPlayerPos(playerid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetPlayerPos(playerid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetVehicleVirtualWorld(vehicleid) == GetPlayerVirtualWorld(playerid))
	;
}

stock GetClosestVehicleToPlayer(playerid, bool:ignoreVW = false) {

	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z)) {
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	if (ignoreVW) {

		foreach (new i : Vehicle) {
			if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
				distance = distance2;
				closestid = i;
			}
		}

	} else {
		new vw = GetPlayerVirtualWorld(playerid);

		foreach (new i : Vehicle) {
			if (vw != GetVehicleVirtualWorld(i)) {
				continue;
			}

			if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
				distance = distance2;
				closestid = i;
			}
		}
	}

	return closestid;
}

stock Float:GetPlayerDistanceToVehicle(playerid, vehicleid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetVehiclePos(vehicleid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetVehiclePos(vehicleid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(vehicleid))
	;
}

stock GetClosestPlayerToVehicle(vehicleid, bool:ignoreVW = false) {

	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z)) {
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	if (ignoreVW) {

		foreach (new i : Player) {
			if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
				distance = distance2;
				closestid = i;
			}
		}

	} else {
		new vw = GetVehicleVirtualWorld(vehicleid);

		foreach (new i : Player) {
			if (vw != GetPlayerVirtualWorld(i)) {
				continue;
			}

			if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
				distance = distance2;
				closestid = i;
			}
		}
	}

	return closestid;
}

stock Float:GetPlayerDistanceToObject(playerid, objectid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetObjectPos(objectid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsPlayerInRangeOfObject(playerid, objectid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestPlayerToObject(objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z)) {
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	foreach (new i : Player) {
		if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetObjectDistanceToPlayer(objectid, playerid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetPlayerPos(playerid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsObjectInRangeOfPlayer(objectid, playerid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetPlayerPos(playerid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestObjectToPlayer(playerid) {

	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z)) {
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i) if (IsValidObject(i)) {
		if ((distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetObjectDistanceToVehicle(objectid, vehicleid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetVehiclePos(vehicleid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsObjectInRangeOfVehicle(objectid, vehicleid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetVehiclePos(vehicleid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestObjectToVehicle(vehicleid) {

	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z)) {
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i) if (IsValidObject(i)) {
		if ((distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetVehicleDistanceToObject(vehicleid, objectid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetObjectPos(objectid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsVehicleInRangeOfObject(vehicleid, objectid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestVehicleToObject(objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z)) {
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	foreach (new i : Vehicle) {
		if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetDynObjectDistanceToPlayer(STREAMER_TAG_OBJECT:objectid, playerid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetPlayerPos(playerid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsDynObjectInRangeOfPlayer(STREAMER_TAG_OBJECT:objectid, playerid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetPlayerPos(playerid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock STREAMER_TAG_OBJECT:GetClosestDynObjectToPlayer(playerid) {

	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z)) {
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = 0, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i) if (IsValidDynamicObject(i)) {
		if ((distance2 = (Streamer_GetDistanceToItem( x,  y,  z, STREAMER_TYPE_OBJECT, i, Float:I@), Float:I@)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetPlayerDistanceToDynObject(playerid, STREAMER_TAG_OBJECT:objectid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetDynamicObjectPos(objectid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsPlayerInRangeOfDynObject(playerid, STREAMER_TAG_OBJECT:objectid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetDynamicObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestPlayerToDynObject(STREAMER_TAG_OBJECT:objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z)) {
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	foreach (new i : Player) {
		if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetDynObjectDistanceToObject(STREAMER_TAG_OBJECT:objectid, targetid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetObjectPos(targetid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsDynObjectInRangeOfObject(STREAMER_TAG_OBJECT:objectid, targetid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock STREAMER_TAG_OBJECT:GetClosestDynObjectToObject(objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z)) {
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = 0, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i) if (IsValidDynamicObject(i)) {
		if ((distance2 = (Streamer_GetDistanceToItem( x,  y,  z, STREAMER_TYPE_OBJECT, i, Float:I@), Float:I@)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetObjectDistanceToDynObject(objectid, STREAMER_TAG_OBJECT:targetid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetDynamicObjectPos(targetid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsObjectInRangeOfDynObject(objectid, STREAMER_TAG_OBJECT:targetid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetDynamicObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestObjectToDynObject(STREAMER_TAG_OBJECT:objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z)) {
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i) if (IsValidObject(i)) {
		if ((distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetDynObjectDistanceToVehicle(STREAMER_TAG_OBJECT:objectid, vehicleid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetVehiclePos(vehicleid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsDynObjectInRangeOfVehicle(STREAMER_TAG_OBJECT:objectid, vehicleid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetVehiclePos(vehicleid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock STREAMER_TAG_OBJECT:GetClosestDynObjectToVehicle(vehicleid) {

	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z)) {
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = 0, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i) if (IsValidDynamicObject(i)) {
		if ((distance2 = (Streamer_GetDistanceToItem( x,  y,  z, STREAMER_TYPE_OBJECT, i, Float:I@), Float:I@)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

stock Float:GetVehicleDistanceToDynObject(vehicleid, STREAMER_TAG_OBJECT:objectid) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetDynamicObjectPos(objectid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

stock bool:IsVehicleInRangeOfDynObject(vehicleid, STREAMER_TAG_OBJECT:objectid, Float:range) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetDynamicObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

stock GetClosestVehicleToDynObject(STREAMER_TAG_OBJECT:objectid) {

	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z)) {
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	foreach (new i : Vehicle) {
		if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

