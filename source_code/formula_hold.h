/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_HOLD__GUARD
# define    FORMULA_HOLD__GUARD

namespace fml {

    template <typename __C, typename __F, typename __T> bool hold(const __C &C, const __F &F, const __T &T) {
        for (const auto &E : C) if (F(T, E)) return 1;
        return 0;
    };

    template <typename __C, typename __F, typename __T, typename... ___T> bool hold(const __C &C, const __F &F, const __T &T, const ___T&... _T) {
        return fml::hold(C, F, T) && fml::hold(C, F, _T...);
    };

    template <typename __C, typename __T> bool hold(const __C &C, const __T &T) {
        return hold(C, [] (const __T &T1, const __T &T2) -> bool { return T1 == T2; }, T);
    };

    template <typename __C, typename __T, typename... ___T> bool hold(const __C &C, const __T &T, const ___T&... _T) {
        return hold(C, T) + hold(C, [] (const __T &T1, const __T &T2) -> bool { return T1 == T2; }, _T...);
    };

    template <typename __C, typename __T> bool hold(const __C &C, const __T &T1, const __T &T2) {
        return fml::hold(C, T1) && fml::hold(C, T2);
    };

    template <typename __C, typename __T, typename... ___T> bool hold(const __C &C, const __T &T1, const __T &T2, const ___T&... _T) {
        return fml::hold(C, T1, T2) && fml::hold(C, _T...);
    };

};

# endif
