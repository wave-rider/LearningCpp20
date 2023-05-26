//********************************************************
// The following code example is taken from the book
//  C++ Move Semantics - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppmove.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include <iostream>
#include <vector>

class MoveOnly {
  bool movedFrom{false};
 public:
  // constructors:
  MoveOnly() {
  }
  //...

  // copying disabled:
  MoveOnly(const MoveOnly&) = delete;
  MoveOnly& operator= (const MoveOnly&) = delete;

  // moving enabled:
  MoveOnly(MoveOnly&& m) noexcept {
    std::cout << "move\n";
    m.movedFrom = true;
  }
  MoveOnly& operator= (MoveOnly&& m) noexcept {
    std::cout << "moveassign\n";
    m.movedFrom = true;
    return *this;
  }

  bool moved() const {
    return movedFrom;
  }
};

void print(const std::vector<MoveOnly>& coll)
{
  std::cout << "coll: \n" ;
  for (const auto& elem : coll) {
    std::cout << (elem.moved() ? "- moved elem" : "- unmoved elem") << '\n';
  }
}

int main()
{
  std::vector<MoveOnly> coll;
  //...
  coll.push_back(MoveOnly{});     // OK, creates temporary object, which is moved into coll
  //...

  MoveOnly mo;
  //coll.push_back(mo);           // ERROR: can't copy mo into coll
  coll.push_back(std::move(mo));  // OK, moves mo into coll

  mo = std::move(coll[0]);        // move assign first element (still there with moved-from state)
  print(coll);

  std::vector<MoveOnly> coll2;
  for (auto& elem : coll) {            // note: non-const reference
    coll2.push_back(std::move(elem));  // move element to coll2
  }
  print(coll);
}

