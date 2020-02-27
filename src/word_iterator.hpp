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
        _it{ std::begin(_data) }
    {
    }

    /**
     *  Pre-decrement operator, moves the iterator to the previous word and returns it
     * 
     *  @return         A reference to this iterator for chaining
     */
    word_iterator& operator--() noexcept {
        auto reverse = std::make_reverse_iterator(_it - 1);
        _it = std::find_if(reverse, std::rend(_data), isspace).base();
        
        return *this;
    }


    /**
     *  Post-decrement operator, moves the iterator to point to the previous word
     * 
     *  @return         A new iterator pointing to the current word
     */
    word_iterator operator--(int) noexcept {
        auto copy = *this;
        this->operator--();

        return copy;
    }

    /**
     *  Pre-increment operator, moves the iterator to the next word and returns it
     * 
     *  @return         A reference to this iterator for chaining
     */
    word_iterator& operator++() noexcept {
        _it = std::find_if(_it, std::end(_data), isspace) + 1;
        
        return *this;
    }

    /**
     *  Post-increment operator, moves the iterator to point to the next word
     * 
     *  @return         A new iterator pointing to the current word
     */
    word_iterator operator++(int) noexcept {
        auto copy = *this;
        this->operator++();

        return copy;
    }

    /**
     *  Derefence operator, retrieves the current pointed word
     * 
     *  @return         A new view of the pointer word
     */
    value_type operator*() const noexcept {
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
