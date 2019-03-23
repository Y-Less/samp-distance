#define RUN_TESTS
//#include <ut_mock_players>

#include <YSI_Core\y_testing>

#include "distance.inc"


#define EPSILON 0.001


Test:DoesItEvenCompile() {
    GetDistanceBetweenPoints(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    IsPointInRangeOfPoint(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    GetDistanceBetweenPoints2D(0.0, 0.0, 0.0, 0.0);
    IsPointInRangeOfPoint2D(0.0, 0.0, 0.0, 0.0, 0.0);

    GetPlayerDistanceFromPoint(0, 0.0, 0.0, 0.0);
    IsPlayerInRangeOfPoint(0, 0.0, 0.0, 0.0, 0.0);
    GetPlayerDistanceFromPoint2D(0, 0.0, 0.0);
    IsPlayerInRangeOfPoint2D(0, 0.0, 0.0, 0.0);

    GetVehicleDistanceFromPoint(0, 0.0, 0.0, 0.0);
    IsVehicleInRangeOfPoint(0, 0.0, 0.0, 0.0, 0.0);
    GetVehicleDistanceFromPoint2D(0, 0.0, 0.0);
    IsVehicleInRangeOfPoint2D(0, 0.0, 0.0, 0.0);

    GetDistanceBetweenPlayers(0, 0);
    IsPlayerInRangeOfPlayer(0, 0, 0.0);
    GetClosestPlayerToPlayer(0);

    GetPlayerDistanceFromVehicle(0, 0);
    IsPlayerInRangeOfVehicle(0, 0, 0.0);
    GetClosestVehicleToPlayer(0);

    GetDistanceBetweenVehicles(0, 0);
    IsVehicleInRangeOfVehicle(0, 0, 0.0);
    GetClosestVehicleToVehicle(0);

    GetVehicleDistanceFromPlayer(0, 0);
    IsVehicleInRangeOfPlayer(0, 0, 0.0);
    GetClosestPlayerToVehicle(0);
}


Test:PointPoint() {
    ASSERT(-EPSILON <= GetDistanceBetweenPoints(0.0, 0.0, 0.0, 3.0, 4.0, 5.0) - 7.071 <= EPSILON);
    ASSERT(-EPSILON <= GetDistanceBetweenPoints(0.0, 0.0, 0.0, 5.0, 12.0, 13.0) - 18.385 <= EPSILON);
    ASSERT(-EPSILON <= GetDistanceBetweenPoints(3.0, 4.0, 5.0, 5.0, 12.0, 13.0) - 11.489 <= EPSILON);

    ASSERT(IsPointInRangeOfPoint(0.0, 0.0, 0.0, 3.0, 4.0, 5.0, 10.0));
    ASSERT(!IsPointInRangeOfPoint(0.0, 0.0, 0.0, 5.0, 12.0, 13.0, 10.0));
    ASSERT(!IsPointInRangeOfPoint(3.0, 4.0, 5.0, 5.0, 12.0, 13.0, 10.0));

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