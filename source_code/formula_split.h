/*
 *  purpose
 *  usage
 *  example
 */

# ifndef    FORMULA_SPLIT__GUARD
# define    FORMULA_SPLIT__GUARD

# include   <vector>

namespace fml {

    std::vector<std::string> split(const std::string &data, char sep = ' ') {
        std::vector<std::string> res;
        std::string hold = "";
        for (char c : data)
            if (c == sep)
                if (hold[0]) {
                    res.push_back(hold); hold = ""; } else;
            else hold += c;
        res.push_back(hold);
        return res;
    };

};

# endif
