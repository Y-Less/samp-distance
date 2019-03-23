#if defined _inc_distance
    #undef _inc_distance
#endif

#if defined _distance_included
    #endinput
#endif
#define _distance_included

#include <a_samp>
#include <YSI_Data\y_iterate>


#if !defined IsValidVehicle
    native IsValidVehicle(vehicleid);
#endif


/*
ooooooooo.              o8o                  .           ooooooooo.              o8o                  .   
`888   `Y88.            `"'                .o8           `888   `Y88.            `"'                .o8   
 888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo          888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo 
 888ooo88P'  d88' `88b `888  `888P"Y88b    888            888ooo88P'  d88' `88b `888  `888P"Y88b    888   
 888         888   888  888   888   888    888   8888888  888         888   888  888   888   888    888   
 888         888   888  888   888   888    888 .          888         888   888  888   888   888    888 . 
o888o        `Y8bod8P' o888o o888o o888o   "888"         o888o        `Y8bod8P' o888o o888o o888o   "888"
*/

stock Float:GetDistanceBetweenPoints(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2) {
    return VectorSize(x1 - x2, y1 - y2, z1 - z2);
}


stock bool:IsPointInRangeOfPoint(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:range) {
    return GetDistanceBetweenPoints(x1, y1, z1, x2, y2, z2) <= range;
}


stock Float:GetDistanceBetweenPoints2D(Float:x1, Float:y1, Float:x2, Float:y2) {
    return VectorSize(x1 - x2, y1 - y2, 0.0);
}


stock bool:IsPointInRangeOfPoint2D(Float:x1, Float:y1, Float:x2, Float:y2, Float:range) {
    return GetDistanceBetweenPoints2D(x1, y1, x2, y2) <= range;
}


/*
ooooooooo.   oooo                                                   ooooooooo.              o8o                  .   
`888   `Y88. `888                                                   `888   `Y88.            `"'                .o8   
 888   .d88'  888   .oooo.   oooo    ooo  .ooooo.  oooo d8b          888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo 
 888ooo88P'   888  `P  )88b   `88.  .8'  d88' `88b `888""8P          888ooo88P'  d88' `88b `888  `888P"Y88b    888   
 888          888   .oP"888    `88..8'   888ooo888  888     8888888  888         888   888  888   888   888    888   
 888          888  d8(  888     `888'    888    .o  888              888         888   888  888   888   888    888 . 
o888o        o888o `Y888""8o     .8'     `Y8bod8P' d888b            o888o        `Y8bod8P' o888o o888o o888o   "888" 
                             .o..P'                                                                                  
                             `Y8P'                                                                                   
*/

stock Float:dist_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) {
    if (!IsPlayerConnected(playerid)) {
        return FLOAT_INFINITY;
    }

    return GetPlayerDistanceFromPoint(playerid, x, y, z);
}

#if defined _ALS_GetPlayerDistanceFromPoint
    #undef GetPlayerDistanceFromPoint
#else
    #define _ALS_GetPlayerDistanceFromPoint
#endif
#define GetPlayerDistanceFromPoint dist_GetPlayerDistanceFromPoint


stock Float:GetPlayerDistanceFromPoint2D(playerid, Float:x, Float:y) {
    new Float:x2, Float:y2, Float:z2;

    if (!GetPlayerPos(playerid, x2, y2, z2)) {
        return FLOAT_INFINITY;
    }

	return GetDistanceBetweenPoints2D(x, y, x2, y2);
}


stock bool:IsPlayerInRangeOfPoint2D(playerid, Float:range, Float:x, Float:y) {
    return GetPlayerDistanceFromPoint2D(playerid, x, y) <= range;
}


/*
oooooo     oooo           oooo         o8o            oooo                    ooooooooo.              o8o                  .   
 `888.     .8'            `888         `"'            `888                    `888   `Y88.            `"'                .o8   
  `888.   .8'    .ooooo.   888 .oo.   oooo   .ooooo.   888   .ooooo.           888   .d88'  .ooooo.  oooo  ooo. .oo.   .o888oo 
   `888. .8'    d88' `88b  888P"Y88b  `888  d88' `"Y8  888  d88' `88b          888ooo88P'  d88' `88b `888  `888P"Y88b    888   
    `888.8'     888ooo888  888   888   888  888        888  888ooo888 8888888  888         888   888  888   888   888    888   
     `888'      888    .o  888   888   888  888   .o8  888  888    .o          888         888   888  888   888   888    888 . 
      `8'       `Y8bod8P' o888o o888o o888o `Y8bod8P' o888o `Y8bod8P'         o888o        `Y8bod8P' o888o o888o o888o   "888" 
*/

stock Float:dist_GetVehicleDistFromPoint(vehicleid, Float:x, Float:y, Float:z) {
    if (!IsValidVehicle(vehicleid)) {
        return FLOAT_INFINITY;
    }

    return GetVehicleDistanceFromPoint(vehicleid, x, y, z);
}

#if defined _ALS_GetVehicleDistFromPoint
    #undef GetVehicleDistanceFromPoint
#else
    #define _ALS_GetVehicleDistFromPoint
#endif
#define GetVehicleDistanceFromPoint dist_GetVehicleDistFromPoint


stock bool:IsVehicleInRangeOfPoint(vehicleid, Float:range, Float:x, Float:y, Float:z) {
    return GetVehicleDistanceFromPoint(vehicleid, x, y, z) <= range;
}


stock Float:GetVehicleDistanceFromPoint2D(vehicleid, Float:x, Float:y) {
    new Float:x2, Float:y2, Float:z2;

    if (!GetVehiclePos(vehicleid, x2, y2, z2)) {
        return FLOAT_INFINITY;
    }

	return GetDistanceBetweenPoints2D(x, y, x2, y2);
}


stock bool:IsVehicleInRangeOfPoint2D(vehicleid, Float:range, Float:x, Float:y) {
    return GetVehicleDistanceFromPoint2D(vehicleid, x, y) <= range;
}


/*
ooooooooo.   oooo                                                   ooooooooo.   oooo                                           
`888   `Y88. `888                                                   `888   `Y88. `888                                           
 888   .d88'  888   .oooo.   oooo    ooo  .ooooo.  oooo d8b          888   .d88'  888   .oooo.   oooo    ooo  .ooooo.  oooo d8b 
 888ooo88P'   888  `P  )88b   `88.  .8'  d88' `88b `888""8P          888ooo88P'   888  `P  )88b   `88.  .8'  d88' `88b `888""8P 
 888          888   .oP"888    `88..8'   888ooo888  888     8888888  888          888   .oP"888    `88..8'   888ooo888  888     
 888          888  d8(  888     `888'    888    .o  888              888          888  d8(  888     `888'    888    .o  888     
o888o        o888o `Y888""8o     .8'     `Y8bod8P' d888b            o888o        o888o `Y888""8o     .8'     `Y8bod8P' d888b    
                             .o..P'                                                              .o..P'                         
                             `Y8P'                                                               `Y8P'                          
*/

stock Float:GetDistanceBetweenPlayers(playerid1, playerid2) {
    if (!IsPlayerConnected(playerid1) || !IsPlayerConnected(playerid2)) {
		return FLOAT_INFINITY;
	}

	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid2, x, y, z);

	return GetPlayerDistanceFromPoint(playerid1, x, y, z);
}


stock bool:IsPlayerInRangeOfPlayer(playerid1, playerid2, Float:range) {
    return GetDistanceBetweenPlayers(playerid1, playerid2) <= range && GetPlayerVirtualWorld(playerid1) == GetPlayerVirtualWorld(playerid2);
}


stock GetClosestPlayerToPlayer(playerid, ignoredid = INVALID_PLAYER_ID) {
    new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2, vw = GetPlayerVirtualWorld(playerid);

    foreach (new i : Player) {
        if (playerid == i || i == ignoredid || vw != GetPlayerVirtualWorld(i)) {
            continue;
        }

        if ((distance2 = GetDistanceBetweenPlayers(playerid, i)) < distance) {
            distance = distance2;
            closestid = i;
        }
    }

    return closestid;
}


/*
ooooooooo.   oooo                                                   oooooo     oooo           oooo         o8o            oooo            
`888   `Y88. `888                                                    `888.     .8'            `888         `"'            `888            
 888   .d88'  888   .oooo.   oooo    ooo  .ooooo.  oooo d8b           `888.   .8'    .ooooo.   888 .oo.   oooo   .ooooo.   888   .ooooo.  
 888ooo88P'   888  `P  )88b   `88.  .8'  d88' `88b `888""8P            `888. .8'    d88' `88b  888P"Y88b  `888  d88' `"Y8  888  d88' `88b 
 888          888   .oP"888    `88..8'   888ooo888  888     8888888     `888.8'     888ooo888  888   888   888  888        888  888ooo888 
 888          888  d8(  888     `888'    888    .o  888                  `888'      888    .o  888   888   888  888   .o8  888  888    .o 
o888o        o888o `Y888""8o     .8'     `Y8bod8P' d888b                  `8'       `Y8bod8P' o888o o888o o888o `Y8bod8P' o888o `Y8bod8P' 
                             .o..P'                                                                                                       
                             `Y8P'                                                                                                        
*/

stock Float:GetPlayerDistanceFromVehicle(playerid, vehicleid) {
    if (!IsPlayerConnected(playerid) || !IsValidVehicle(vehicleid)) {
        return FLOAT_INFINITY;
    }

    new Float:x, Float:y, Float:z;
	GetVehiclePos(vehicleid, x, y, z);

	return GetPlayerDistanceFromPoint(playerid, x, y, z);
}


stock bool:IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range) {
    return GetPlayerDistanceFromVehicle(playerid, vehicleid) <= range && GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(vehicleid);
}


stock GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID) {
    new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2, vw = GetPlayerVirtualWorld(playerid);

    foreach (new i : Vehicle) {
		if (i == ignoredid || vw != GetVehicleVirtualWorld(i)) {
            continue;
        }

        if ((distance2 = GetPlayerDistanceFromVehicle(playerid, i)) < distance) {
            distance = distance2;
            closestid = i;
        }
    }

    return closestid;
}


/*
oooooo     oooo           oooo         o8o            oooo                    oooooo     oooo           oooo         o8o            oooo            
 `888.     .8'            `888         `"'            `888                     `888.     .8'            `888         `"'            `888            
  `888.   .8'    .ooooo.   888 .oo.   oooo   .ooooo.   888   .ooooo.            `888.   .8'    .ooooo.   888 .oo.   oooo   .ooooo.   888   .ooooo.  
   `888. .8'    d88' `88b  888P"Y88b  `888  d88' `"Y8  888  d88' `88b            `888. .8'    d88' `88b  888P"Y88b  `888  d88' `"Y8  888  d88' `88b 
    `888.8'     888ooo888  888   888   888  888        888  888ooo888 8888888     `888.8'     888ooo888  888   888   888  888        888  888ooo888 
     `888'      888    .o  888   888   888  888   .o8  888  888    .o              `888'      888    .o  888   888   888  888   .o8  888  888    .o 
      `8'       `Y8bod8P' o888o o888o o888o `Y8bod8P' o888o `Y8bod8P'               `8'       `Y8bod8P' o888o o888o o888o `Y8bod8P' o888o `Y8bod8P' 
*/

stock Float:GetDistanceBetweenVehicles(vehicleid1, vehicleid2) {
    if (!IsValidVehicle(vehicleid1) || !IsValidVehicle(vehicleid2)) {
		return FLOAT_INFINITY;
	}

	new Float:x, Float:y, Float:z;
	GetVehiclePos(vehicleid2, x, y, z);

	return GetVehicleDistanceFromPoint(vehicleid1, x, y, z);
}


stock bool:IsVehicleInRangeOfVehicle(vehicleid1, vehicleid2, Float:range) {
	return GetDistanceBetweenVehicles(vehicleid1, vehicleid2) <= range && GetVehicleVirtualWorld(vehicleid1) == GetVehicleVirtualWorld(vehicleid2);
}


stock GetClosestVehicleToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID) {
    new Float:distance = FLOAT_INFINITY, closestid = INVALID_VEHICLE_ID, Float:distance2, vw = GetVehicleVirtualWorld(vehicleid);

    foreach (new i : Vehicle) {
		if (vehicleid == i || i == ignoredid || vw != GetVehicleVirtualWorld(i)) {
            continue;
        }

        if ((distance2 = GetDistanceBetweenVehicles(vehicleid, i)) < distance) {
            distance = distance2;
            closestid = i;
        }
    }

    return closestid;
}


/*
oooooo     oooo           oooo         o8o            oooo                    ooooooooo.   oooo                                           
 `888.     .8'            `888         `"'            `888                    `888   `Y88. `888                                           
  `888.   .8'    .ooooo.   888 .oo.   oooo   .ooooo.   888   .ooooo.           888   .d88'  888   .oooo.   oooo    ooo  .ooooo.  oooo d8b 
   `888. .8'    d88' `88b  888P"Y88b  `888  d88' `"Y8  888  d88' `88b          888ooo88P'   888  `P  )88b   `88.  .8'  d88' `88b `888""8P 
    `888.8'     888ooo888  888   888   888  888        888  888ooo888 8888888  888          888   .oP"888    `88..8'   888ooo888  888     
     `888'      888    .o  888   888   888  888   .o8  888  888    .o          888          888  d8(  888     `888'    888    .o  888     
      `8'       `Y8bod8P' o888o o888o o888o `Y8bod8P' o888o `Y8bod8P'         o888o        o888o `Y888""8o     .8'     `Y8bod8P' d888b    
                                                                                                           .o..P'                         
                                                                                                           `Y8P'                          
*/

#define GetVehicleDistanceFromPlayer(%0,%1) \
    GetPlayerDistanceFromVehicle(%1,%0)


#define IsVehicleInRangeOfPlayer(%0,%1,%2) \
    IsPlayerInRangeOfVehicle(%1,%0,%2)


stock GetClosestPlayerToVehicle(vehicleid, ignoredid = INVALID_PLAYER_ID) {
    new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2, vw = GetVehicleVirtualWorld(vehicleid);

    foreach (new i : Player) {
        if (i == ignoredid || vw != GetPlayerVirtualWorld(i)) {
            continue;
        }

        if ((distance2 = GetPlayerDistanceFromVehicle(vehicleid, i)) < distance) {
            distance = distance2;
            closestid = i;
        }
    }

    return closestid;
}