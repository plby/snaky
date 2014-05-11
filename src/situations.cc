#include "situations.hh"

void add_blacks( situations&s, const std::vector<shape> gs ) {
//TODO
}

void add_leaf_situation( situations& s, const shape g ) {
//TODO
}

void add_leaf_situations( situations& s, const std::vector<shape> gs ) {
	for( std::vector<shape>::const_iterator i = gs.begin();
	     i != gs.end();
	     i++ ) {
		add_leaf_situation( s, *i );
	}
}

bool finished( const situations s ) {
	for( std::unordered_map<shape, std::vector<situation> >::const_iterator i = s.s.begin();
	     i != s.s.end();
	     i++ ) {
		if( i->first.present.count() == 1 and i->second.size() > 0 )
			return true;
	}

	return false;
}
