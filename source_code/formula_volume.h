/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_VOLUME__GUARD
# define    FORMULA_VOLUME__GUARD

namespace fml {

    template <typename __C> int volume(const __C &C) {
        int vol = 0;
        for (const auto &E : C) ++vol;
        return vol;
    };

    template <typename __C, typename... ___C> int volume(const __C &C, const ___C&... _C) {
        return fml::volume(C) + fml::volume(_C...);
    };

};

# endif
