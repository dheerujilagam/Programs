class Person {
  String? name;
  String? gender;
  int age = 0;

  Person(String nameC, String genderC, int ageC) {
    this.name = nameC;
    this.gender = genderC;
    this.age = ageC;
  }
  // Generative Constructor
  // Person(this.name, this.gender, this.age);

  Person.newBorn() {
    this.age = 0;
  }

  walking() => print('$name is walking');
  talking() => print('$name is talking');
}

void main() {
  var firstPerson = Person("Sarah", "Female", 25);
  print(firstPerson.name);
  firstPerson.walking();
  firstPerson.talking();
}
