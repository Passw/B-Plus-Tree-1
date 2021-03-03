#include "b+tree.h"
#include <iostream>
#include <string>
using namespace BPlusTree;
using namespace std;

int main() {
  // Tree<double, string> t;
  // Tree<double, string>::iterator it;
  // Tree<double, string>::reverse_iterator rit;

  Tree<string, string> t;
  Tree<string, string>::iterator it;
  Tree<string, string>::reverse_iterator rit;

  t.insert("a", "A"); // insert (a,A) into B+Tree
  t.insert("b", "B"); // insert (b,B) into B+Tree

  t["c"] = "C"; // insert (c,C) into B+Tree
  t["d"] = "D"; // insert (d,D) into B+Tree

  cout << t["b"] << endl;
  try {
    cout << t.at("e")
         << endl; // e is not in B+Tree. It will throw out_of_range exception.
  } catch (std::out_of_range e) {
    cout << e.what() << endl;
  }

  cout << t.contains("a") << " " << t.contains("c") << endl;

  // ascending order
  for (it = t.begin(); it != t.end(); ++it) {
    cout << it.get_key() << " -> " << it.get_val() << endl;
    it.set_val("J"); // set the value to J
  }

  // rescending order
  cout << endl;
  t.erase(t.begin());
  for (rit = t.rbegin(); rit != t.rend(); rit++) {
    cout << rit.get_key() << " -> " << rit.get_val() << endl;
  }
}
