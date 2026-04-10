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
        compute_column();
    } 
    else {
        --column;
    }

    return true;
}

void TextBuffer::insert(char c) {
  data.insert(cursor, c);

  if (c == '\n') {
    ++row;
    column = 0;
  } 
  else {
    ++column;
  }

  ++index;
}

bool TextBuffer::remove() {
  if (cursor == data.end()) return false;

  char c = *cursor;
  cursor = data.erase(cursor);

  if (c == '\n') {
    --row;
    compute_column();
  } 

  return true;
}

void TextBuffer::move_to_row_start() {
  while (cursor != data.begin()) {
    --cursor;
    if (*cursor == '\n') {
      ++cursor;
      break;
    }
  }
  column = 0;
}

void TextBuffer::move_to_row_end() {
  while (cursor != data.end() && *cursor != '\n') {
    ++cursor;
    ++column;
  }
}

bool TextBuffer::is_at_end() const {
  return cursor == data.end();
}

char TextBuffer::data_at_cursor() const {
  assert(cursor != data.end());
  return *cursor;
}

bool TextBuffer::is_at_end() const {
  return cursor == data.end();
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