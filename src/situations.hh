#pragma once
#include "position.hh"

/*
  The main structure here keeps track of a *collection* of situations,
  and handles things like organizing them for quick access.
*/
struct situations {
};

void add_leaf_situation( situations& s, const shape g );
bool finished( const situations s );
