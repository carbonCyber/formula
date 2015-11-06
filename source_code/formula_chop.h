/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_CHOP__GUARD
# define    FORMULA_CHOP__GUARD

# include   "formula_pop.h"

namespace fml {

    namespace mnl {

        template <typename __C> int chop(__C &C, int beg, int end) {
            int index = 0, replaced = 0, sub_index;
            bool contact = 0;
            for (auto &E : C) {
                if (index == end) contact = 0;
                if (!contact && index == beg) contact = 1;
                if (contact) {
                    sub_index = 0;
                    for (auto &E2 : C)
                        if (sub_index++ != replaced);
                        else {
                            E2 = E; ++replaced;
                            break; }}
                ++index; }
            return index - replaced;
        };

    };

    template <typename __C> void chop(__C &C, int beg, int end) {
        fml::pop(C, fml::mnl::chop(C, beg, end));
    };

};

# endif
