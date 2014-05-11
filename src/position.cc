#include "position.hh"

shape reflect_xy( const shape& s ) {
	
//TODO
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
