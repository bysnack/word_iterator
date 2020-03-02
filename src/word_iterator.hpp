#include <string>
#include <iostream>
#include <algorithm>

/**
 *  Class used to iterate a sencence word by word
 */
class word_iterator {
public:
    using difference_type = std::string_view::difference_type;
    using value_type = std::string_view;
    using iterator_category = std::bidirectional_iterator_tag;

    /**
     *  Default constructor
     */
    word_iterator() = default;
    

    /**
     *  String constructor
     *
     *  @param  data    The string containign the sentence to iterate through
     */
    word_iterator(std::string_view data) noexcept :
        _data{ data },
        _it{ std::begin(_data) },
        _length{ static_cast<std::string_view::size_type>(std::distance(_it, std::find_if(_it, std::end(_data), isspace))) }
    {
    }

    /**
     *  Pre-decrement operator, moves the iterator to the previous word and returns it
     * 
     *  @return         A reference to this iterator for chaining
     */
    word_iterator& operator--() noexcept {
        auto reverse = std::make_reverse_iterator(_it - 1);
        auto it = std::find_if(reverse, std::rend(_data), isspace);
        _length = std::distance(reverse, it);
        _it = it.base();
        
        return *this;
    }


    /**
     *  Post-decrement operator, moves the iterator to point to the previous word
     * 
     *  @return         A new iterator pointing to the current word
     */
    word_iterator operator--(int) noexcept {
        auto retval = *this;
        --(*this);

        return retval;
    }

    /**
     *  Pre-increment operator, moves the iterator to the next word and returns it
     * 
     *  @return         A reference to this iterator for chaining
     */
    word_iterator& operator++() noexcept {
        _it = std::find_if(_it, std::end(_data), isspace) + 1;
        _length = std::distance(_it, std::find_if(_it, std::end(_data), isspace));

        return *this;
    }

    /**
     *  Post-increment operator, moves the iterator to point to the next word
     * 
     *  @return         A new iterator pointing to the current word
     */
    word_iterator operator++(int) noexcept {
        auto retval = *this;
        ++(*this);

        return retval;
    }

    /**
     *  Derefence operator, retrieves the current pointed word
     * 
     *  @return         A new view of the pointed word
     */
    value_type operator*() const noexcept {
        if (_it == std::end(_data)) return {};

        return {_it, _length};
    }

    bool operator==(word_iterator other) const noexcept {
        return _it == other._it;
    }

    bool operator!=(word_iterator other) const noexcept {
        return !(*this == other);
    }

private:
    std::string_view _data;
    std::string_view::iterator _it;
    std::string_view::size_type _length;
};
