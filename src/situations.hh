#pragma once
#include "position.hh"

/*
  The main structure here keeps track of a *collection* of situations,
  and handles things like organizing them for quick access.
*/
struct situations {
//TODO
	
};

void add_blacks( situations&s, const std::vector<shape> gs );
void add_leaf_situation( situations& s, const shape g );
void add_leaf_situations( situations& s, const std::vector<shape> gs );
bool finished( const situations s );
