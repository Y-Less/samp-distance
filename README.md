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


## Function Naming

The functions in this library have several basic forms:

* `Get<A>DistanceTo<B>` - Get the distance between `A` and `B`.
* `Is<A>InRangeOf<B>` - Is the distance between `A` and `B` lower than some threshold?
* `GetClosest<A>To<B>` - Get the closest `B` to `A`.

Plus a few "Point" functions which take an `x/y` pair or `x/y/z` triple instead of another entity:

* `Get<A>DistanceToPoint2D` - Get the distance between `A` and an `x/y` point.
* `Is<A>InRangeOfPoint2D` - Is the distance between `A` and an `x/y` point lower than some threshold?
* `Get<A>DistanceToPoint3D` - Get the distance between `A` and an `x/y/z` point.
* `Is<A>InRangeOfPoint3D` - Is the distance between `A` and an `x/y/z` point lower than some threshold?

For each of these functions `A` and `B` can be any of the following entity types:

* `Player`
* `Vehicle`
* `Object`
* `DynObject` (with the streamer plugin).

So for example, to check if a vehicle (`A`) is near a given streamer object (`B`) use:

```pawn
if (IsVehicleInRangeOfDynObject(vehicleid, objectid, 50.0))
{
	// Yes.
}
```

There are also two generic point functions:

```pawn
stock Float:GetPointDistanceToPoint(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN);
stock bool:IsPointInRangeOfPoint(Float:range, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN);
```

These can be invoked as 2D (with four/five parameters) or 3D (with six/seven parameters).

## All Functions

Functions that return `Float:` will return `FLOAT_NAN` if they fail.  If, for example, one of the input entities doesn't exist.

### Point - Point

```pawn
Float:GetPointDistanceToPoint(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN);

bool:IsPointInRangeOfPoint(Float:range, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2 = FLOAT_NAN, Float:z2 = FLOAT_NAN);
```

### Player - Point

```pawn
Float:GetPlayerDistanceToPoint2D(playerid, Float:x, Float:y);

bool:IsPlayerInRangeOfPoint2D(playerid, Float:range, Float:x, Float:y);

Float:GetPlayerDistanceToPoint3D(playerid, Float:x, Float:y, Float:z);

bool:IsPlayerInRangeOfPoint3D(playerid, Float:range, Float:x, Float:y, Float:z);
```

### Player - Player

```pawn
Float:GetPlayerDistanceToPlayer(playerid, targetid);

bool:IsPlayerInRangeOfPlayer(playerid, targetid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false);

GetClosestPlayerToPlayer(playerid, bool:ignoreVW = false, bool:ignoreInterior = false);
```

### Vehicle - Point

```pawn
Float:GetVehicleDistanceToPoint2D(vehicleid, Float:x, Float:y);

bool:IsVehicleInRangeOfPoint2D(vehicleid, Float:range, Float:x, Float:y);

Float:GetVehicleDistanceToPoint3D(vehicleid, Float:x, Float:y, Float:z);

bool:IsVehicleInRangeOfPoint3D(vehicleid, Float:range, Float:x, Float:y, Float:z);
```

### Vehicle - Vehicle

```pawn
Float:GetVehicleDistanceToVehicle(vehicleid, targetid);

bool:IsVehicleInRangeOfVehicle(vehicleid, targetid, Float:range, bool:ignoreVW = false);

GetClosestVehicleToVehicle(vehicleid, bool:ignoreVW = false);
```

### Object - Point

```pawn
Float:GetObjectDistanceToPoint2D(objectid, Float:x, Float:y);

bool:IsObjectInRangeOfPoint2D(objectid, Float:range, Float:x, Float:y);

Float:GetObjectDistanceToPoint3D(objectid, Float:x, Float:y, Float:z);

bool:IsObjectInRangeOfPoint3D(objectid, Float:range, Float:x, Float:y, Float:z);
```

### Object - Object

```pawn
Float:GetObjectDistanceToObject(objectid, targetid);

bool:IsObjectInRangeOfObject(objectid, targetid, Float:range);

GetClosestObjectToObject(objectid);
```

### DynObject - Point

```pawn
Float:GetDynObjectDistanceToPoint2D(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y);

bool:IsDynObjectInRangeOfPoint2D(STREAMER_TAG_OBJECT:objectid, Float:range, Float:x, Float:y);

Float:GetDynObjectDistanceToPoint3D(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y, Float:z);

bool:IsDynObjectInRangeOfPoint3D(STREAMER_TAG_OBJECT:objectid, Float:range, Float:x, Float:y, Float:z);
```

### DynObject - DynObject

```pawn
Float:GetDynObjectDistanceToDynObject(STREAMER_TAG_OBJECT:objectid, STREAMER_TAG_OBJECT:targetid);

bool:IsDynObjectInRangeOfDynObject(STREAMER_TAG_OBJECT:objectid, STREAMER_TAG_OBJECT:targetid, Float:range);

STREAMER_TAG_OBJECT:GetClosestDynObjectToDynObject(STREAMER_TAG_OBJECT:objectid);
```

### Player - Vehicle

```pawn
Float:GetVehicleDistanceToPlayer(vehicleid, playerid);

bool:IsVehicleInRangeOfPlayer(vehicleid, playerid, Float:range, bool:ignoreVW = false);

GetClosestVehicleToPlayer(playerid, bool:ignoreVW = false);

Float:GetPlayerDistanceToVehicle(playerid, vehicleid);

bool:IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false);

GetClosestPlayerToVehicle(vehicleid, bool:ignoreVW = false);
```

### Player - Object

```pawn
Float:GetPlayerDistanceToObject(playerid, objectid);

bool:IsPlayerInRangeOfObject(playerid, objectid, Float:range);

GetClosestPlayerToObject(objectid);

Float:GetObjectDistanceToPlayer(objectid, playerid);

bool:IsObjectInRangeOfPlayer(objectid, playerid, Float:range);

GetClosestObjectToPlayer(playerid);
```

### Object - Vehicle

```pawn
Float:GetObjectDistanceToVehicle(objectid, vehicleid);

bool:IsObjectInRangeOfVehicle(objectid, vehicleid, Float:range);

GetClosestObjectToVehicle(vehicleid);

Float:GetVehicleDistanceToObject(vehicleid, objectid);

bool:IsVehicleInRangeOfObject(vehicleid, objectid, Float:range);

GetClosestVehicleToObject(objectid);
```

### DynObject - Player

```pawn
Float:GetDynObjectDistanceToPlayer(STREAMER_TAG_OBJECT:objectid, playerid);

bool:IsDynObjectInRangeOfPlayer(STREAMER_TAG_OBJECT:objectid, playerid, Float:range);

STREAMER_TAG_OBJECT:GetClosestDynObjectToPlayer(playerid);

Float:GetPlayerDistanceToDynObject(playerid, STREAMER_TAG_OBJECT:objectid);

bool:IsPlayerInRangeOfDynObject(playerid, STREAMER_TAG_OBJECT:objectid, Float:range);

GetClosestPlayerToDynObject(STREAMER_TAG_OBJECT:objectid);
```

### DynObject - Object

```pawn
Float:GetDynObjectDistanceToObject(STREAMER_TAG_OBJECT:objectid, targetid);

bool:IsDynObjectInRangeOfObject(STREAMER_TAG_OBJECT:objectid, targetid, Float:range);

STREAMER_TAG_OBJECT:GetClosestDynObjectToObject(objectid);

Float:GetObjectDistanceToDynObject(objectid, STREAMER_TAG_OBJECT:targetid);

bool:IsObjectInRangeOfDynObject(objectid, STREAMER_TAG_OBJECT:targetid, Float:range);

GetClosestObjectToDynObject(STREAMER_TAG_OBJECT:objectid);
```

### DynObject - Vehicle

```pawn
Float:GetDynObjectDistanceToVehicle(STREAMER_TAG_OBJECT:objectid, vehicleid);

bool:IsDynObjectInRangeOfVehicle(STREAMER_TAG_OBJECT:objectid, vehicleid, Float:range);

STREAMER_TAG_OBJECT:GetClosestDynObjectToVehicle(vehicleid);

Float:GetVehicleDistanceToDynObject(vehicleid, STREAMER_TAG_OBJECT:objectid);

bool:IsVehicleInRangeOfDynObject(vehicleid, STREAMER_TAG_OBJECT:objectid, Float:range);

GetClosestVehicleToDynObject(STREAMER_TAG_OBJECT:objectid);
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

