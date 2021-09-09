//
// Created by Daniil Kolesnik on 31/08/2021.
//

#ifndef LR5_ISSUERESOLUTION_MY_ITERATOR_H
#define LR5_ISSUERESOLUTION_MY_ITERATOR_H


#include <iterator>

template<typename T>
class my_iterator {

    T* pos = nullptr;

public:

    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using pointer = T*;
    using reference = T&;



    //using iterator_category = std::output_iterator_tag;
private:


public:
    pointer get_pos(){
        return pos;
    }

    explicit my_iterator(pointer ptr) : pos(ptr) {};// теперь итератор смотрит на ptr.  explicit in order to prevent implicit cast from pointer to my_iterator



    bool operator==(const my_iterator& other) const { //PASS
        return pos == other.pos; // if slots are equal return 1
    }

    bool operator!=(const my_iterator& other) const { //PASS
        return pos != other.pos; // if slots are equal return 0
    }

    pointer operator->() { //PASS
        return pos; // get address of a pointer
    }

    reference operator*() const { //PASS
        return *pos; //return int position
    }

    my_iterator operator+(const difference_type& diff) const { //diff + iterator /10 //PASS
        return my_iterator(pos + diff); // return iterator with position pos + diff
    }

    my_iterator operator-(const difference_type& diff) const { //iterator - diff /12 //PASS
        return my_iterator(pos - diff); // return iterator with position pos - diff
    }

    difference_type operator-(const my_iterator& other) const { // iterator - iterator 13 //PASS
        return std::distance(other.pos, pos);
    }

    bool operator>(const my_iterator& other) const {  //PASS
        return pos > other.pos; // look at the furthest from the origin and return 1 if the furthest 0 if other is the furthest
    }

    bool operator<(const my_iterator& other) const { //PASS
        return pos < other.pos; // look at the furthest from the origin and return 0 if the furthest 1 if other is the furthest
    }

    bool operator>=(const my_iterator& other) const { //PASS
        return pos >= other.pos; // look at the furthest from the origin and return 1 if the furthest 0 if other is the furthest
    } //also returns 1 if both point at the same element

    bool operator<=(const my_iterator& other) const { //PASS
        return pos <= other.pos; // look at the furthest from the origin and return 0 if the furthest 1 if the other is the furthest
    }// also returns 1 if both point at the same element

    reference operator[](size_t index) const { //PASS
        return pos[index]; // returns a reference to an element pointed by index . is pos an array? yes
    }



    my_iterator& operator++() { //right side //PASS
        ++pos;
        return *this;
    }

    my_iterator operator++(int) { //left side //PASS
        my_iterator tmp = *this;
        ++pos;
        return *this;
    }

    my_iterator& operator--() {//right side //PASS
        --pos;
        return *this;
    }

    my_iterator operator--(int) noexcept { //left side //PASS
        my_iterator tmp = *this;
        --pos;
        return tmp;
    }


    my_iterator& operator+=(const difference_type& diff) { // modify pos (+=) //PASS
        pos += diff;
        return *this;
    }

    my_iterator& operator-=(const difference_type& diff) { // modify pos (-=) //PASS
        pos -= diff;
        return *this;
    }

    friend my_iterator operator+(difference_type const& diff, my_iterator const& it) {
        return it + diff;
    } // 11 //iterator + diff


};



#endif //LR5_ISSUERESOLUTION_MY_ITERATOR_H
