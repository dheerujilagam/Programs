void main() {
  // 1D List
  /* Syntax : List ? list_Name = List.filled(number of elements, E, growanle:boolean) */
  // List? gfg = List.filled(5, null, growable: false);
  // gfg[0] = 'Geeks';
  // gfg[1] = 'For';
  // gfg[2] = 'Geeks';

  // // Printing all the values in List
  // print(gfg);

  // // Printing value at specific position
  // print(gfg[2]);

  // 2D List
  var gfg = List.generate(3, (i) => List.generate(3, (j) => i + j));

  // Printing its value
  print(gfg);

  // 3D List
  var newList = List.generate(
      3, (i) => List.generate(3, (j) => List.generate(3, (k) => i + j + k)));

  print(newList);

  var temp = List.generate(3, (i) => List<String>.filled(3,''));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int val = i + j;
      temp[i][j] = val.toString();
    }
  }
  print(temp);
}
