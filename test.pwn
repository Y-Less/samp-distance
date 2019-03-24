#define RUN_TESTS
//#include <ut_mock_players>

#include <YSI_Core\y_testing>

#include "distance.inc"


#define EPSILON 0.001


Test:DoesItEvenCompile1() {
	GetDistanceBetweenPoints3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	IsPointInRangeOfPoint3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	GetDistanceBetweenPoints2D(0.0, 0.0, 0.0, 0.0);
	IsPointInRangeOfPoint2D(0.0, 0.0, 0.0, 0.0, 0.0);
}


Test:DoesItEvenCompile2() {
	GetPlayerDistanceToPoint3D(0, 0.0, 0.0, 0.0);
	IsPlayerInRangeOfPoint3D(0, 0.0, 0.0, 0.0, 0.0);
	GetPlayerDistanceToPoint2D(0, 0.0, 0.0);
	IsPlayerInRangeOfPoint2D(0, 0.0, 0.0, 0.0);

	GetVehicleDistanceToPoint3D(0, 0.0, 0.0, 0.0);
	IsVehicleInRangeOfPoint3D(0, 0.0, 0.0, 0.0, 0.0);
	GetVehicleDistanceToPoint2D(0, 0.0, 0.0);
	IsVehicleInRangeOfPoint2D(0, 0.0, 0.0, 0.0);

	GetDynObjectDistanceToPoint3D(0, 0.0, 0.0, 0.0);
	IsDynObjectInRangeOfPoint3D(0, 0.0, 0.0, 0.0, 0.0);
	GetDynObjectDistanceToPoint2D(0, 0.0, 0.0);
	IsDynObjectInRangeOfPoint2D(0, 0.0, 0.0, 0.0);

	GetObjectDistanceToPoint3D(0, 0.0, 0.0, 0.0);
	IsObjectInRangeOfPoint3D(0, 0.0, 0.0, 0.0, 0.0);
	GetObjectDistanceToPoint2D(0, 0.0, 0.0);
	IsObjectInRangeOfPoint2D(0, 0.0, 0.0, 0.0);
}


Test:DoesItEvenCompile3() {
	GetPlayerDistanceToPlayer(0, 0);
	IsPlayerInRangeOfPlayer(0, 0, 0.0);
	GetClosestPlayerToPlayer(0);

	GetVehicleDistanceToVehicle(0, 0);
	IsVehicleInRangeOfVehicle(0, 0, 0.0);
	GetClosestVehicleToVehicle(0);

	GetObjectDistanceToObject(0, 0);
	IsObjectInRangeOfObject(0, 0, 0.0);
	GetClosestObjectToObject(0);

	GetDynObjectDistanceToDynObject(0, 0);
	IsDynObjectInRangeOfDynObject(0, 0, 0.0);
	GetClosestDynObjectToDynObject(0);
}


Test:DoesItEvenCompile4() {
	GetPlayerDistanceToVehicle(0, 0);
	IsPlayerInRangeOfVehicle(0, 0, 0.0);
	GetClosestVehicleToPlayer(0);

	GetVehicleDistanceToPlayer(0, 0);
	IsVehicleInRangeOfPlayer(0, 0, 0.0);
	GetClosestPlayerToVehicle(0);

	GetObjectDistanceToVehicle(0, 0);
	IsObjectInRangeOfVehicle(0, 0, 0.0);
	GetClosestVehicleToObject(0);

	GetVehicleDistanceToObject(0, 0);
	IsVehicleInRangeOfObject(0, 0, 0.0);
	GetClosestObjectToVehicle(0);

	GetDynObjectDistanceToVehicle(0, 0);
	IsDynObjectInRangeOfVehicle(0, 0, 0.0);
	GetClosestVehicleToDynObject(0);

	GetVehicleDistanceToDynObject(0, 0);
	IsVehicleInRangeOfDynObject(0, 0, 0.0);
	GetClosestDynObjectToVehicle(0);

	GetPlayerDistanceToDynObject(0, 0);
	IsPlayerInRangeOfDynObject(0, 0, 0.0);
	GetClosestDynObjectToPlayer(0);

	GetDynObjectDistanceToPlayer(0, 0);
	IsDynObjectInRangeOfPlayer(0, 0, 0.0);
	GetClosestPlayerToDynObject(0);

	GetObjectDistanceToPlayer(0, 0);
	IsObjectInRangeOfPlayer(0, 0, 0.0);
	GetClosestPlayerToObject(0);

	GetPlayerDistanceToObject(0, 0);
	IsPlayerInRangeOfObject(0, 0, 0.0);
	GetClosestObjectToPlayer(0);

	GetDynObjectDistanceToObject(0, 0);
	IsDynObjectInRangeOfObject(0, 0, 0.0);
	GetClosestObjectToDynObject(0);

	GetObjectDistanceToDynObject(0, 0);
	IsObjectInRangeOfDynObject(0, 0, 0.0);
	GetClosestDynObjectToObject(0);
}


Test:PointPoint() {
	ASSERT(-EPSILON <= GetDistanceBetweenPoints3D(0.0, 0.0, 0.0, 3.0, 4.0, 5.0) - 7.071 <= EPSILON);
	ASSERT(-EPSILON <= GetDistanceBetweenPoints3D(0.0, 0.0, 0.0, 5.0, 12.0, 13.0) - 18.385 <= EPSILON);
	ASSERT(-EPSILON <= GetDistanceBetweenPoints3D(3.0, 4.0, 5.0, 5.0, 12.0, 13.0) - 11.489 <= EPSILON);

	ASSERT(IsPointInRangeOfPoint3D(0.0, 0.0, 0.0, 3.0, 4.0, 5.0, 10.0));
	ASSERT(!IsPointInRangeOfPoint3D(0.0, 0.0, 0.0, 5.0, 12.0, 13.0, 10.0));
	ASSERT(!IsPointInRangeOfPoint3D(3.0, 4.0, 5.0, 5.0, 12.0, 13.0, 10.0));

	ASSERT(-EPSILON <= GetDistanceBetweenPoints2D(0.0, 0.0, 3.0, 4.0) - 5.0 <= EPSILON);
	ASSERT(-EPSILON <= GetDistanceBetweenPoints2D(0.0, 0.0, 5.0, 12.0) - 13.0 <= EPSILON);
	ASSERT(-EPSILON <= GetDistanceBetweenPoints2D(2.0, 4.0, 5.0, 12.0) - 8.544 <= EPSILON);

	ASSERT(IsPointInRangeOfPoint2D(0.0, 0.0, 3.0, 4.0, 10.0));
	ASSERT(!IsPointInRangeOfPoint2D(0.0, 0.0, 5.0, 12.0, 10.0));
	ASSERT(IsPointInRangeOfPoint2D(3.0, 4.0, 5.0, 12.0, 10.0));
}


/*Test:PlayerPlayer() {
	SetPlayerConnected(3, false);

	SetPlayerPos(0, 0.0, 0.0, 0.0);
	SetPlayerPos(1, 3.0, 4.0, 5.0);
	SetPlayerPos(2, 5.0, 12.0, 13.0);

	ASSERT(-EPSILON <= GetDistanceBetweenPlayers(0, 1) - 7.071 <= EPSILON);
	ASSERT(-EPSILON <= GetDistanceBetweenPlayers(0, 2) - 18.385 <= EPSILON);
	ASSERT(GetDistanceBetweenPlayers(0, 3) == FLOAT_INFINITY);

	ASSERT(IsPlayerInRangeOfPlayer(0, 1, 10.0));
	ASSERT(!IsPlayerInRangeOfPlayer(0, 2, 10.0));
	ASSERT(!IsPlayerInRangeOfPlayer(0, 3, 10.0));
}*/

