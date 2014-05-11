#include "position.hh"

/*
  Reflect the shape across the line y = x, regardless of the values of
  MIN_X, etc.

  Throws an exception if doing so pushes the shape out of bounds.
 */
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

/*
  Rotate the shape so that the origin stays fixed and the x-axis goes
  to the y-axis.

  Throws an exception if doing so pushes the shape out of bounds.
 */
shape rotate_xy( const shape& s ) {
	shape r;

	for( int x = MIN_X; x < MAX_X; x++ ) {
		for( int y = MIN_Y; y < MAX_Y; y++ ) {
			if( not s.get(x,y) )
				continue;
			verify_in_bounds(-y,x);

			r.set(-y,x);
		}
	}

	return r;	
}

/*
  Translates the shape so that the origin (0, 0) moves to (dx, dy).

  Throws an exception if doing so pushes the shape out of bounds.
 */
shape translate( const shape& s, int dx, int dy ) {
	shape r;

	for( int x = MIN_X; x < MAX_X; x++ ) {
		for( int y = MIN_Y; y < MAX_Y; y++ ) {
			if( not s.get(x,y) )
				continue;
			verify_in_bounds(x+dx,y+dy);

			r.set(x+dx,y+dy);
		}
	}

	return r;	
}

/*
  Return a list of the (up to) 8 rotations and reflections of a given
  shape.

  We do not deduplicate the results for now because we don't need that
  optimization.
*/
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

	return result;
}

/*
  Generate a canonical form of a situation.  Because we aren't
  currently considered rotation and reflection optimization, this just
  means translating the black squares.

  Throws exception if something is forced out of bounds.
 */
situation canonical( const situation& s ) {
	// Find smallest x and y coordinates present in black shape
	int min_x = MAX_X;
	int min_y = MAX_Y;
	for( int x = MIN_X; x < MAX_X; x++ ) {
		for( int y = MIN_Y; y < MAX_Y; y++ ) {
			if( not s.black.get(x,y) )
				continue;

			if( x < min_x )
				min_x = x;
			if( y < min_y )
				min_y = y;
		}
	}

	if( min_x == MAX_X or min_y == MAX_Y )
		return s;

	situation r;
	r.black    = translate( s.black   , -min_x, -min_y );
	r.relevant = translate( s.relevant, -min_x, -min_y );
	return r;
}
