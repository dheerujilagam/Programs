// MAP

/*
  var mapName={
  key 1:  value 1,
  key 2 : value 2,
  ...
  key n : value n
} 
*/

/*
  constructor
  var mapName=map()
  type => var mapName= Map<dataType of key, dataType of value>()
  Adding values => mapName[key]=value
  Lenght => mapName.length

  Checking a key in a map => mapName.containsKey(key to check)

  Retrieving all the keys and values => key - mapName.keys 
                                        value - mapName.values

  Remove key value pair => mapNAme.remove(key of pair to be removed)

*/

void main() {
  var names = {'1': 'subhash', '2': 'subbu'};
  print(names);

  var marks = Map<int, String>();
  marks[1] = 'subhash';
  marks[2] = 'subbu';
  print(marks);
  print(marks[1]);
  print(marks[0]);

  var capitals = {
    'United States' : 'Washington D.C.',
    'England' : 'London',
    'China' : 'Beijing',
    'Germany' : 'Berlin',
    'Nigeria' : 'Abuja',
    'Egypt' : 'Cairo',
    'New Zealand' : 'Wellington'
   };

  // Retrieving all the keys 
  var allKeys = capitals.keys;    
  print("Keys: $allKeys");

  // Retrieving all the values
  var allValues = capitals.values;
  print("Values: $allValues");

  capitals.remove('China');      
  print(capitals);  
}
