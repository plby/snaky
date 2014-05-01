#pragma once

/*
  There are a few different useful concepts of "position" in a weak
  achievement game, like that of Snaky.

  Most obviously, there is a "board position", which is a finite or
  infinite board where some squares are filled with black stones, some
  with white stones, and the rest empty.  We will not need to
  implement this concept.

  Instead, we will have the concept of a "situation", which is a
  fragment of a board position, which has some squares filled with
  black stones, some squares empty, and the rest *irrelevant*.  We
  notably do not keep track of white stones, except in the negative
  sense that empty squares do not have them.  (NB: Situations will, in
  some sense, represent an equivalence class of situations up to
  translation, but the first implementation will not consider
  rotations or reflections.)

  A situation is represented as a collection of "black stone squares"
  and a collection of "non-white-stone squares".  (In particular, the
  black stone squares will be part of the non-white stone squares.
  Thus, the complement of the non-white-stone squares are the
  irrelevant squares.  As such, we shall say "relevant" instead of
  "non-white".)  Each of these is represented in a structure called a
  "shape", which is a collection of squares in a grid.
 */

#include<bitset>
#include<vector>

/*
  A shape is a subset of the squares in [MIN_X, MAX_X) x [MIN_Y,
  MAX_Y), represented with a bitset.  Here as everywhere else,
  intervals are half-open.

  The user of this structure is generally responsible for testing that
  modifications are within bounds.
*/
#include "const.hh"
const int COL = MAX_Y - MIN_Y;
const int MAX_SQUARES = (MAX_X - MIN_X) * (MAX_Y - MIN_Y);
struct shape {
	std::bitset<MAX_SQUARES> present;

	inline bool get( const int x, const int y ) const {
		return present[(x-MIN_X)*COL + (y-MIN_Y)];
	}
	inline shape& set( int x, int y, bool val = true ) {
		present.set( (x-MIN_X)*COL + (y-MIN_Y), val );
		return *this;
	}
};
inline bool in_bounds( const int x, const int y ) {
	return MIN_X <= x and x < MAX_X and MIN_Y <= y and y < MAX_Y;
}

std::vector<shape> rotate_reflect_all( shape s );

/*
  A "situation" is a collection of relevant squares, some
  subcollection of which is black stones.

  The user of this structure is generally responsible for insuring
  that the subcollection property is upheld.
*/
struct situation {
	shape relevant;
	shape black;
};
