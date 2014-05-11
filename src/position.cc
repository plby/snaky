#include "position.hh"

shape reflect_xy( const shape& s ) {
	shape r;

	for( int x = MIN_X; x < MAX_X; x++ ) {
		for( int y = MIN_Y; y < MAX_Y; y++ ) {
			if( not s.get(x,y) )
				continue;
			verify_in_bounds(y,x);

			r.set(y,x);
		}
	}

	return r;
}
shape rotate_xy( const shape& s ) {
//TODO
}

std::vector<shape> rotate_reflect_all( shape s ) {
	std::vector<shape> result;
	shape tmp = s;
	for( int i = 0; i < 2; i++ ) {
		for( int j = 0; j < 4; j++ ) {
			result.push_back( tmp );
			tmp = rotate_xy( tmp );
		}
		tmp = reflect_xy(tmp);
	}

//TODO: Deduplicate?

	return result;
}
