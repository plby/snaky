#pragma once
#include "position.hh"

/*
  The main structure here keeps track of a *collection* of situations,
  and handles things like organizing them for quick access.
*/
#include <unordered_map>
struct situations {
	std::unordered_map<shape, std::vector<situation> > s;
};

/*
  Build up the collection of possible black shapes tracked.
*/
void add_blacks( situations&s, const std::vector<shape> gs );

struct unexpected : std::exception {};
void add_leaf_situation( situations& s, const shape g );
void add_leaf_situations( situations& s, const std::vector<shape> gs );

/*
  Test if the search is complete and a winning strategy has been found.
*/
bool finished( const situations s );
