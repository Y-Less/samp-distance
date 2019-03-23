# SA-MP Distance Functions

[![sampctl](https://shields.southcla.ws/badge/sampctl-samp--distance-2f2f2f.svg?style=for-the-badge)](https://github.com/kristoisberg/samp-distance)

This library offers a bunch of functions for getting the distance between various entities (2D/3D points, players, vehicles), performing proximity/distance checks between them and finding the closest entities to other entities. The idea for this library came after seeing a discussion on this topic on the forums and realising that there is no widely adopted library for performing these tasks and the homebrewed implementations often have major issues. Some of the issues this library addresses:

* **Incorrect return values** - If a distance check fails because an entity does not exist, the result of the check is `NaN`, not `0.0` as the standard library would return, `9999.9999`, `-1.0` or any other nonsense. As you might know, comparing `NaN` to any value, even itself, always returns `false`, making it easy to distinguish if the function failed and avoiding incorrect behaviour in code using those functions.
* **Inconsistent and non-descriptive function names** - A function name I saw in the topic mentioned above is `IsCoordNearCoord`, which has a similar behaviour to `IsPlayerInRangeOfPoint` from the standard library, but a completely different name structure. Some other examples are `GetClosestPlayer` and `GetClosestVehicle`, commonly used names for functions returning the closest player/vehicle to a player. The more you read the previous sentence, the more you will realise that the names are missing something...

Huge thanks to Y_Less for his contributions to this library and the productive conversations with him!


## Installation

Simply install to your project:

```bash
sampctl package install kristoisberg/samp-distance
```

Include in your code and begin using the library:

```pawn
#include <samp-distance>
```

## Changes to the standard library

This library hooks the `GetPlayerDistanceFromPoint` and `GetVehicleDistanceFromPoint` functions to return `NaN` instead of `0.0` when the functions fail (the player/vehicle does not exist). These changes should not affect any existing code since it should be checking for invalid players/vehicles before using these functions anyway.


## New functions

### Point-Point

```pawn
Float:GetDistanceBetweenPoints(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
bool:IsPointInRangeOfPoint(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:range);
Float:GetDistanceBetweenPoints2D(Float:x1, Float:y1, Float:x2, Float:y2);
bool:IsPointInRangeOfPoint2D(Float:x1, Float:y1, Float:x2, Float:y2, Float:range);
```


### Player-Point

```pawn
Float:GetPlayerDistanceFromPoint2D(playerid, Float:x, Float:y);
bool:IsPlayerInRangeOfPoint2D(playerid, Float:range, Float:x, Float:y);
```


### Vehicle-Point

```pawn
bool:IsVehicleInRangeOfPoint(vehicleid, Float:range, Float:x, Float:y, Float:z);
Float:GetVehicleDistanceFromPoint2D(vehicleid, Float:x, Float:y);
bool:IsVehicleInRangeOfPoint2D(vehicleid, Float:range, Float:x, Float:y);
```


### Player-Player

```pawn
Float:GetDistanceBetweenPlayers(playerid1, playerid2);
bool:IsPlayerInRangeOfPlayer(playerid1, playerid2, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);
GetClosestPlayerToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false);
```


### Player-Vehicle

```pawn
Float:GetPlayerDistanceFromVehicle(playerid, vehicleid);
bool:IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false); // *
GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false); // *
```


### Vehicle-Vehicle

```pawn
Float:GetDistanceBetweenVehicles(vehicleid1, vehicleid2);
bool:IsVehicleInRangeOfVehicle(vehicleid1, vehicleid2, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false); // *
GetClosestVehicleToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false); // *
```


### Vehicle-Player

```pawn
Float:GetVehicleDistanceFromPlayer(vehicleid, playerid);
bool:IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false); // *
GetClosestPlayerToVehicle(vehicleid, ignoredid = INVALID_PLAYER_ID, bool:ignoreVW = false, bool:ignoreInterior = false); // *
```


**Note:** The functions with an asterisk (*) next to them only support the `ignoreInterior` argument if the `GetVehicleInterior` function is available (added by YSF, some other library or by a new SA-MP version (yeah, right)). 


## Examples

```pawn
CMD:pay(playerid, params[]) {
    new playerid2, amount;

    if (sscanf(params, "ui", playerid2, amount)) {
        return SendClientMessage(playerid, COLOR_WHITE, "USAGE: /pay <Player name/ID> <Amount>");
    }

    if (!IsPlayerInRangeOfPlayer(playerid, playerid2, 5.0)) {
        // fails if the other player is not connected or not near enough to the player
        return SendClientMessage(playerid, COLOR_RED, "The specified player is not near you!");
    }

    GivePlayerMoney(playerid, -amount);
    GivePlayerMoney(playerid2, amount);
    return 1;
}
```

```pawn
CMD:fixtires(playerid) {
    new vehicleid = GetClosestVehicleToPlayer(playerid);

    if (!IsPlayerInRangeOfVehicle(playerid, vehicleid, 10.0)) {
        // fails if no vehicle was found in the same interior and virtual world as the player or the closest one is not near enough to the player
        return SendClientMessage(playerid, COLOR_RED, "You are not near any vehicle!");
    }

    new panels, doors, lights, tires;
    GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    SetVehicleDamageStatus(vehicleid, panels, doors, lights, 0);
    return 1;
}
```


## Testing

The library is not fully tested as of now because there is no fully working version of `ut_mock_player`/`y_mock` right now (I will be working on one soon). Right now, the tests only check whether the library compiles and the functions in the `Point-Point` section return the correct values. To test, simply run the package:

```bash
sampctl package run
```