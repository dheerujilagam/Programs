import 'dart:io';

void main() {
  num number = 3;
  print(number);
  number = 5;
  print(number);

  var name = stdin.readLineSync();
  print(name);
  name = "Jilagam";
  print(name);

  var age = stdin.readLineSync();
  print(age);
  print(name.runtimeType);
  print(age.runtimeType);

  dynamic location = stdin.readLineSync();
  print("location $location");
  location = 533239;
  print("location $location");

  print(age is num);
  print(age is! int);
  
  String text = "hello";
  print(text.indexOf("l"));
}
