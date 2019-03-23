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
#define DISTANCE_Player_Valid IsPlayerConnected
#define DISTANCE_Player_Pos GetPlayerPos
#define DISTANCE_Player_Invalid() INVALID_PLAYER_ID

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
#define DISTANCE_Vehicle_Valid(%0) Iter_Contains(Vehicle, (%0))
#define DISTANCE_Vehicle_Pos GetVehiclePos
#define DISTANCE_Vehicle_Invalid() INVALID_VEHICLE_ID

#if defined _ALS_GetVehicleDistFromPoint
    #undef GetVehicleDistanceFromPoint
#else
    #define _ALS_GetVehicleDistFromPoint
    native BAD_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
#endif
#define GetVehicleDistanceFromPoint( GetVehicleDistanceFromPoint3D(

#define DISTANCE_A(%0...%1) %0Vehicle%1
#include "distance_point.inc"

#define DISTANCE_Object_Distance GetObjectDistanceFromPoint
#define DISTANCE_Object_Interior GetObjectInterior
#define DISTANCE_Object_VW GetVehicleVirtualWorld
#define DISTANCE_Object_Valid(%0) Iter_Contains(Vehicle, (%0))
#define DISTANCE_Object_Pos GetVehiclePos

stock GetObjectDistanceFromPoint(objectid, Float:x1, Float:y1, Float:z2)
{
	new Float:x2, Float:y2, Float:z2;

	if (GetObjectPos(objectid, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}


//
//#define DISTANCE_Vehicle_Distance BAD_GetVehicleDistanceFromPoint
//#define DISTANCE_Vehicle_Interior GetVehicleInterior
//#define DISTANCE_Vehicle_VW GetVehicleVirtualWorld
//#define DISTANCE_Vehicle_Valid(%0) Iter_Contains(Vehicle, (%0))
//#define DISTANCE_Vehicle_Pos GetVehiclePos
//
//#define DISTANCE_Vehicle_Distance BAD_GetVehicleDistanceFromPoint
//#define DISTANCE_Vehicle_Interior GetVehicleInterior
//#define DISTANCE_Vehicle_VW GetVehicleVirtualWorld
//#define DISTANCE_Vehicle_Valid(%0) Iter_Contains(Vehicle, (%0))
//#define DISTANCE_Vehicle_Pos GetVehiclePos







/*

native GetPlayerDistanceFromVehicle(playerid, vehicleid);
native IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestPlayerToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0Player%1
#define DISTANCE_B(%0...%1) %0Vehicle%1
#define DISTANCE_AB(%0...%1...%2) %0Player%1Vehicle%2
#if defined GetVehicleInterior && defined GetPlayerInterior
	#define DISTANCE_INT
#endif
#define DISTANCE_VW
#define DISTANCE_LOOP(%0) foreach (new %0 : Player)

#include "distance_diff.inc"


/*

native GetVehicleDistanceFromPlayer(vehicleid, playerid);
native IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0Vehicle%1
#define DISTANCE_B(%0...%1) %0Player%1
#define DISTANCE_AB(%0...%1...%2) %0Vehicle%1Player%2
#define DISTANCE_INT
#define DISTANCE_LOOP(%0) foreach (new %0 : Vehicle)

#include "distance_diff.inc"




Vehicle,Player,vehicleid,playerid
Player,Object,playerid,objectid
Object,Vehicle,objectid,vehicleid









/*

native GetAAADistanceFromBBB(aaa, bbb);
native IsAAAInRangeOfBBB(aaa, bbb, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestAAAToBBB(bbb, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0AAA%1
#define DISTANCE_B(%0...%1) %0BBB%1
#define DISTANCE_AB(%0...%1...%2) %0AAA%1BBB%2
#define DISTANCE_INT
#define DISTANCE_LOOP(%0) foreach (new %0 : AAA)

#include "distance_diff.inc"


/*

native GetAAADistanceFromBBB(aaa, bbb);
native IsAAAInRangeOfBBB(aaa, bbb, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestAAAToBBB(bbb, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0AAA%1
#define DISTANCE_B(%0...%1) %0BBB%1
#define DISTANCE_AB(%0...%1...%2) %0AAA%1BBB%2
#define DISTANCE_INT
#define DISTANCE_LOOP(%0) foreach (new %0 : AAA)

#include "distance_diff.inc"


/*

native GetAAADistanceFromBBB(aaa, bbb);
native IsAAAInRangeOfBBB(aaa, bbb, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestAAAToBBB(bbb, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0AAA%1
#define DISTANCE_B(%0...%1) %0BBB%1
#define DISTANCE_AB(%0...%1...%2) %0AAA%1BBB%2
#define DISTANCE_INT
#define DISTANCE_LOOP(%0) foreach (new %0 : AAA)

#include "distance_diff.inc"


/*

native GetAAADistanceFromBBB(aaa, bbb);
native IsAAAInRangeOfBBB(aaa, bbb, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestAAAToBBB(bbb, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0AAA%1
#define DISTANCE_B(%0...%1) %0BBB%1
#define DISTANCE_AB(%0...%1...%2) %0AAA%1BBB%2
#define DISTANCE_INT
#define DISTANCE_LOOP(%0) foreach (new %0 : AAA)

#include "distance_diff.inc"


/*

native GetAAADistanceFromBBB(aaa, bbb);
native IsAAAInRangeOfBBB(aaa, bbb, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestAAAToBBB(bbb, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0AAA%1
#define DISTANCE_B(%0...%1) %0BBB%1
#define DISTANCE_AB(%0...%1...%2) %0AAA%1BBB%2
#define DISTANCE_INT
#define DISTANCE_LOOP(%0) foreach (new %0 : AAA)

#include "distance_diff.inc"


/*

native GetAAADistanceFromBBB(aaa, bbb);
native IsAAAInRangeOfBBB(aaa, bbb, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
native GetClosestAAAToBBB(bbb, ignoredid = INVALID_VEHICLE_ID, aool:ignoreVW = false, aool:ignoreInterior = false);

*/

#define DISTANCE_A(%0...%1) %0AAA%1
#define DISTANCE_B(%0...%1) %0BBB%1
#define DISTANCE_AB(%0...%1...%2) %0AAA%1BBB%2
#define DISTANCE_INT
#define DISTANCE_LOOP(%0) foreach (new %0 : AAA)

#include "distance_diff.inc"

