// import 'dart:io';

// sets
void main() {
  var simpleset = {1, 2, 3};
  simpleset.add(4);
  print(simpleset);

  // Method 1
  var setName = <String>{'subhash'};
  setName.add('jilagam');
  print(setName);
  print(setName.length);
  // Method 2
  Set<String> set2 = {'subhash'};
  set2.addAll(setName);
  print(set2.length);
  print(set2);

  // remove()
  set2.remove('jilagam');
  print(set2);
  // contains() && containsAll()
  print(set2.contains('jilagam'));

  // intersection()
  var setOfFruits = {'apples', 'oranges', 'watermelon', 'grapes'};
  var setOfMoreFruits = {'oranges', 'kiwi', 'bananas'};
  var intersectionSet = setOfFruits.intersection(setOfMoreFruits);
  print(intersectionSet);

  // union
  var unionSet = setOfFruits.union(setOfMoreFruits);
     
  print(unionSet);
}
