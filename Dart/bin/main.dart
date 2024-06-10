import 'dart:io';

void main() {
  print("Enter your Name : ");
  String? s = stdin.readLineSync();
  print("Hello $s");
  print("Enter your Age : ");
  int? age = int.parse(stdin.readLineSync()!);
  print("$s age is $age");
  String s1 = "Hello", s2 = "Subhash";
  print(s1 + s2);
}
