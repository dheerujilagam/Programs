class person {
  String? name;
  int? age;

  //person(this.name, this.age);

  String? get personName => name;

  void set personAge(int val) {
    if (val < 0)
      print("Age can't be negative");
    else
      this.age = val;
  }
}

void main(List<String> args) {
  var p = person();
  p.name = 'Subhash';
  print(p.name);
  print(p.personName);
  p.personAge = 21;
  print(p.age);
}
