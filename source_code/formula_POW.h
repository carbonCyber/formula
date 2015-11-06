/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_POW_GUARD
# define    FORMULA_POW_GUARD

namespace fml {

    template <int N, int P> struct __POW__ {
        enum : long long { O = N * __POW__<N, P-1>::O };
    };

    template <int N> struct __POW__<N, 0> {
        enum { O = 1 };
    };

    long long POW(int N, int P) {
        long long RES = 1;
        while(P-- > 0) RES *= N;
        //  do if (P & 1) RES *= N; while (P >>= 1, N *= N);
        return RES;
    };

};

# endif
