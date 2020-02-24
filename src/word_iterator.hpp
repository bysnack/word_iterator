#include <string>
#include <iostream>
#include <algorithm>

class word_iterator {
public:
    using difference_type = std::string_view::difference_type;
    using value_type = std::string_view;
    using pointer = std::string_view*;
    using reference = std::string_view&;
    using iterator_category = std::bidirectional_iterator_tag;

    word_iterator() = default;
    word_iterator(std::string_view data) noexcept :
        _data{ data },
        _it{ std::begin(_data) }
    {
    }

    word_iterator& operator--() {
        auto reverse = std::make_reverse_iterator(_it - 1);
        _it = std::find_if(reverse, std::rend(_data), isspace).base();
        
        return *this;
    }


    word_iterator operator--(int) {
        auto copy = *this;
        this->operator--();

        return copy;
    }

    word_iterator& operator++() {
        _it = std::find_if(_it, std::end(_data), isspace) + 1;
        
        return *this;
    }

    word_iterator operator++(int) {
        auto copy = *this;
        this->operator++();

        return copy;
    }

    value_type operator*() noexcept {
        auto it = std::find_if(_it, std::end(_data), isspace);
        if (it == std::end(_data)) {
            return {};
        }
        std::string_view::size_type dist = std::distance(_it, it);
        
        return {_it, dist};
    }

private:
    std::string_view _data;
    std::string_view::iterator _it;
};
