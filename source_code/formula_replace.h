/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_REPLACE__GUARD
# define    FORMULA_REPLACE__GUARD

namespace fml {

    template <typename __C, typename __F, typename __T> void replace(__C &C, const __F &F, const __T &T1, const __T &T2) {
        for (auto &E : C) if (F(T1, E)) E = T2;
    };

    template <typename __C, typename __T> void replace(__C &C, const __T &T1, const __T &T2) {
        fml::replace(C, [] (const __T &T1, const __T &T2) -> bool { return T1 == T2; }, T1, T2);
    };

};

# endif
