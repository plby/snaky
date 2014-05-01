#include<vector>

#include "position.hh"
#include "situations.hh"

/*
  Return the goal shape.  Theoretically, this shape could be a
  constant or could come as a parameter.
*/
shape goal_shape( ) {
	shape goal;
	goal.set( 0, 0 );
	goal.set( 1, 0 );
	goal.set( 2, 0 );
	return goal;
}

/*
  Add all of the reflections and rotations to a collection of
  situations as leaves.
*/
void add_rotated_leaves( situations& s, const shape g ) {
	std::vector<shape> symmetries = rotate_reflect_all( g );
	for( std::vector<shape>::iterator i = symmetries.begin();
	     i != symmetries.end();
	     i++ ) {
		add_leaf_situation( s, *i );
	}
}

void deduce( situations& s );
int main( ) {
	situations wins;

	shape goal = goal_shape();
	add_rotated_leaves( wins, goal );
	while( not finished(wins) ) {
		deduce( wins );
	}

	return 0;
}
