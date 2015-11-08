/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_CHOP__GUARD
# define    FORMULA_CHOP__GUARD

# include   "formula_pop.h"

namespace fml {

    namespace mnl {

        template <typename __C> int chop(__C &C, int beg, int end) {
            // HIDDEN //
        };

    };

    template <typename __C> void chop(__C &C, int beg, int end) {
        fml::pop(C, fml::mnl::chop(C, beg, end));
    };

};

# endif
