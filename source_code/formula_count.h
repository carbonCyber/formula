/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_COUNT__GUARD
# define    FORMULA_COUNT__GUARD

namespace fml {

    template <typename __C, typename __F, typename __T> int count(const __C &C, const __F &F, const __T &T) {
        int cnt = 0;
        for (const auto &E : C) if (F(T, E)) ++cnt;
        return cnt;
    };

    template <typename __C, typename __F, typename __T, typename... ___T> int count(__C &C, const __F &F, const __T &T, const ___T&... _T) {
        return fml::count(C, F, T) + fml::count(C, F, _T...);
    };

    template <typename __C, typename __T> int count(__C &C, const __T &T) {
        return fml::count(C, [] (const __T &T1, const __T &T2) -> bool { return T1 == T2; }, T);
    };

    template <typename __C, typename __T, typename... ___T> int count(__C &C, const __T &T, const ___T&... _T) {
        return fml::count(C, T) + fml::count(C, [] (const __T &T1, const __T &T2) -> bool { return T1 == T2; }, _T...);
    };

    template <typename __C, typename __T> int count(__C &C, const __T &T1, const __T &T2) {
        return fml::count(C, T1) + fml::count(C, T2);
    };

    template <typename __C, typename __T, typename... ___T> int count(__C &C, const __T &T1, const __T &T2, const ___T&... _T) {
        return fml::count(C, T1, T2) + fml::count(C, _T...);
    };

};

# endif
