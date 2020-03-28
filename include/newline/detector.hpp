#pragma once

#include "newline/newline_defs.h"

#include <istream>

namespace newline {

template<typename CharT>
class detector {
    using newline_type = basic_newline<CharT>;

public:
    constexpr detector(newline_type newlineSeq)
        : newlineSeq_(newlineSeq)
    {
    }

    /**
     * \param is the stream to read from
     */
    template<typename Traits>
    bool isnext(std::basic_istream<CharT, Traits>& is) const
    {
        using stream_type = std::basic_istream<CharT, Traits>;

        bool result = false;

        typename stream_type::sentry se{is, true};
        if (se) {
            auto sb = is.rdbuf();
            if (sb != nullptr) {
                result = this->isnext(sb);
            }
        }

        return result;
    }

    /**
     * \param sb the stream buffer to read from
     */
    template<typename Traits>
    bool isnext(std::basic_streambuf<CharT, Traits>* sb) const
    {
        if (newlineSeq_.empty()) {
            return false;
        }

        constexpr auto EOF_VALUE = Traits::eof();

        bool result = true;

        auto it = this->newlineSeq_.begin();
        for (; it != this->newlineSeq_.end(); ++it) {
            auto nc = static_cast<typename Traits::int_type>(*it);
            auto sc = sb->sgetc();
            if (sc == EOF_VALUE || sc != nc) {
                result = false;
                break;
            }
            else {
                sb->sbumpc();
            }
        }

        while (it != this->newlineSeq_.begin()) {
            sb->sungetc();
            --it;
        }

        return result;
    }

private:
    const newline_type newlineSeq_;
};

}
