// Font: Roman
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

/// <p/>

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
stock Float:GetPointDistanceToPoint2D(Float:x1, Float:y1, Float:x2, Float:y2)
{
	return VectorSize(x1 - x2, y1 - y2, 0.0);
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetPointDistanceToPoint3D(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
	return VectorSize(x1 - x2, y1 - y2, z1 - z2);
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPointInRangeOfPoint2D(Float:range, Float:x1, Float:y1, Float:x2, Float:y2)
{
	return VectorSize(x1 - x2, y1 - y2, 0.0) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPointInRangeOfPoint3D(Float:range, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
	return VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range;
}

// Define two versions of the functions for different parameter counts.
#define GetPointDistanceToPoint(%0) GetPointDistanceToPoint2D(%0)PP_DISCARD$
#define GetPointDistanceToPoint2D(%0,%1,%2,%3,%4,%5)PP_DISCARD$ GetPointDistanceToPoint3D(%0,%1,%2,%3,%4,%5)
#define _ALS_GetPointDistanceToPoint
#define _ALS_GetPointDistanceToPoint2D

#define IsPointInRangeOfPoint(%0) IsPointInRangeOfPoint2D(%0)PP_DISCARD$
#define IsPointInRangeOfPoint2D(%0,%1,%2,%3,%4,%5,%6)PP_DISCARD$ IsPointInRangeOfPoint3D(%0,%1,%2,%3,%4,%5,%6)
#define _ALS_IsPointInRangeOfPoint
#define _ALS_IsPointInRangeOfPoint2D

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
 * <param name="playerid">The ID of the player to search from.</param>
 * <param name="targetid">The ID of the player to measure to.</param>
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
 * <param name="playerid">The ID of the player to search from.</param>
 * <param name="ignoreVW">Should entities in different virtual worlds be considered?</param>
 * <param name="ignoreInterior">Should entities in different interiors be considered?</param>
 * <returns>The ID of the closest player.</returns>
 * <remarks>
 *   Loops through all the players on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given player.
 *   Returns <c>INVALID_PLAYER_ID</c>If the input player is invalid,
 *   or there are no <em>other</em> players connected.
 * </remarks>
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
 * <param name="vehicleid">The ID of the vehicle to measure from.</param>
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
 * <param name="vehicleid">The ID of the vehicle to test.</param>
 */
stock bool:IsVehicleInRangeOfPoint2D(vehicleid, Float:range, Float:x, Float:y)
{
	new Float:x2, Float:y2;
	return GetVehiclePos(vehicleid, x2, y2, Float:vehicleid) && VectorSize(x - x2, y - y2, 0) <= range;
}

/**
 * <library>samp-distance</library>
 * <param name="vehicleid">The ID of the vehicle to measure from.</param>
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
 * <param name="vehicleid">The ID of the vehicle to test.</param>
 */
stock bool:IsVehicleInRangeOfPoint3D(vehicleid, Float:range, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;
	return GetVehiclePos(vehicleid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

/**
 * <library>samp-distance</library>
 * <param name="vehicleid">The ID of the vehicle to measure from.</param>
 * <param name="targetid">The ID of the vehicle to measure to.</param>
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
 * <param name="vehicleid">The ID of the vehicle to test.</param>
 * <param name="targetid">The ID of the vehicle to use as the origin.</param>
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
 * <param name="vehicleid">The ID of the vehicle to search from.</param>
 * <param name="ignoreVW">Should entities in different virtual worlds be considered?</param>
 * <returns>The ID of the closest vehicle.</returns>
 * <remarks>
 *   Loops through all the vehicles on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given vehicle.
 *   Returns <c>INVALID_VEHICLE_ID</c>If the input vehicle is invalid,
 *   or there are no <em>other</em> vehicles created.
 * </remarks>
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
 * <returns>The ID of the closest object.</returns>
 * <remarks>
 *   Loops through all the objects on the server and returns the ID of the one
 *   closest to the given object.
 *   Returns <c>INVALID_OBJECT_ID</c>If the input object is invalid,
 *   or there are no <em>other</em> objects created.
 * </remarks>
 */
stock GetClosestObjectToObject(objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != MAX_OBJECTS; ++i)
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
 * <returns>The ID of the closest dynamic object.</returns>
 * <remarks>
 *   Loops through all the dyanamic objects on the server (using
 *   <c>Streamer_GetUpperBound</c>) and returns the ID of the one
 *   closest to the given dynamic object.
 *   Returns <c>INVALID_STREAMER_ID</c>If the input dynamic object is invalid,
 *   or there are no <em>other</em> dynamic objects created.
 * </remarks>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToDynObject(STREAMER_TAG_OBJECT:objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z))
	{
		return STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = _:INVALID_STREAMER_ID, Float:distance2;

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
                                                              
           db                                                     
          d88b                     ,d                             
         d8'`8b                    88                             
        d8'  `8b      ,adPPYba,  MM88MMM  ,adPPYba,   8b,dPPYba,  
       d8YaaaaY8b    a8"     ""    88    a8"     "8a  88P'   "Y8  
      d8""""""""8b   8b            88    8b       d8  88          
     d8'        `8b  "8a,   ,aa    88,   "8a,   ,a8"  88          
    d8'          `8b  `"Ybbd8"'    "Y888  `"YbbdP"'   88          


*/

/**
 * <library>samp-distance</library>
 */
stock Float:GetActorDistanceToPoint2D(actorid, Float:x, Float:y)
{
	new Float:x2, Float:y2;

	if (GetActorPos(actorid, x2, y2, Float:actorid))
	{
		return VectorSize(x - x2, y - y2, 0);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsActorInRangeOfPoint2D(actorid, Float:range, Float:x, Float:y)
{
	new Float:x2, Float:y2;
	return GetActorPos(actorid, x2, y2, Float:actorid) && VectorSize(x - x2, y - y2, 0) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetActorDistanceToPoint3D(actorid, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;

	if (GetActorPos(actorid, x2, y2, z2))
	{
		return VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsActorInRangeOfPoint3D(actorid, Float:range, Float:x, Float:y, Float:z)
{
	new Float:x2, Float:y2, Float:z2;
	return GetActorPos(actorid, x2, y2, z2) && VectorSize(x - x2, y - y2, z - z2) <= range;
}

/**
 * <library>samp-distance</library>
 */
stock Float:GetActorDistanceToActor(actorid, targetid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetActorPos(actorid, x1, y1, z1) && GetActorPos(targetid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsActorInRangeOfActor(actorid, targetid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetActorPos(actorid, x1, y1, z1)
		&& GetActorPos(targetid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 * <returns>The ID of the closest actor.</returns>
 * <remarks>
 *   Loops through all the actor on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given actor.
 *   Returns <c>INVALID_ACTOR_ID</c>If the input actor is invalid,
 *   or there are no <em>other</em> actors created.
 * </remarks>
 */
stock GetClosestActorToActor(actorid)
{
	new Float:x, Float:y, Float:z;

	if (!GetActorPos(actorid, x, y, z))
	{
		return INVALID_ACTOR_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_ACTOR_ID, Float:distance2;

	foreach (new i : Actor)
	{
		if (i != actorid && (distance2 = GetActorDistanceToPoint3D(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

// Define two versions of the functions for different parameter counts.
#define GetActorDistanceToPoint(%0) GetActorDistanceToPoint2D(%0)PP_DISCARD$
#define GetActorDistanceToPoint2D(%0,%1,%2,%3)PP_DISCARD$ GetActorDistanceToPoint3D(%0,%1,%2,%3)
#define _ALS_GetActorDistanceToPoint
#define _ALS_GetActorDistanceToPoint2D

#define IsActorInRangeOfPoint(%0) IsActorInRangeOfPoint2D(%0)PP_DISCARD$
#define IsActorInRangeOfPoint2D(%0,%1,%2,%3,%4)PP_DISCARD$ IsActorInRangeOfPoint3D(%0,%1,%2,%3,%4)
#define _ALS_IsActorInRangeOfPoint
#define _ALS_IsActorInRangeOfPoint2D

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
 * <param name="vehicleid">The ID of the vehicle to measure from.</param>
 * <param name="playerid">The ID of the player to measure to.</param>
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
 * <param name="vehicleid">The ID of the vehicle to test.</param>
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
 * <param name="playerid">The ID of the player to search from.</param>
 * <param name="ignoreVW">Should entities in different virtual worlds be considered?</param>
 * <returns>The ID of the closest vehicle.</returns>
 * <remarks>
 *   Loops through all the vehicles on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given player.
 *   Returns <c>INVALID_VEHICLE_ID</c>If the input player is invalid,
 *   or there are no vehicles created.
 * </remarks>
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
 * <param name="playerid">The ID of the player to search from.</param>
 * <param name="vehicleid">The ID of the vehicle to measure to.</param>
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
 * <param name="vehicleid">The ID of the vehicle to search from.</param>
 * <param name="ignoreVW">Should entities in different virtual worlds be considered?</param>
 * <returns>The ID of the closest player.</returns>
 * <remarks>
 *   Loops through all the players on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given vehicl.
 *   Returns <c>INVALID_PLAYER_ID</c>If the input vehicle is invalid,
 *   or there are no players connected.
 * </remarks>
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
 * <returns>The ID of the closest player.</returns>
 * <remarks>
 *   Loops through all the players on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given object.
 *   Returns <c>INVALID_PLAYER_ID</c>If the input object is invalid,
 *   or there are no players connected.
 * </remarks>
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
 * <param name="playerid">The ID of the player to measure to.</param>
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
 * <param name="playerid">The ID of the player to search from.</param>
 * <returns>The ID of the closest object.</returns>
 * <remarks>
 *   Loops through all the objects on the server and returns the ID of the one
 *   closest to the given player.
 *   Returns <c>INVALID_OBJECT_ID</c>If the input player is invalid,
 *   or there are no objects created.
 * </remarks>
 */
stock GetClosestObjectToPlayer(playerid)
{
	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != MAX_OBJECTS; ++i)
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
 * <param name="vehicleid">The ID of the vehicle to measure to.</param>
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
 * <param name="vehicleid">The ID of the vehicle to search from.</param>
 * <param name="ignoreVW">Should entities in different virtual worlds be considered?</param>
 * <returns>The ID of the closest object.</returns>
 * <remarks>
 *   Loops through all the objects on the server and returns the ID of the one
 *   closest to the given vehicle.
 *   Returns <c>INVALID_OBJECT_ID</c>If the input vehicle is invalid,
 *   or there are no objects created.
 * </remarks>
 */
stock GetClosestObjectToVehicle(vehicleid)
{
	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != MAX_OBJECTS; ++i)
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
 * <param name="vehicleid">The ID of the vehicle to measure from.</param>
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
 * <param name="vehicleid">The ID of the vehicle to test.</param>
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
 * <returns>The ID of the closest vehicle.</returns>
 * <remarks>
 *   Loops through all the vehicles on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given object.
 *   Returns <c>INVALID_VEHICLE_ID</c>If the input object is invalid,
 *   or there are no vehicles created.
 * </remarks>
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
 * <param name="playerid">The ID of the player to measure to.</param>
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
 * <param name="playerid">The ID of the player to search from.</param>
 * <returns>The ID of the closest dynamic object.</returns>
 * <remarks>
 *   Loops through all the dyanamic objects on the server (using
 *   <c>Streamer_GetUpperBound</c>) and returns the ID of the one
 *   closest to the given player.
 *   Returns <c>INVALID_STREAMER_ID</c>If the input player is invalid,
 *   or there are no dynamic objects created.
 * </remarks>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToPlayer(playerid)
{
	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z))
	{
		return STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = _:INVALID_STREAMER_ID, Float:distance2;

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
 * <returns>The ID of the closest player.</returns>
 * <remarks>
 *   Loops through all the players on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given dynamic object.
 *   Returns <c>INVALID_PLAYER_ID</c>If the input dynamic object is invalid,
 *   or there are no players connected.
 * </remarks>
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
 * <returns>The ID of the closest dynamic object.</returns>
 * <remarks>
 *   Loops through all the dyanamic objects on the server (using
 *   <c>Streamer_GetUpperBound</c>) and returns the ID of the one
 *   closest to the given object.
 *   Returns <c>INVALID_STREAMER_ID</c>If the input object is invalid,
 *   or there are no dynamic objects created.
 * </remarks>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToObject(objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z))
	{
		return STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = _:INVALID_STREAMER_ID, Float:distance2;

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
 * <returns>The ID of the closest object.</returns>
 * <remarks>
 *   Loops through all the objects on the server and returns the ID of the one
 *   closest to the given dynamic object.
 *   Returns <c>INVALID_OBJECT_ID</c>If the input dynamic object is invalid,
 *   or there are no objects created.
 * </remarks>
 */
stock GetClosestObjectToDynObject(STREAMER_TAG_OBJECT:objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != MAX_OBJECTS; ++i)
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
 * <param name="vehicleid">The ID of the vehicle to measure to.</param>
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
 * <param name="vehicleid">The ID of the vehicle to search from.</param>
 * <returns>The ID of the closest dynamic object.</returns>
 * <remarks>
 *   Loops through all the dyanamic objects on the server (using
 *   <c>Streamer_GetUpperBound</c>) and returns the ID of the one
 *   closest to the given vehicle.
 *   Returns <c>INVALID_STREAMER_ID</c>If the input vehicle is invalid,
 *   or there are no dynamic objects created.
 * </remarks>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToVehicle(vehicleid)
{
	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z))
	{
		return STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = _:INVALID_STREAMER_ID, Float:distance2;

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
 * <param name="vehicleid">The ID of the vehicle to measure from.</param>
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
 * <param name="vehicleid">The ID of the vehicle to test.</param>
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
 * <returns>The ID of the closest vehicle.</returns>
 * <remarks>
 *   Loops through all the vehicles on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given dynamic object.
 *   Returns <c>INVALID_VEHICLE_ID</c>If the input dynamic object is invalid,
 *   or there are no vehicles created.
 * </remarks>
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

/**
 * <library>samp-distance</library>
 * <param name="vehicleid">The ID of the vehicle to measure from.</param>
 */
stock Float:GetVehicleDistanceToActor(vehicleid, actorid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetVehiclePos(vehicleid, x1, y1, z1) && GetActorPos(actorid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 * <param name="vehicleid">The ID of the vehicle to test.</param>
 */
stock bool:IsVehicleInRangeOfActor(vehicleid, actorid, Float:range, bool:ignoreVW = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetVehiclePos(vehicleid, x1, y1, z1)
		&& GetActorPos(actorid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetVehicleVirtualWorld(vehicleid) == GetActorVirtualWorld(actorid))
	;
}

/**
 * <library>samp-distance</library>
 * <returns>The ID of the closest vehicle.</returns>
 * <remarks>
 *   Loops through all the vehicles on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given actor.
 *   Returns <c>INVALID_VEHICLE_ID</c>If the input actor is invalid,
 *   or there are no vehicles created.
 * </remarks>
 */
stock GetClosestVehicleToActor(actorid, bool:ignoreVW = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetActorPos(actorid, x, y, z))
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
		new vw = GetActorVirtualWorld(actorid);

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
 * <param name="vehicleid">The ID of the vehicle to measure to.</param>
 */
stock Float:GetActorDistanceToVehicle(actorid, vehicleid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;if (GetActorPos(actorid, x1, y1, z1) && GetVehiclePos(vehicleid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsActorInRangeOfVehicle(actorid, vehicleid, Float:range, bool:ignoreVW = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetActorPos(actorid, x1, y1, z1)
		&& GetVehiclePos(vehicleid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetActorVirtualWorld(actorid) == GetVehicleVirtualWorld(vehicleid))
	;
}

/**
 * <library>samp-distance</library>
 * <param name="vehicleid">The ID of the vehicle to search from.</param>
 * <param name="ignoreVW">Should entities in different virtual worlds be considered?</param>
 * <returns>The ID of the closest actor.</returns>
 * <remarks>
 *   Loops through all the actor on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given vehicle.
 *   Returns <c>INVALID_ACTOR_ID</c>If the input vehicle is invalid,
 *   or there are no actors created.
 * </remarks>
 */
stock GetClosestActorToVehicle(vehicleid, bool:ignoreVW = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetVehiclePos(vehicleid, x, y, z))
	{
		return INVALID_ACTOR_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_ACTOR_ID, Float:distance2;

	if (ignoreVW)
	{
		foreach (new i : Actor)
		{
			if ((distance2 = GetActorDistanceToPoint3D(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}
	}
	else
	{
		new vw = GetVehicleVirtualWorld(vehicleid);

		foreach (new i : Actor)
		{
			if (vw == GetActorVirtualWorld(i) && (distance2 = GetActorDistanceToPoint3D(i, x, y, z)) < distance)
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
stock Float:GetActorDistanceToObject(actorid, objectid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetActorPos(actorid, x1, y1, z1) && GetObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsActorInRangeOfObject(actorid, objectid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetActorPos(actorid, x1, y1, z1)
		&& GetObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 * <returns>The ID of the closest actor.</returns>
 * <remarks>
 *   Loops through all the actor on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given object.
 *   Returns <c>INVALID_ACTOR_ID</c>If the input object is invalid,
 *   or there are no actors created.
 * </remarks>
 */
stock GetClosestActorToObject(objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetObjectPos(objectid, x, y, z))
	{
		return INVALID_ACTOR_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_ACTOR_ID, Float:distance2;

	foreach (new i : Actor)
	{
		if ((distance2 = GetActorDistanceToPoint3D(i, x, y, z)) < distance)
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
stock Float:GetObjectDistanceToActor(objectid, actorid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x1, y1, z1) && GetActorPos(actorid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsObjectInRangeOfActor(objectid, actorid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetObjectPos(objectid, x1, y1, z1)
		&& GetActorPos(actorid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 * <returns>The ID of the closest object.</returns>
 * <remarks>
 *   Loops through all the objects on the server and returns the ID of the one
 *   closest to the given actor.
 *   Returns <c>INVALID_OBJECT_ID</c>If the input actor is invalid,
 *   or there are no objects created.
 * </remarks>
 */
stock GetClosestObjectToActor(actorid)
{
	new Float:x, Float:y, Float:z;

	if (!GetActorPos(actorid, x, y, z))
	{
		return INVALID_OBJECT_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_OBJECT_ID, Float:distance2;

	for (new i = 0; i != MAX_OBJECTS; ++i)
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
stock Float:GetDynObjectDistanceToActor(STREAMER_TAG_OBJECT:objectid, actorid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetDynamicObjectPos(objectid, x1, y1, z1) && GetActorPos(actorid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsDynObjectInRangeOfActor(STREAMER_TAG_OBJECT:objectid, actorid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetDynamicObjectPos(objectid, x1, y1, z1)
		&& GetActorPos(actorid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 * <returns>The ID of the closest dynamic object.</returns>
 * <remarks>
 *   Loops through all the dyanamic objects on the server (using
 *   <c>Streamer_GetUpperBound</c>) and returns the ID of the one
 *   closest to the given actor.
 *   Returns <c>INVALID_STREAMER_ID</c>If the input actor is invalid,
 *   or there are no dynamic objects created.
 * </remarks>
 */
stock STREAMER_TAG_OBJECT:GetClosestDynObjectToActor(actorid)
{
	new Float:x, Float:y, Float:z;

	if (!GetActorPos(actorid, x, y, z))
	{
		return STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = _:INVALID_STREAMER_ID, Float:distance2;

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
stock Float:GetActorDistanceToDynObject(actorid, STREAMER_TAG_OBJECT:objectid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetActorPos(actorid, x1, y1, z1) && GetDynamicObjectPos(objectid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsActorInRangeOfDynObject(actorid, STREAMER_TAG_OBJECT:objectid, Float:range)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetActorPos(actorid, x1, y1, z1)
		&& GetDynamicObjectPos(objectid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
	;
}

/**
 * <library>samp-distance</library>
 * <returns>The ID of the closest actor.</returns>
 * <remarks>
 *   Loops through all the actor on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given dynamic object.
 *   Returns <c>INVALID_ACTOR_ID</c>If the input dynamic object is invalid,
 *   or there are no actors created.
 * </remarks>
 */
stock GetClosestActorToDynObject(STREAMER_TAG_OBJECT:objectid)
{
	new Float:x, Float:y, Float:z;

	if (!GetDynamicObjectPos(objectid, x, y, z))
	{
		return INVALID_ACTOR_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_ACTOR_ID, Float:distance2;

	foreach (new i : Actor)
	{
		if ((distance2 = GetActorDistanceToPoint3D(i, x, y, z)) < distance)
		{
			distance = distance2;
			closestid = i;
		}
	}

	return closestid;
}

/**
 * <library>samp-distance</library>
 * <param name="playerid">The ID of the player to measure to.</param>
 */
stock Float:GetActorDistanceToPlayer(actorid, playerid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetActorPos(actorid, x1, y1, z1) && GetPlayerPos(playerid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsActorInRangeOfPlayer(actorid, playerid, Float:range, bool:ignoreVW = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetActorPos(actorid, x1, y1, z1)
		&& GetPlayerPos(playerid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetActorVirtualWorld(actorid) == GetPlayerVirtualWorld(playerid))
	;
}

/**
 * <library>samp-distance</library>
 * <param name="playerid">The ID of the player to search from.</param>
 * <param name="ignoreVW">Should entities in different virtual worlds be considered?</param>
 * <returns>The ID of the closest actor.</returns>
 * <remarks>
 *   Loops through all the actor on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given player.
 *   Returns <c>INVALID_ACTOR_ID</c>If the input player is invalid,
 *   or there are no actors created.
 * </remarks>
 */
stock GetClosestActorToPlayer(playerid, bool:ignoreVW = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetPlayerPos(playerid, x, y, z))
	{
		return INVALID_VEHICLE_ID;
	}

	new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2;

	if (ignoreVW)
	{
		foreach (new i : Actor)
		{
			if ((distance2 = GetActorDistanceToPoint3D(i, x, y, z)) < distance)
			{
				distance = distance2;
				closestid = i;
			}
		}

	}
	else
	{
		new vw = GetPlayerVirtualWorld(playerid);

		foreach (new i : Actor)
		{
			if (vw == GetActorVirtualWorld(i) && (distance2 = GetActorDistanceToPoint3D(i, x, y, z)) < distance)
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
stock Float:GetPlayerDistanceToActor(playerid, actorid)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (GetPlayerPos(playerid, x1, y1, z1) && GetActorPos(actorid, x2, y2, z2))
	{
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}

/**
 * <library>samp-distance</library>
 */
stock bool:IsPlayerInRangeOfActor(playerid, actorid, Float:range, bool:ignoreVW = false)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	return GetPlayerPos(playerid, x1, y1, z1)
		&& GetActorPos(actorid, x2, y2, z2)
		&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
		&& (ignoreVW || GetPlayerVirtualWorld(playerid) == GetActorVirtualWorld(actorid))
	;
}

/**
 * <library>samp-distance</library>
 * <returns>The ID of the closest player.</returns>
 * <remarks>
 *   Loops through all the players on the server (using <c>foreach</c>) and
 *   returns the ID of the one closest to the given actor.
 *   Returns <c>INVALID_PLAYER_ID</c>If the input actor is invalid,
 *   or there are no players connected.
 * </remarks>
 */
stock GetClosestPlayerToActor(actorid, bool:ignoreVW = false)
{
	new Float:x, Float:y, Float:z;

	if (!GetActorPos(actorid, x, y, z))
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
		new vw = GetActorVirtualWorld(actorid);

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


