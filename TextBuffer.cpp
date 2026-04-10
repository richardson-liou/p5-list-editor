#include "TextBuffer.hpp"
#include <cassert>

using namespace std;

TextBuffer::TextBuffer() 
    : data(), cursor(data.end()), row(1), column(0), index(0) {}

bool TextBuffer::forward(){
    if (cursor == data.end()) return false;

    if (*cursor == '\n') {
        ++row;
        column = 0;
    } 
    else {
        ++column;
    }

    ++cursor;
    ++index;
    return true;
}

bool TextBuffer::backward() {
    if (cursor == data.begin()) return false;

    --cursor;
    --index;

    if (*cursor == '\n') {
        --row;
        column = compute_column();
    } 
    else {
        --column;
    }

    return true;
}

void TextBuffer::insert(char c) {
    data.insert(cursor, c);
    ++index;
    if (c == '\n') {
        ++row;
        column = 0;
    } 
    else {
        ++column;
    }
}

bool TextBuffer::remove() {
    if (cursor == data.end()) return false;

    char c = *cursor;
    cursor = data.erase(cursor);
    --index;

    if (c == '\n') {
        --row;
        column = compute_column();
    } 

    return true;
}

void TextBuffer::move_to_row_start() {
    while (cursor != data.begin()) {
        auto prev = cursor;
        --prev;
        if (*prev == '\n') break;
        --cursor;
        --index;
    }
    column = 0;
}

void TextBuffer::move_to_row_end() {
    while (cursor != data.end() && *cursor != '\n') {
        ++cursor;
        ++column;
        ++index;
    }
}

void TextBuffer::move_to_column(int new_column){
    move_to_row_start();
    
    while (column < new_column && cursor != data.end() && *cursor != '\n') {
        forward();
    }
}

bool TextBuffer::up(){
    if (row == 1){
        return false;
    }

    int curr_col = column;

    move_to_row_start();
    if (cursor == data.begin()) {
        return false;
    }

    backward();
    move_to_row_start();
    move_to_column(curr_col);

    return true;
}

bool TextBuffer::down(){
    int start_index = index;
    int curr_col = column;

    move_to_row_end();

    if (cursor == data.end()) return false;

    forward();

    move_to_column(curr_col);

    return index != start_index;
}

bool TextBuffer::is_at_end() const {
    return cursor == data.end();
}

char TextBuffer::data_at_cursor() const {
    assert(cursor != data.end());
    return *cursor;
}

int TextBuffer::get_row() const {
    return row;
}

int TextBuffer::get_column() const {
    return column;
}

int TextBuffer::get_index() const {
    return index;
}

int TextBuffer::size() const{
    return data.size();
}

std::string TextBuffer::stringify() const {
    string result;
    for (char c : data) {
        result += c;
    }
    return result;
}

int TextBuffer::compute_column() const{
    int column = 0;
    auto it = cursor;

    while (it != data.begin()) {
        --it;
        if (*it == '\n') break;

        ++column;
    }
    return column;
}