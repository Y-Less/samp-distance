#define DISTANCE_Player_Distance BAD_GetPlayerDistanceFromPoint
#define DISTANCE_Player_Interior GetPlayerInterior
#define DISTANCE_Player_VW GetPlayerVirtualWorld
#define DISTANCE_Player_Valid IsPlayerConnected
#define DISTANCE_Player_Pos GetPlayerPos
#define DISTANCE_Player_Invalid() INVALID_PLAYER_ID

#define DISTANCE_Vehicle_Distance BAD_GetVehicleDistanceFromPoint
#define DISTANCE_Vehicle_Interior GetVehicleInterior
#define DISTANCE_Vehicle_VW GetVehicleVirtualWorld
#define DISTANCE_Vehicle_Valid(%0) Iter_Contains(Vehicle, (%0))
#define DISTANCE_Vehicle_Pos GetVehiclePos
#define DISTANCE_Vehicle_Invalid() INVALID_VEHICLE_ID

#define DISTANCE_Object_Distance GetObjectDistanceFromPoint
#define DISTANCE_Object_Interior GetVehicleInterior
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
#define DISTANCE_INT
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

