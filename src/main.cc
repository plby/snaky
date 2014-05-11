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

void deduce( situations& s );
int main( ) {
	situations wins;

	shape goal = goal_shape();
	std::vector<shape> goals = rotate_reflect_all( goal );
	add_blacks( wins, goals );
	add_leaf_situations( wins, goals );
	while( not finished(wins) ) {
		deduce( wins );
	}

	return 0;
}
