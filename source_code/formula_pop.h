/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_POP__GUARD
# define    FORMULA_POP__GUARD

namespace fml {

    template <typename __C> void pop(__C &C, int N) {
        while(N--) C.pop_back();
    };

};

# endif
