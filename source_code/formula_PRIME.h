/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_PRIME_GUARD
# define    FORMULA_PRIME_GUARD

namespace fml {

    template <int I, int C> struct __PRIME__ {
        enum : bool { O = I % C == 0 ? 0 : __PRIME__<I, C+1>::O };
    };

    template <int I> struct __PRIME__<I, I> {
        enum : bool { O = 1 };
    };

    bool PRIME(int I) {
        int C = 2;
        do if (I % C == 0) return 0; while (++C != I);
        return 1;
    };

};

# endif
