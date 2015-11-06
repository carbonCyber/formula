/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_DEC_BIN__GUARD
# define    FORMULA_DEC_BIN__GUARD

namespace fml {

    template <int I> struct __DEC_BIN__ {
        enum : long long { O = ((I % 2) + __DEC_BIN__<I / 2>::O * 10) };
    };

    template <> struct __DEC_BIN__<0> {
        enum : long long { O = 0 };
    };

    long long DEC_BIN(int I) {
        long long BIN = 1; bool OD = I % 2;
        while (I /= 2) BIN *= 10, BIN += I % 2;
        return BIN - !OD;
    };  /*  algorithm bug with runtime functions    */

};

# endif
