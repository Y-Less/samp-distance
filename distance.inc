// Convenience macros to prepend `DISTANCE_` to everything.
#define _DISTANCE_A(%0...%1) DISTANCE_A(DISTANCE_%0..._%1)
#define _DISTANCE_B(%0...%1) DISTANCE_B(DISTANCE_%0..._%1)


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
#define GetPlayerDistanceFromPoint( GetPlayerDistanceFromPoint3D(

#define DISTANCE_A(%0...%1) %0Player%1
#include "distance_point.inc"


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
#define GetVehicleDistanceFromPoint( GetVehicleDistanceFromPoint3D(

#define DISTANCE_A(%0...%1) %0Vehicle%1
#include "distance_point.inc"


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


#define DISTANCE_Object_Distance GetObjectDistanceFromPoint3D
#define DISTANCE_Object_Pos GetObjectPos
#define DISTANCE_Object_Invalid() INVALID_OBJECT_ID
#define DISTANCE_Object_Loop(%0) for (new %0 = 0; %0 != INVALID_OBJECT_ID; ++%0) if (IsValidObject(%0))

#define DISTANCE_A(%0...%1) %0Object%1
#include "distance_point.inc"


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
#define DISTANCE_DynObject_Invalid() INVALID_STREAMER_ID
#define DISTANCE_DynObject_Loop(%0) for (new %0 = Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); %0; --%0) if (IsValidDynamicObject(%0))

#define DISTANCE_A(%0...%1) %0DynObject%1
#include "distance_point.inc"


/*

native GetPlayerDistanceFromVehicle(playerid, vehicleid);
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

#include "distance_diff.inc"


/*

native GetVehicleDistanceFromPlayer(vehicleid, playerid);
native IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);

*/


#define DISTANCE_A(%0...%1) %0Vehicle%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0Vehicle%1Player%2
#define DISTANCE_INT

#include "distance_diff.inc"


// Input:

#if 0
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
native Get\1DistanceFrom\2\(\3, \4\);
native Is\1InRangeOf\2\(\3, \4, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false\);
native GetClosest\1To\2\(\4, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false\);
*/

#define DISTANCE_A\(%0...%1\) %0\1%1
#define DISTANCE_B\(%0...%1\) %0\2%1
#define DISTANCE_AB\(%0...%1...%2\) %0\1%1\2%2
#define DISTANCE_INT

#include "distance_diff.inc"

#endif


/*
native GetVehicleDistanceFromPlayer(vehicleid, playerid);
native IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Vehicle%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0Vehicle%1Player%2
#define DISTANCE_INT

#include "distance_diff.inc"


/*
native GetPlayerDistanceFromObject(playerid, objectid);
native IsPlayerInRangeOfObject(playerid, objectid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestPlayerToObject(objectid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Player%1
#define DISTANCE_B(%0...%1) %0Object%1
#define DISTANCE_AB(%0...%1...%2) %0Player%1Object%2
#define DISTANCE_INT

#include "distance_diff.inc"


/*
native GetObjectDistanceFromVehicle(objectid, vehicleid);
native IsObjectInRangeOfVehicle(objectid, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestObjectToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0Object%1
#define DISTANCE_B(%0...%1) %0Vehicle%1
#define DISTANCE_AB(%0...%1...%2) %0Object%1Vehicle%2
#define DISTANCE_INT

#include "distance_diff.inc"


/*
native GetDynObjectDistanceFromPlayer(dynobj, playerid);
native IsDynObjectInRangeOfPlayer(dynobj, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestDynObjectToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0DynObject%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0DynObject%1Player%2
#define DISTANCE_INT

#include "distance_diff.inc"


/*
native GetDynObjectDistanceFromObject(dynobj, objectid);
native IsDynObjectInRangeOfObject(dynobj, objectid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestDynObjectToObject(objectid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0DynObject%1
#define DISTANCE_B(%0...%1) %0Object%1
#define DISTANCE_AB(%0...%1...%2) %0DynObject%1Object%2
#define DISTANCE_INT

#include "distance_diff.inc"


/*
native GetDynObjectDistanceFromVehicle(dynobj, vehicleid);
native IsDynObjectInRangeOfVehicle(dynobj, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestDynObjectToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
*/

#define DISTANCE_A(%0...%1) %0DynObject%1
#define DISTANCE_B(%0...%1) %0Vehicle%1
#define DISTANCE_AB(%0...%1...%2) %0DynObject%1Vehicle%2
#define DISTANCE_INT

#include "distance_diff.inc"
