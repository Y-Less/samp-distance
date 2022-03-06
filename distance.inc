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

/**
 * <library name="samp-distance" summary="Distance calculations for players, objects, vehicles, and more.">
 *   <license>
 *     (c) Copyright 2019-2022, Kristoberg and Y_Less.
 *   </license>
 *   <summary pawndoc="true">
 *     This library uses the enhanced <em>pawndoc.xsl</em> from
 *     <a href="https://github.com/pawn-lang/pawndoc">pawn-lang/pawndoc</a>.
 *     This XSL has features such as library and markdown support, and will not
 *     render this message when used.
 *   </summary>
 * </library>
 */

///

#define PP_DISCARD%0$

/*

    ooooooooo.              o8o                  .           ooooooooo.              o8o                  .
    `888   `Y88.            `"'                .o8           `888   `Y88.            `"'                .o8
     888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo          888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo
     888ooo88P'  d88' `88b `888  `888P"Y88b    888            888ooo88P'  d88' `88b `888  `888P"Y88b    888
     888         888   888  888   888   888    888   8888888  888         888   888  888   888   888    888
     888         888   888  888   888   888    888 .          888         888   888  888   888   888    888 .
    o888o        `Y8bod8P' o888o o888o o888o   "888"         o888o        `Y8bod8P' o888o o888o o888o   "888"

*/

/**
 * <library>samp-distance</library>
 */
stock Float:GetPointDistanceToPoint(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN)
{
	if (IS_NAN(y2))
	{
		return VectorSize(x1 - z1, y1 - x2, 0.0);
	}

	return VectorSize(x1 - x2, y1 - y2, z1 - z2);
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPointInRangeOfPoint(Float:range, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN)
{
	if (IS_NAN(y2))
	{
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

/**
 * <library>samp-distance</library>
 */
stock Float:GetPlayerDistanceToPoint2D(playerid, Float:x, Float:y)
{
	new Float:x2, Float:y2;

	if (GetPlayerPos(playerid, x2, y2, Float:playerid))
	{
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPlayerInRangeOfPoint2D(playerid, Float:range, Float:x, Float:y)
{
	new Float:x2, Float:y2;
	return GetPlayerPos(playerid, x2, y2, Float:playerid) && VectorSize(x - x2, y - y2, 0) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetPlayerDistanceToPoint3D(playerid, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x2, y2, z2))
	{
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPlayerInRangeOfPoint3D(playerid, Float:range, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;
	return GetPlayerPos(playerid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetPlayerDistanceToPlayer(playerid, targetid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetPlayerPos(targetid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPlayerInRangeOfPlayer(playerid, targetid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetPlayerPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid))
		&& (ignoreInterior || GetPlayerInterior(playerid) == GetPlayerInterior(targetid))
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestPlayerToPlayer(playerid, bool:ignoreVW = false, bool:ignoreInterior = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z))
	{
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	if (ignoreInterior)
	{
		if (ignoreVW)
		{
			foreach (new i : Player)
			{
				if (i != playerid && (distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
				{
					distance = distance2;
					closestid = i;
				}
			}
		}
		else
		{
			new vw = GetPlayerVirtualWorld(playerid);

			foreach (new i : Player)
			{
				if (i != playerid && vw == GetPlayerVirtualWorld(i) && (distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
				{
					distance = distance2;
					closestid = i;
				}
			}
		}
	}
	else
	{
		if (ignoreVW)
		{
			new interior = GetPlayerInterior(playerid);

			foreach (new i : Player)
			{
				if (i != playerid && interior == GetPlayerInterior(i) && (distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
				{
					distance = distance2;
					closestid = i;
				}
			}
		}
		else
		{
			new vw = GetPlayerVirtualWorld(playerid), interior = GetPlayerInterior(playerid);

			foreach (new i : Player)
			{
				if (i != playerid && vw == GetPlayerVirtualWorld(i) && interior == GetPlayerInterior(i) && (distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
				{
					distance = distance2;
					closestid = i;
				}
			}
		}
	}

	return closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetPlayerDistanceToPoint(%0) GetPlayerDistanceToPoint2D(%0)PP_DISCARD$
#define GetPlayerDistanceToPoint2D(%0,%1,%2,%3)PP_DISCARD$ GetPlayerDistanceToPoint3D(%0,%1,%2,%3)
#define GetPlayerDistanceFromPoint( GetPlayerDistanceToPoint(
#define _ALS_GetPlayerDistanceToPoint
#define _ALS_GetPlayerDistanceToPoint2D

#define IsPlayerInRangeOfPoint(%0) IsPlayerInRangeOfPoint2D(%0)PP_DISCARD$
#define IsPlayerInRangeOfPoint2D(%0,%1,%2,%3,%4)PP_DISCARD$ IsPlayerInRangeOfPoint3D(%0,%1,%2,%3,%4)
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

/**
 * <library>samp-distance</library>
 */
stock Float:GetVehicleDistanceToPoint2D(vehicleid, Float:x, Float:y)
{
	new Float:x2, Float:y2;

	if (GetVehiclePos(vehicleid, x2, y2, Float:vehicleid))
	{
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsVehicleInRangeOfPoint2D(vehicleid, Float:range, Float:x, Float:y)
{
	new Float:x2, Float:y2;
	return GetVehiclePos(vehicleid, x2, y2, Float:vehicleid) && VectorSize(x - x2, y - y2, 0) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetVehicleDistanceToPoint3D(vehicleid, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x2, y2, z2))
	{
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsVehicleInRangeOfPoint3D(vehicleid, Float:range, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;
	return GetVehiclePos(vehicleid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetVehicleDistanceToVehicle(vehicleid, targetid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetVehiclePos(targetid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsVehicleInRangeOfVehicle(vehicleid, targetid, Float:range, bool:ignoreVW = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetVehiclePos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetVehicleVirtualWorld(vehicleid) == GetVehicleVirtualWorld(targetid))
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestVehicleToVehicle(vehicleid, bool:ignoreVW = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z))
	{
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	if (ignoreVW)
	{
		foreach (new i : Vehicle)
		{
			if (i != vehicleid && (distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}
	}
	else
	{
		new vw = GetVehicleVirtualWorld(vehicleid);

		foreach (new i : Vehicle)
		{
			if (i != vehicleid && vw == GetVehicleVirtualWorld(i) && (distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}
	}

	return closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetVehicleDistanceToPoint(%0) GetVehicleDistanceToPoint2D(%0)PP_DISCARD$
#define GetVehicleDistanceToPoint2D(%0,%1,%2,%3)PP_DISCARD$ GetVehicleDistanceToPoint3D(%0,%1,%2,%3)
#define GetVehicleDistanceFromPoint( GetVehicleDistanceToPoint(
#define _ALS_GetVehicleDistanceToPoint
#define _ALS_GetVehicleDistanceToPoint2D

#define IsVehicleInRangeOfPoint(%0) IsVehicleInRangeOfPoint2D(%0)PP_DISCARD$
#define IsVehicleInRangeOfPoint2D(%0,%1,%2,%3,%4)PP_DISCARD$ IsVehicleInRangeOfPoint3D(%0,%1,%2,%3,%4)
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

/**
 * <library>samp-distance</library>
 */
stock Float:GetObjectDistanceToPoint2D(objectid, Float:x, Float:y)
{
	new Float:x2, Float:y2;

	if (GetObjectPos(objectid, x2, y2, Float:objectid))
	{
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsObjectInRangeOfPoint2D(objectid, Float:range, Float:x, Float:y)
{
	new Float:x2, Float:y2;
	return GetObjectPos(objectid, x2, y2, Float:objectid) && VectorSize(x - x2, y - y2, 0) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetObjectDistanceToPoint3D(objectid, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsObjectInRangeOfPoint3D(objectid, Float:range, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;
	return GetObjectPos(objectid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetObjectDistanceToObject(objectid, targetid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetObjectPos(targetid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsObjectInRangeOfObject(objectid, targetid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestObjectToObject(objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i)
	{
		if (i != objectid && IsValidObject(i) && (distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetObjectDistanceToPoint(%0) GetObjectDistanceToPoint2D(%0)PP_DISCARD$
#define GetObjectDistanceToPoint2D(%0,%1,%2,%3)PP_DISCARD$ GetObjectDistanceToPoint3D(%0,%1,%2,%3)
#define _ALS_GetObjectDistanceToPoint
#define _ALS_GetObjectDistanceToPoint2D

#define IsObjectInRangeOfPoint(%0) IsObjectInRangeOfPoint2D(%0)PP_DISCARD$
#define IsObjectInRangeOfPoint2D(%0,%1,%2,%3,%4)PP_DISCARD$ IsObjectInRangeOfPoint3D(%0,%1,%2,%3,%4)
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

/**
 * <library>samp-distance</library>
 */
stock Float:GetDynObjectDistanceToPoint2D(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y)
{
	new Float:x2, Float:y2;

	if (GetDynamicObjectPos(objectid, x2, y2, Float:objectid))
	{
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsDynObjectInRangeOfPoint2D(STREAMER_TAG_OBJECT:objectid, Float:range, Float:x, Float:y)
{
	new Float:x2, Float:y2;
	return GetDynamicObjectPos(objectid, x2, y2, Float:objectid) && VectorSize(x - x2, y - y2, 0) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetDynObjectDistanceToPoint3D(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsDynObjectInRangeOfPoint3D(STREAMER_TAG_OBJECT:objectid, Float:range, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;
	return GetDynamicObjectPos(objectid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetDynObjectDistanceToDynObject(STREAMER_TAG_OBJECT:objectid, STREAMER_TAG_OBJECT:targetid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetDynamicObjectPos(targetid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsDynObjectInRangeOfDynObject(STREAMER_TAG_OBJECT:objectid, STREAMER_TAG_OBJECT:targetid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetDynamicObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToDynObject(STREAMER_TAG_OBJECT:objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z))
	{
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_STREAMER_ID, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i)
	{
		if (STREAMER_TAG_OBJECT:i != objectid && IsValidDynamicObject(STREAMER_TAG_OBJECT:i) && (distance2 = (Streamer_GetDistanceToItem(x, y, z, STREAMER_TYPE_OBJECT, STREAMER_TAG_OBJECT:i, Float:I@), Float:I@)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return STREAMER_TAG_OBJECT:closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetDynObjectDistanceToPoint(%0) GetDynObjectDistanceToPoint2D(%0)PP_DISCARD$
#define GetDynObjectDistanceToPoint2D(%0,%1,%2,%3)PP_DISCARD$ GetDynObjectDistanceToPoint3D(%0,%1,%2,%3)
#define _ALS_GetDynObjectDistanceToPoint
#define _ALS_GetDynObjectDistanceToPoint2D

#define IsDynObjectInRangeOfPoint(%0) IsDynObjectInRangeOfPoint2D(%0)PP_DISCARD$
#define IsDynObjectInRangeOfPoint2D(%0,%1,%2,%3,%4)PP_DISCARD$ IsDynObjectInRangeOfPoint3D(%0,%1,%2,%3,%4)
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

/**
 * <library>samp-distance</library>
 */
stock Float:GetVehicleDistanceToPlayer(vehicleid, playerid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetPlayerPos(playerid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetPlayerPos(playerid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetVehicleVirtualWorld(vehicleid) == GetPlayerVirtualWorld(playerid))
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestVehicleToPlayer(playerid, bool:ignoreVW = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z))
	{
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	if (ignoreVW)
	{
		foreach (new i : Vehicle)
		{
			if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}

	}
	else
	{
		new vw = GetPlayerVirtualWorld(playerid);

		foreach (new i : Vehicle)
		{
			if (vw == GetVehicleVirtualWorld(i) && (distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetPlayerDistanceToVehicle(playerid, vehicleid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetVehiclePos(vehicleid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetVehiclePos(vehicleid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(vehicleid))
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestPlayerToVehicle(vehicleid, bool:ignoreVW = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z))
	{
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	if (ignoreVW)
	{
		foreach (new i : Player)
		{
			if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}
	}
	else
	{
		new vw = GetVehicleVirtualWorld(vehicleid);

		foreach (new i : Player)
		{
			if (vw == GetPlayerVirtualWorld(i) && (distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetPlayerDistanceToObject(playerid, objectid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPlayerInRangeOfObject(playerid, objectid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestPlayerToObject(objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z))
	{
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	foreach (new i : Player)
	{
		if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetObjectDistanceToPlayer(objectid, playerid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetPlayerPos(playerid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsObjectInRangeOfPlayer(objectid, playerid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetPlayerPos(playerid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestObjectToPlayer(playerid)
{
	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i)
	{
		if (IsValidObject(i) && (distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetObjectDistanceToVehicle(objectid, vehicleid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetVehiclePos(vehicleid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsObjectInRangeOfVehicle(objectid, vehicleid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetVehiclePos(vehicleid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestObjectToVehicle(vehicleid)
{
	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i)
	{
		if (IsValidObject(i) && (distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetVehicleDistanceToObject(vehicleid, objectid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsVehicleInRangeOfObject(vehicleid, objectid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestVehicleToObject(objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z))
	{
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	foreach (new i : Vehicle)
	{
		if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetDynObjectDistanceToPlayer(STREAMER_TAG_OBJECT:objectid, playerid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetPlayerPos(playerid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsDynObjectInRangeOfPlayer(STREAMER_TAG_OBJECT:objectid, playerid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetPlayerPos(playerid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToPlayer(playerid)
{
	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z))
	{
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_STREAMER_ID, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i)
	{
		if (IsValidDynamicObject(STREAMER_TAG_OBJECT:i) && (distance2 = (Streamer_GetDistanceToItem(x, y, z, STREAMER_TYPE_OBJECT, STREAMER_TAG_OBJECT:i, Float:I@), Float:I@)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return STREAMER_TAG_OBJECT:closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetPlayerDistanceToDynObject(playerid, STREAMER_TAG_OBJECT:objectid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetDynamicObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPlayerInRangeOfDynObject(playerid, STREAMER_TAG_OBJECT:objectid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetDynamicObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestPlayerToDynObject(STREAMER_TAG_OBJECT:objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z))
	{
		return INVALID_PLAYER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;

	foreach (new i : Player)
	{
		if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetDynObjectDistanceToObject(STREAMER_TAG_OBJECT:objectid, targetid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetObjectPos(targetid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsDynObjectInRangeOfObject(STREAMER_TAG_OBJECT:objectid, targetid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToObject(objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z))
	{
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_STREAMER_ID, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i)
	{
		if (IsValidDynamicObject(STREAMER_TAG_OBJECT:i) && (distance2 = (Streamer_GetDistanceToItem(x, y, z, STREAMER_TYPE_OBJECT, STREAMER_TAG_OBJECT:i, Float:I@), Float:I@)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return STREAMER_TAG_OBJECT:closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetObjectDistanceToDynObject(objectid, STREAMER_TAG_OBJECT:targetid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetDynamicObjectPos(targetid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsObjectInRangeOfDynObject(objectid, STREAMER_TAG_OBJECT:targetid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetDynamicObjectPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestObjectToDynObject(STREAMER_TAG_OBJECT:objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != INVALID_OBJECT_ID; ++i)
	{
		if (IsValidObject(i) && (distance2 = GetObjectDistanceToPoint3D(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetDynObjectDistanceToVehicle(STREAMER_TAG_OBJECT:objectid, vehicleid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetVehiclePos(vehicleid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsDynObjectInRangeOfVehicle(STREAMER_TAG_OBJECT:objectid, vehicleid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetVehiclePos(vehicleid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToVehicle(vehicleid)
{
	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z))
	{
		return 0;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_STREAMER_ID, Float:distance2;

	for (new i = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i; --i)
	{
		if (IsValidDynamicObject(STREAMER_TAG_OBJECT:i) && (distance2 = (Streamer_GetDistanceToItem(x, y, z, STREAMER_TYPE_OBJECT, STREAMER_TAG_OBJECT:i, Float:I@), Float:I@)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return STREAMER_TAG_OBJECT:closestid;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetVehicleDistanceToDynObject(vehicleid, STREAMER_TAG_OBJECT:objectid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetDynamicObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsVehicleInRangeOfDynObject(vehicleid, STREAMER_TAG_OBJECT:objectid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetDynamicObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 */
stock GetClosestVehicleToDynObject(STREAMER_TAG_OBJECT:objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z))
	{
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	foreach (new i : Vehicle)
	{
		if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

