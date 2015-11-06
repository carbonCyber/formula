/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_BIN_DEC__GUARD
# define    FORMULA_BIN_DEC__GUARD

namespace fml {

    template <long long I> struct __BIN_DEC__ {
        enum : long long { O = (I % 10) + 2 * __BIN_DEC__<I / 10>::O };
    };

    template <> struct __BIN_DEC__<0> {
        enum { O = 0 };
    };

    int BIN_DEC(long long I) {
        int DEC = 1; bool MR = I % 10;
        while (I /= 10) DEC *= 2, DEC += I % 10;
        return DEC - !MR;
    };  /*  algorithm bug with runtime functions    */
};

# endif
