#if defined _inc_distance_diff
	#undef _inc_distance_diff
#endif


stock Float:DISTANCE_AB(Get...DistanceFrom...)(a, b) {
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

	if (_DISTANCE_A(...Pos)(a, x1, y1, z1) && _DISTANCE_B(...Pos)(b, x2, y2, z2)) {
		return VectorSize(x1 - x2, y1 - y2, z1 - z2);
	}

	return FLOAT_NAN;
}


#if defined DISTANCE_INT
	#if defined DISTANCE_VW
		stock bool:DISTANCE_AB(Is...InRangeOf...)(a, b, Float:range, bool:ignoreVW = false, bool:ignoreInterior = false) {
			new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

			return _DISTANCE_A(...Pos)(a, x1, y1, z1)
				&& _DISTANCE_B(...Pos)(b, x2, y2, z2)
				&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
				&& (ignoreVW || _DISTANCE_A(...VW)(a) == _DISTANCE_B(...VW)(b))
				&& (ignoreInterior || _DISTANCE_A(...Interior)(a) == _DISTANCE_B(...Interior)(b))
			;
		}
	#else
		stock bool:DISTANCE_AB(Is...InRangeOf...)(a, b, Float:range, bool:ignoreInterior = false) {
			new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

			return _DISTANCE_A(...Pos)(a, x1, y1, z1)
				&& _DISTANCE_B(...Pos)(b, x2, y2, z2)
				&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
				&& (ignoreInterior || _DISTANCE_A(...Interior)(a) == _DISTANCE_B(...Interior)(b))
			;
		}
	#endif
#else
	#if defined DISTANCE_VW
		stock bool:DISTANCE_AB(Is...InRangeOf...)(a, b, Float:range, bool:ignoreVW = false) {
			new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

			return _DISTANCE_A(...Pos)(a, x1, y1, z1)
				&& _DISTANCE_B(...Pos)(b, x2, y2, z2)
				&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
				&& (ignoreVW || _DISTANCE_A(...VW)(a) == _DISTANCE_B(...VW)(b))
			;
		}
	#else
		stock bool:DISTANCE_AB(Is...InRangeOf...)(a, b, Float:range) {
			new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;

			return _DISTANCE_A(...Pos)(a, x1, y1, z1)
				&& _DISTANCE_B(...Pos)(b, x2, y2, z2)
				&& VectorSize(x1 - x2, y1 - y2, z1 - z2) <= range
			;
		}
	#endif
#endif


#if defined DISTANCE_INT
	#if defined DISTANCE_VW
		stock DISTANCE_AB(GetClosest...To...)(b, ignoredid = _DISTANCE_B(...Invalid)(), bool:ignoreVW = false, bool:ignoreInterior = false) {
	#else
		stock DISTANCE_AB(GetClosest...To...)(b, ignoredid = _DISTANCE_B(...Invalid)(), bool:ignoreInterior = false) {
	#endif
#else
	#if defined DISTANCE_VW
		stock DISTANCE_AB(GetClosest...To...)(b, ignoredid = _DISTANCE_B(...Invalid)(), bool:ignoreVW = false) {
	#else
		stock DISTANCE_AB(GetClosest...To...)(b, ignoredid = _DISTANCE_B(...Invalid)()) {
	#endif
#endif
			new Float:x, Float:y, Float:z;

			if (!_DISTANCE_B(...Pos)(b, x, y, z)) {
				return _DISTANCE_A(...Invalid)();
			}

			new Float:distance = FLOAT_INFINITY, closestid = _DISTANCE_A(...Invalid)(), Float:distance2;

#if defined DISTANCE_INT
			if (ignoreInterior) {
#endif
	#if defined DISTANCE_VW
				if (ignoreVW) {
	#endif
					_DISTANCE_A(...Loop)(i) {
						if (i == ignoredid) {
							continue;
						}

						if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
							distance = distance2;
							closestid = i;
						}
					}
	#if defined DISTANCE_VW
				} else {
					new vw = _DISTANCE_B(...VW)(b);

					_DISTANCE_A(...Loop)(i) {
						if (i == ignoredid || vw != _DISTANCE_A(...VW)(i)) {
							continue;
						}

						if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
							distance = distance2;
							closestid = i;
						}
					}
				}
	#endif
#if defined DISTANCE_INT
			} else {
	#if defined DISTANCE_VW
				if (ignoreVW) {
	#endif
					new interior = _DISTANCE_B(...Interior)(b);

					_DISTANCE_A(...Loop)(i) {
						if (i == ignoredid || interior != _DISTANCE_A(...Interior)(i)) {
							continue;
						}

						if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
							distance = distance2;
							closestid = i;
						}
					}
	#if defined DISTANCE_VW
				} else {
					new vw = _DISTANCE_B(...VW)(b), interior = _DISTANCE_B(...Interior)(b);

					_DISTANCE_A(...Loop)(i) {
						if (i == ignoredid || vw != _DISTANCE_A(...VW)(i) || interior != _DISTANCE_A(...Interior)(i)) {
							continue;
						}

						if ((distance2 = _DISTANCE_A(...Distance)(i, x, y, z)) < distance) {
							distance = distance2;
							closestid = i;
						}
					}
				}
	#endif
			}
#endif

			return closestid;
		}


#if defined DISTANCE_INT
	#undef DISTANCE_INT
#endif

#if defined DISTANCE_VW
	#undef DISTANCE_VW
#endif

#undef DISTANCE_A
#undef DISTANCE_B
#undef DISTANCE_LOOP

