/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_INDEXOF__GUARD
# define    FORMULA_INDEXOF__GUARD

namespace fml {

    template <typename __C, typename __F, typename __T> int indexof(const __C &C, const __F &F, const __T &T) {
        int index = 0;
        for (const auto &E : C)
            if (F(T, E)) return index;
            else ++index;
        return -1;
    };

    template <typename __C, typename __T> int indexof(const __C &C, const __T &T) {
        return fml::indexof(C, [] (const __T &T1, const __T &T2) -> bool { return T1 == T2; }, T);
    };

};

# endif
