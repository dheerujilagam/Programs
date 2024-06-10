// import 'dart:io';

void main() {
  // constructor
  // var listName = List();
  // var listName = List<dataType>()

  var listOf = ['ktm', 'royal', 'hero'];
  print(listOf);

  // accessing
  print(listOf[1]);
  print(listOf.length);

  // add one element
  listOf.add('tvs');
  print(listOf);

  // adding multiple elements
  listOf.addAll(['toyota', 'maruti']);
  // insert() && insertAll()
  listOf.insert(1, 'jawa');
  //listOf.insertAll(1,['a','b']);
  print(listOf);

  // adding list of elements as elements
  var temp = [];
  temp.addAll(listOf);
  print(temp);

  // adding list in a list
  var newList = [];
  newList.add(listOf);
  print(newList);

  // removing at an index
  print(temp);
  temp.removeAt(0);
  print(temp);

  // indexOf() && clear()
  var ind = temp.indexOf('tvs');
  print(ind);
  temp.removeAt(ind);
  print(temp);
  temp.clear();
  print(temp);

  /* The List type has a method known as map(), not to be confused with the Map collection.
  map() maps all the items of a list to an expression or statement. 
  For instance, we could have a list of integers and we want to calculate the square of each integer in the list.*/

  // Syntax : listName.map((iterator)=> statement)

  var bikes = ['ktm', 'jawa', 'yamaha', 'bmw'];
  var it = bikes.map((i) => 'I Love $i bike.');
  print(it);

  /*You might have noticed that the output is not a list, as it does not have square brackets. 
  To transform the result of map() to a list we can use the toList() method. */

  var it1 = bikes.map((i) => "I love $i bike.").toList();
  print(it1);
}
