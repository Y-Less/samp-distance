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

#define DISTANCE_Player_Distance BAD_GetPlayerDistanceFromPoint
#define DISTANCE_Player_Interior GetPlayerInterior
#define DISTANCE_Player_VW GetPlayerVirtualWorld
#define DISTANCE_Player_Pos GetPlayerPos
#define DISTANCE_Player_Invalid() INVALID_PLAYER_ID
#define DISTANCE_Player_Loop(%0) foreach (new %0 : Player)

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

#define DISTANCE_A(%0...%1) %0Player%1
#include "distance_point"

/*
native GetPlayerDistanceToPlayer(playerid2, playerid1);
native IsPlayerInRangeOfPlayer(playerid2, playerid1, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestPlayerToPlayer(playerid1, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Player%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0Player%1Player%2
#define DISTANCE_INT
#define DISTANCE_VW

#include "distance_diff"

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

#define DISTANCE_Vehicle_Distance BAD_GetVehicleDistanceFromPoint
#define DISTANCE_Vehicle_Interior GetVehicleInterior
#define DISTANCE_Vehicle_VW GetVehicleVirtualWorld
#define DISTANCE_Vehicle_Pos GetVehiclePos
#define DISTANCE_Vehicle_Invalid() INVALID_VEHICLE_ID
#define DISTANCE_Vehicle_Loop(%0) foreach (new %0 : Vehicle)

#if defined _ALS_GetVehicleDistFromPoint
    #undef GetVehicleDistanceFromPoint
#else
    #define _ALS_GetVehicleDistFromPoint
    native BAD_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
#endif

#define DISTANCE_A(%0...%1) %0Vehicle%1
#include "distance_point"

/*
native GetVehicleDistanceToVehicle(vehicleid2, vehicleid1);
native IsVehicleInRangeOfVehicle(vehicleid2, vehicleid1, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestVehicleToVehicle(vehicleid1, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Vehicle%1
#define DISTANCE_B(%0...%1) %0Vehicle%1
#define DISTANCE_AB(%0...%1...%2) %0Vehicle%1Vehicle%2
#if defined GetVehicleInterior
	#define DISTANCE_INT
#endif
#define DISTANCE_VW

#include "distance_diff"

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

#define DISTANCE_Object_Distance GetObjectDistanceToPoint3D
#define DISTANCE_Object_Pos GetObjectPos
#define DISTANCE_Object_Invalid() INVALID_OBJECT_ID
#define DISTANCE_Object_Loop(%0) for (new %0 = 0; %0 != INVALID_OBJECT_ID; ++%0) if (IsValidObject(%0))

#define DISTANCE_A(%0...%1) %0Object%1
#include "distance_point"

/*
native GetObjectDistanceToObject(objectid2, objectid1);
native IsObjectInRangeOfObject(objectid2, objectid1, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestObjectToObject(objectid1, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Object%1
#define DISTANCE_B(%0...%1) %0Object%1
#define DISTANCE_AB(%0...%1...%2) %0Object%1Object%2

#include "distance_diff"

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

#define DISTANCE_DynObject_Distance(%0,%1,%2,%3) (Streamer_GetDistanceToItem(%1, %2, %3, STREAMER_TYPE_OBJECT, %0, Float:I@), Float:I@)
#define DISTANCE_DynObject_Pos GetDynamicObjectPos
#define DISTANCE_DynObject_Invalid() 0
#define DISTANCE_DynObject_Loop(%0) for (new %0 = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); %0; --%0) if (IsValidDynamicObject(%0))

#define DISTANCE_A(%0...%1) %0DynObject%1
#include "distance_point"

/*
native GetDynObjectDistanceToDynObject(objectid2, objectid1);
native IsDynObjectInRangeOfDynObject(objectid2, objectid1, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestDynObjectToDynObject(objectid1, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0DynObject%1
#define DISTANCE_B(%0...%1) %0DynObject%1
#define DISTANCE_AB(%0...%1...%2) %0DynObject%1DynObject%2

#include "distance_diff"

// Define two versions of the functions for different parameter counts.
#define GetDynObjectDistanceToPoint(%0) GetDynObjectDistanceToPoint2D(%0)_DISTANCE_E$
#define GetDynObjectDistanceToPoint2D(%0,%1,%2,%3)_DISTANCE_E$ GetDynObjectDistanceToPoint3D(%0,%1,%2,%3)
#define _ALS_GetDynObjectDistanceToPoint
#define _ALS_GetDynObjectDistanceToPoint2D

#define IsDynObjectInRangeOfPoint(%0) IsDynObjectInRangeOfPoint2D(%0)_DISTANCE_E$
#define IsDynObjectInRangeOfPoint2D(%0,%1,%2,%3,%4)_DISTANCE_E$ IsDynObjectInRangeOfPoint3D(%0,%1,%2,%3,%4)
#define _ALS_IsDynObjectInRangeOfPoint
#define _ALS_IsDynObjectInRangeOfPoint2D

// Input:

#if 0

Player,Player,playerid1,playerid2
Vehicle,Vehicle,vehicleid1,vehicleid2
Object,Object,objectid1,objectid2
DynObject,DynObject,objectid1,objectid2
Vehicle,Player,vehicleid,playerid
Player,Object,playerid,objectid
Object,Vehicle,objectid,vehicleid
DynObject,Player,dynobj,playerid
DynObject,Object,dynobj,objectid
DynObject,Vehicle,dynobj,vehicleid

#endif

// Search:
//
//     (.*),(.*),(.*),(.*)
//
// Replace:

#if 0

/*
native Get\1DistanceTo\2\(\3, \4\);
native Is\1InRangeOf\2\(\3, \4, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false\);
native GetClosest\1To\2\(\4, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false\);
*/

#define DISTANCE_A\(%0...%1\) %0\1%1
#define DISTANCE_B\(%0...%1\) %0\2%1
#define DISTANCE_AB\(%0...%1...%2\) %0\1%1\2%2
#define DISTANCE_INT
#define DISTANCE_VW

#include "distance_diff"

/*
native Get\2DistanceTo\1\(\4, \3\);
native Is\2InRangeOf\1\(\4, \3, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false\);
native GetClosest\2To\1\(\3, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false\);
*/

#define DISTANCE_A\(%0...%1\) %0\2%1
#define DISTANCE_B\(%0...%1\) %0\1%1
#define DISTANCE_AB\(%0...%1...%2\) %0\2%1\1%2
#define DISTANCE_INT
#define DISTANCE_VW

#include "distance_diff"

#endif

/*
native GetVehicleDistanceToPlayer(vehicleid, playerid);
native IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Vehicle%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0Vehicle%1Player%2
#if defined GetVehicleInterior
	#define DISTANCE_INT
#endif
#define DISTANCE_VW

#include "distance_diff"

/*
native GetPlayerDistanceToVehicle(playerid, vehicleid);
native IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestPlayerToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Player%1
#define DISTANCE_B(%0...%1) %0Vehicle%1
#define DISTANCE_AB(%0...%1...%2) %0Player%1Vehicle%2
#if defined GetVehicleInterior
	#define DISTANCE_INT
#endif
#define DISTANCE_VW

#include "distance_diff"

/*
native GetPlayerDistanceToObject(playerid, objectid);
native IsPlayerInRangeOfObject(playerid, objectid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestPlayerToObject(objectid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Player%1
#define DISTANCE_B(%0...%1) %0Object%1
#define DISTANCE_AB(%0...%1...%2) %0Player%1Object%2

#include "distance_diff"

/*
native GetObjectDistanceToPlayer(objectid, playerid);
native IsObjectInRangeOfPlayer(objectid, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestObjectToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Object%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0Object%1Player%2

#include "distance_diff"

/*
native GetObjectDistanceToVehicle(objectid, vehicleid);
native IsObjectInRangeOfVehicle(objectid, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestObjectToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Object%1
#define DISTANCE_B(%0...%1) %0Vehicle%1
#define DISTANCE_AB(%0...%1...%2) %0Object%1Vehicle%2

#include "distance_diff"

/*
native GetVehicleDistanceToObject(vehicleid, objectid);
native IsVehicleInRangeOfObject(vehicleid, objectid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestVehicleToObject(objectid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Vehicle%1
#define DISTANCE_B(%0...%1) %0Object%1
#define DISTANCE_AB(%0...%1...%2) %0Vehicle%1Object%2

#include "distance_diff"

/*
native GetDynObjectDistanceToPlayer(dynobj, playerid);
native IsDynObjectInRangeOfPlayer(dynobj, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestDynObjectToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0DynObject%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0DynObject%1Player%2

#include "distance_diff"

/*
native GetPlayerDistanceToDynObject(playerid, dynobj);
native IsPlayerInRangeOfDynObject(playerid, dynobj, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestPlayerToDynObject(dynobj, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Player%1
#define DISTANCE_B(%0...%1) %0DynObject%1
#define DISTANCE_AB(%0...%1...%2) %0Player%1DynObject%2

#include "distance_diff"

/*
native GetDynObjectDistanceToObject(dynobj, objectid);
native IsDynObjectInRangeOfObject(dynobj, objectid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestDynObjectToObject(objectid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0DynObject%1
#define DISTANCE_B(%0...%1) %0Object%1
#define DISTANCE_AB(%0...%1...%2) %0DynObject%1Object%2

#include "distance_diff"

/*
native GetObjectDistanceToDynObject(objectid, dynobj);
native IsObjectInRangeOfDynObject(objectid, dynobj, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestObjectToDynObject(dynobj, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Object%1
#define DISTANCE_B(%0...%1) %0DynObject%1
#define DISTANCE_AB(%0...%1...%2) %0Object%1DynObject%2

#include "distance_diff"

/*
native GetDynObjectDistanceToVehicle(dynobj, vehicleid);
native IsDynObjectInRangeOfVehicle(dynobj, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestDynObjectToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0DynObject%1
#define DISTANCE_B(%0...%1) %0Vehicle%1
#define DISTANCE_AB(%0...%1...%2) %0DynObject%1Vehicle%2

#include "distance_diff"

/*
native GetVehicleDistanceToDynObject(vehicleid, dynobj);
native IsVehicleInRangeOfDynObject(vehicleid, dynobj, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestVehicleToDynObject(dynobj, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Vehicle%1
#define DISTANCE_B(%0...%1) %0DynObject%1
#define DISTANCE_AB(%0...%1...%2) %0Vehicle%1DynObject%2

#include "distance_diff"

