#pragma once
template <typename T> class Node {
public:
  T data;
  Node* next;
  Node(): next(nullptr), data() {}
  explicit Node(const T &t): next(nullptr), data(t) {}
  explicit Node(Node* n): next(n), data() {}
  Node(const T &t, Node* n): next(n), data(t) {}
};

template <typename T> class List {
public:
  Node<T> *head;
  List(): head(new Node<T>()){};
  ~List() {
    Node<T>* p = head;
    while(p->next){
      head = p->next;
      delete p;
      p = head;
    }
  }

  size_t size() {
    size_t ret = 0;
    Node<T> const *p = head;
    while(p->next){
      ret++;
      p = p->next;
    }
    return ret;
  }

  void append(const T& v) {
    Node<T> *p = head;
    while(p->next) p = p->next;
    p->next = new Node<T>(v);
  }

  void prepend(const T& v) {
    auto *p = new Node<T>(v, head);
    head = p;
  }

  // Extremely slow. for debugging print only.
  T& operator[](const int & index){
    Node<T> *p = head;
    for(int i = 0; i < index && p; ++ i){
      p = p->next;
    }
    return p->data;
  }

  List<T> merge(const List<T> &that) const{
    Node<T> const* p1 = head;
    Node<T> const* p2 = that.head;
    List<T> result;
    while(p1 && p2){
      if(p1->data > p2->data){
        result.prepend(p2->data);
        p2 = p2->next;
      } else {
        result.prepend(p1->data);
        p1 = p1->next;
      }
    }
    return result;
  }
};
