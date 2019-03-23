#if defined _inc_distance_diff
	#undef _inc_distance_diff
#endif


// Convenience macros to prepend `DISTANCE_` to everything.
#define _DISTANCE_A(%0...%1) DISTANCE_A(DISTANCE_%0..._%1)
#define _DISTANCE_B(%0...%1) DISTANCE_B(DISTANCE_%0..._%1)


stock Float:DISTANCE_AB(Get...DistanceFrom...)(a, b) {
	new Float:x, Float:y, Float:z;

	if (_DISTANCE_A(...Valid)(a) && _DISTANCE_B(...Pos)(b, x, y, z)) {
		return _DISTANCE_A(...Distance)(a, x, y, z);
	}

	return FLOAT_NAN;
}


#if defined DISTANCE_INT
stock bool:DISTANCE_AB(Is...InRangeOf...)(a, b, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false) {
	new Float:x, Float:y, Float:z;

	return _DISTANCE_A(...Valid)(a)
		&& _DISTANCE_B(...Pos)(b, x, y, z)
		&& _DISTANCE_A(...Distance)(a, x, y, z) <= range
		&& (ignoreVW || _DISTANCE_A(...VW)(a) == _DISTANCE_B(...VW)(b))
		&& (ignoreInterior || _DISTANCE_A(...Interior)(a) == _DISTANCE_B(...Interior)(b))
	;
}
#else
stock bool:DISTANCE_AB(Is...InRangeOf...)(a, b, Float:range, bool:ignoreVW = false) {
	new Float:x, Float:y, Float:z;

	return _DISTANCE_A(...Valid)(a)
		&& _DISTANCE_B(...Pos)(b, x, y, z)
		&& _DISTANCE_A(...Distance)(a, x, y, z) <= range
		&& (ignoreVW || _DISTANCE_A(...VW)(a) == _DISTANCE_B(...VW)(b))
	;
}
#endif


#if defined DISTANCE_INT
stock DISTANCE_AB(GetClosest...To...)(b, ignoredid = _DISTANCE_B(...Invalid)(), aool:ignoreVW = false, aool:ignoreInterior = false) {
#else
stock DISTANCE_AB(GetClosest...To...)(b, ignoredid = _DISTANCE_B(...Invalid)(), aool:ignoreVW = false) {
#endif
	new Float:x, Float:y, Float:z;

	if (!_DISTANCE_B(...Pos)(b, x, y, z)) {
		return _DISTANCE_A(...Invalid)();
	}

	new Float:distance = FLOAT_INFINITY, closestid = _DISTANCE_A(...Invalid)(), Float:distance2;

#if defined DISTANCE_INT
	if (ignoreInterior) {
#endif
		if (ignoreVW) {
			DISTANCE_LOOP (i) {
				if (i == ignoredid) {
					continue;
				}

				if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		} else {
			new vw = _DISTANCE_B(...VW)(b);

			DISTANCE_LOOP (i) {
				if (i == ignoredid || vw != _DISTANCE_A(...VW)(i)) {
					continue;
				}

				if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		}
#if defined DISTANCE_INT
	} else {
		if (ignoreVW) {
			new interior = _DISTANCE_B(...Interior)(b);

			DISTANCE_LOOP (i) {
				if (i == ignoredid || interior != _DISTANCE_A(...Interior)(i)) {
					continue;
				}

				if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		} else {
			new vw = _DISTANCE_B(...VW)(b), interior = _DISTANCE_B(...Interior)(b);

			DISTANCE_LOOP (i) {
				if (i == ignoredid || vw != _DISTANCE_A(...VW)(i) || interior != _DISTANCE_A(...Interior)(i)) {
					continue;
				}

				if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
					distance = distance2;
					closestid = i;
				}
			}
		}
	}
#endif

	return closestid;
}


#if defined DISTANCE_INT
	#undef DISTANCE_INT
#endif

#undef DISTANCE_A
#undef DISTANCE_B
#undef DISTANCE_LOOP

