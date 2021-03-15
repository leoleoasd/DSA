#pragma once

#define DEFAULT__cap 10

template <typename T> class Vector {
protected:
  size_t _size;
  size_t _cap;
  T *data;
  void expand() {
    if (_size < _cap)
      return;
    if (_cap < DEFAULT__cap) {
      _cap = DEFAULT__cap;
      data = new T[_cap];
    }
    _cap <<= 1;
    T *old = data;
    data = new T[_cap];
    for (int i = 0; i < _size; ++i) {
      data[i] = old[i];
    }
    delete[] old;
  }

public:
  Vector() : _size(0), _cap(0), data(nullptr) {}
  Vector(size_t _size) : _size(_size), _cap(_size), data(new T[_size]) {}
  Vector(size_t _size, size_t _cap) : _size(_size), _cap(_cap), data(new T[_cap]) {}
  ~Vector() {
    if(data) delete[] data;
  }

  T &operator[](const size_t pos) {
    return data[pos];
  }

  const T &operator[](const size_t pos) const {
    return data[pos];
  }

  
  size_t size() const {
    return _size;
  }

  void append(const T& v) {
    expand();
    data[_size++] = v;
  }

  size_t binary_search(int l, int r, const T &v) {
    if (r - l == 1) {
      if (data[l] > v)
        return l;
      return r;
    }
    if (data[(l + r) / 2] > v) {
      return binary_search(l, (l + r) / 2, v);
    } else {
      return binary_search((l+r)/2, r, v);
    }
  }

  void insert_ordered(const T& v){
    expand();
    int pos = binary_search(0, _size, v);
    for(int i = _size; i > pos; -- i){
      data[i] = data[i-1];
    }
    _size++;
    data[pos] = v;
  }

  void remove(int pos, int num) {
    for(int i = pos; i < _size - num; ++ i){
      data[i] = data[i + num];
    }
  }

  Vector<T> find_in_both(const Vector<T>& that){
    Vector<T> result;
    size_t p1 = 0;
    size_t p2 = 0;
    while(p1 < size() && p2 < that.size()){
      if(data[p1] == that[p2]){
        result.append(data[p1]);
        p1++;
        p2++;
      }else if(data[p1] < that[p2]){
        p1++;
      } else {
        p2++;
      }
    }
    return result;
  }
};
