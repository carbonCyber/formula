/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_PRINT__GUARD
# define    FORMULA_PRINT__GUARD

namespace fml {

    template <typename __C, typename __F> void print(const __C &C, const __F &F, char sep = '\n', std::ostream &OS = std::cout) {
        for (const auto &E : C) OS << F(E) << sep;
    };

    template <typename __C> void print(const __C &C, char sep = '\n', std::ostream &OS = std::cout) {
        for (const auto &E : C) {
            typedef decltype(E) __T;
            fml::print(C, [] (const __T &T) -> __T { return T; }, sep, OS);
            return;
        }
    };

};

# endif
