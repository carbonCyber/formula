/*
    formula_chop.h
    Copyright (C) 2015  Ohad Drukman

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

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
