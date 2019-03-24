#if defined _inc_distance_point
	#undef _inc_distance_point
#endif


stock Float:DISTANCE_A(Get...DistanceFromPoint)(a, Float:x, Float:y, Float:z = FLOAT_NAN) {
	new Float:x2, Float:y2, Float:z2;

	if (_DISTANCE_A(...Pos)(a, x2, y2, z2)) {
		return _:z == _:FLOAT_NAN ? VectorSize(x - x2, y - y2, 0.0) : VectorSize(x - x2, y - y2, z - z2);
	}

	return FLOAT_NAN;
}


stock bool:DISTANCE_A(Is...InRangeOfPoint)(a, Float:range, Float:x, Float:y, Float:z = FLOAT_NAN) {
	new Float:x2, Float:y2, Float:z2;

	return _DISTANCE_A(...Pos)(a, x2, y2, z2) && (_:z == _:FLOAT_NAN ? VectorSize(x - x2, y - y2, 0.0) : VectorSize(x - x2, y - y2, z - z2));
}


//stock Float:DISTANCE_A(Get...DistanceFromPoint2D)(a, Float:x, Float:y) {
//	new Float:x2, Float:y2, Float:z2;
//
//	if (_DISTANCE_A(...Pos)(a, x2, y2, z2)) {
//		return VectorSize(x - x2, y - y2, 0.0);
//	}
//
//	return FLOAT_NAN;
//}
//
//
//stock bool:DISTANCE_A(Is...InRangeOfPoint2D)(a, Float:range, Float:x, Float:y) {
//	new Float:x2, Float:y2, Float:z2;
//
//	return _DISTANCE_A(...Pos)(a, x2, y2, z2) && VectorSize(x - x2, y - y2, 0.0) <= range;
//}


#undef DISTANCE_A

