#if defined _inc_distance
    #undef _inc_distance
#endif

#if defined _distance_included
    #endinput
#endif
#define _distance_included

#include <a_samp>
#include <YSI_Data\y_iterate>


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
    return VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range;
}


stock Float:GetDistanceBetweenPoints2D(Float:x1, Float:y1, Float:x2, Float:y2) {
    return VectorSize(x1 - x2, y1 - y2, 0.0);
}


stock bool:IsPointInRangeOfPoint2D(Float:x1, Float:y1, Float:x2, Float:y2, Float:range) {
    return VectorSize(x1 - x2, y1 - y2, 0.0) <= range;
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
    if (IsPlayerConnected(playerid)) {
		return GetPlayerDistanceFromPoint(playerid, x, y, z);
    }

	return FLOAT_INFINITY;
}

#if defined _ALS_GetPlayerDistanceFromPoint
    #undef GetPlayerDistanceFromPoint
#else
    #define _ALS_GetPlayerDistanceFromPoint
	native BAD_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
#endif
#define GetPlayerDistanceFromPoint( dist_GetPlayerDistanceFromPoint(


stock Float:GetPlayerDistanceFromPoint2D(playerid, Float:x, Float:y) {
    new Float:x2, Float:y2, Float:z2;

    if (GetPlayerPos(playerid, x2, y2, z2)) {
		return GetDistanceBetweenPoints2D(x, y, x2, y2);
    }

	return FLOAT_INFINITY;
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
    if (Iter_Contains(Vehicle, vehicleid)) {
		return GetVehicleDistanceFromPoint(vehicleid, x, y, z);
    }

	return FLOAT_INFINITY;
}

#if defined _ALS_GetVehicleDistFromPoint
    #undef GetVehicleDistanceFromPoint
#else
    #define _ALS_GetVehicleDistFromPoint
	native BAD_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
#endif
#define GetVehicleDistanceFromPoint( dist_GetVehicleDistFromPoint(


stock bool:IsVehicleInRangeOfPoint(vehicleid, Float:range, Float:x, Float:y, Float:z) {
    return GetVehicleDistanceFromPoint(vehicleid, x, y, z) <= range;
}


stock Float:GetVehicleDistanceFromPoint2D(vehicleid, Float:x, Float:y) {
    new Float:x2, Float:y2, Float:z2;

    if (GetVehiclePos(vehicleid, x2, y2, z2)) {
		return GetDistanceBetweenPoints2D(x, y, x2, y2);
    }

	return FLOAT_INFINITY;
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
    new Float:x, Float:y, Float:z;

    if (GetPlayerPos(playerid2, x, y, z)) {
		return GetPlayerDistanceFromPoint(playerid1, x, y, z);
    }

	return FLOAT_INFINITY;
}


stock bool:IsPlayerInRangeOfPlayer(playerid1, playerid2, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false) {
	new Float:x, Float:y, Float:z;

	return IsPlayerConnected(playerid1)
		&& GetPlayerPos(playerid2, x, y, z)
		&& BAD_GetPlayerDistanceFromPoint(playerid1, x, y, z) <= range
		&& (ignoreVW || GetPlayerVirtualWorld(playerid1) == GetPlayerVirtualWorld(playerid2))
		&& (ignoreInterior || GetPlayerInterior(playerid1) == GetPlayerInterior(playerid2))
	;
}


stock GetClosestPlayerToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false) {
    new Float:x, Float:y, Float:z;

    if (!GetPlayerPos(playerid, x, y, z)) {
		return INVALID_PLAYER_ID;
    }

    new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;
	if (ignoreInterior) {
		if (ignoreVW) {
			foreach (new i : Player) {
				if (i == ignoredid) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		} else {
			new vw = GetPlayerVirtualWorld(playerid);
			foreach (new i : Player) {
				if (i == ignoredid || vw != GetPlayerVirtualWorld(i)) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		}
	} else {
		if (ignoreVW) {
			new interior = GetPlayerInterior(playerid);
			foreach (new i : Player) {
				if (i == ignoredid || interior != GetPlayerInterior(i)) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		}
		else {
			new vw = GetPlayerVirtualWorld(playerid);
			new interior = GetPlayerInterior(playerid);
			foreach (new i : Player) {
				if (i == ignoredid || vw != GetPlayerVirtualWorld(i) || interior != GetPlayerInterior(i)) {
					continue;
				}

				if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
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
    new Float:x, Float:y, Float:z;

    if (GetVehiclePos(vehicleid, x, y, z)) {
		return GetPlayerDistanceFromPoint(playerid, x, y, z);
    }

	return FLOAT_INFINITY;
}


#if defined GetVehicleInterior
	stock bool:IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false) {
		new Float:x, Float:y, Float:z;

		return IsPlayerConnected(playerid)
			&& GetVehiclePos(vehicleid, x, y, z)
			&& BAD_GetPlayerDistanceFromPoint(playerid, x, y, z) <= range
			&& (ignoreVW || GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(vehicleid))
			&& (ignoreInterior || GetPlayerInterior(playerid) == GetVehicleInterior(vehicleid))
		;
	}
#else
	stock bool:IsPlayerInRangeOfVehicle(playerid, vehicleid, Float:range, bool:ignoreVW = false) {
		new Float:x, Float:y, Float:z;

		return IsPlayerConnected(playerid)
			&& GetVehiclePos(vehicleid, x, y, z)
			&& BAD_GetPlayerDistanceFromPoint(playerid, x, y, z) <= range
			&& (ignoreVW || GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(vehicleid))
		;
	}
#endif


#if defined GetVehicleInterior
	stock GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false) {
#else
	stock GetClosestVehicleToPlayer(playerid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false) {
#endif
		new Float:x, Float:y, Float:z;

		if (!GetPlayerPos(playerid, x, y, z)) {
			return INVALID_PLAYER_ID;
		}

		new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;
#if defined GetVehicleInterior
		if (ignoreInterior) {
#endif
			if (ignoreVW) {
				foreach (new i : Vehicle) {
					if (i == ignoredid) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			} else {
				new vw = GetPlayerVirtualWorld(playerid);
				foreach (new i : Vehicle) {
					if (i == ignoredid || vw != GetVehicleVirtualWorld(i)) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			}
#if defined GetVehicleInterior
		} else {
			if (ignoreVW) {
				new interior = GetPlayerInterior(playerid);
				foreach (new i : Vehicle) {
					if (i == ignoredid || interior != GetVehicleInterior(i)) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			} else {
				new vw = GetPlayerVirtualWorld(playerid);
				new interior = GetPlayerInterior(playerid);
				foreach (new i : Vehicle) {
					if (i == ignoredid || vw != GetVehicleVirtualWorld(i) || interior != GetVehicleInterior(i)) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			}
		}
#endif

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
    new Float:x, Float:y, Float:z;

    if (GetVehiclePos(vehicleid2, x, y, z)) {
		return GetVehicleDistanceFromPoint(vehicleid1, x, y, z);
    }

	return FLOAT_INFINITY;
}


#if defined GetVehicleInterior
	stock bool:IsVehicleInRangeOfVehicle(vehicleid1, vehicleid2, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false) {
		new Float:x, Float:y, Float:z;

		return Iter_Contains(Vehicle, vehicleid1)
			&& GetVehiclePos(vehicleid2, x, y, z)
			&& BAD_GetVehicleDistanceFromPoint(vehicleid1, x, y, z) <= range
			&& (ignoreVW || GetVehicleVirtualWorld(vehicleid1) == GetVehicleVirtualWorld(vehicleid2))
			&& (ignoreInterior || GetVehicleInterior(vehicleid1) == GetVehicleInterior(vehicleid2))
		;
	}
#else
	stock bool:IsVehicleInRangeOfVehicle(vehicleid1, vehicleid2, Float:range, bool:ignoreVW = false) {
		new Float:x, Float:y, Float:z;

		return Iter_Contains(Vehicle, vehicleid1)
			&& GetVehiclePos(vehicleid2, x, y, z)
			&& BAD_GetVehicleDistanceFromPoint(vehicleid1, x, y, z) <= range
			&& (ignoreVW || GetVehicleVirtualWorld(vehicleid1) == GetVehicleVirtualWorld(vehicleid2))
		;
	}
#endif


#if defined GetVehicleInterior
	stock GetClosestVehicleToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false, bool:ignoreInterior = false) {
#else
	stock GetClosestVehicleToVehicle(vehicleid, ignoredid = INVALID_VEHICLE_ID, bool:ignoreVW = false) {
#endif
		new Float:x, Float:y, Float:z;

		if (!GetVehiclePos(vehicleid, x, y, z)) {
			return INVALID_PLAYER_ID;
		}

		new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;
#if defined GetVehicleInterior
		if (ignoreInterior) {
#endif
			if (ignoreVW) {
				foreach (new i : Vehicle) {
					if (i == ignoredid) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			} else {
				new vw = GetVehicleVirtualWorld(vehicleid);
				foreach (new i : Vehicle) {
					if (i == ignoredid || vw != GetVehicleVirtualWorld(i)) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			}
#if defined GetVehicleInterior
		} else {
			if (ignoreVW) {
				new interior = GetVehicleInterior(vehicleid);
				foreach (new i : Vehicle) {
					if (i == ignoredid || interior != GetVehicleInterior(i)) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			} else {
				new vw = GetVehicleVirtualWorld(vehicleid);
				new interior = GetVehicleInterior(vehicleid);
				foreach (new i : Vehicle) {
					if (i == ignoredid || vw != GetVehicleVirtualWorld(i) || interior != GetVehicleInterior(i)) {
						continue;
					}

					if ((distance2 = BAD_GetVehicleDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			}
		}
#endif

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


#if defined GetVehicleInterior
	stock GetClosestPlayerToVehicle(vehicleid, ignoredid = INVALID_PLAYER_ID, bool:ignoreVW = false, bool:ignoreInterior = false) {
#else
	stock GetClosestPlayerToVehicle(vehicleid, ignoredid = INVALID_PLAYER_ID, bool:ignoreVW = false) {
#endif
		new Float:x, Float:y, Float:z;

		if (!GetVehiclePos(vehicleid, x, y, z)) {
			return INVALID_PLAYER_ID;
		}

		new Float:distance = FLOAT_INFINITY, closestid = INVALID_PLAYER_ID, Float:distance2;
#if defined GetVehicleInterior
		if (ignoreInterior) {
#endif
			if (ignoreVW) {
				new vw = GetVehicleVirtualWorld(vehicleid);
				foreach (new i : Player) {
					if (i == ignoredid || vw != GetPlayerVirtualWorld(i)) {
						continue;
					}

					if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			} else {
				foreach (new i : Player) {
					if (i == ignoredid) {
						continue;
					}

					if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			}
#if defined GetVehicleInterior
		} else {
			if (ignoreVW) {
				new interior = GetVehicleInterior(vehicleid);
				foreach (new i : Player) {
					if (i == ignoredid || interior != GetPlayerInterior(i)) {
						continue;
					}

					if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			} else {
				new vw = GetVehicleVirtualWorld(vehicleid);
				new interior = GetVehicleInterior(vehicleid);
				foreach (new i : Player) {
					if (i == ignoredid || vw != GetPlayerVirtualWorld(i) || interior != GetPlayerInterior(i)) {
						continue;
					}

					if ((distance2 = BAD_GetPlayerDistanceFromPoint(i, x, y, z)) < distance) {
						distance = distance2;
						closestid = i;
					}
				}
			}
		}
#endif

		return closestid;
	}

