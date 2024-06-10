// console.log('message')
// logger()
// console.log(1)

// function logger() {
//     console.log(2)
//     finish()
//     console.log(3)
//     function finish() {
//         console.log('finished')
//     }
// }

/* Call back */

// function one() {
//     console.log('1')
// }

// function two(callback) {
//     setTimeout(() => {
//         console.log('2')
//         callback()
//     }, 0)
// }

// function three() {
//     console.log('3')
// }

// function four() {
//     setTimeout(() => {
//         console.log('4')
//     }, 0)
// }

// one()
// two(three)
// three()
// four() 

/* Promises */

// const promise = new Promise((resolve, reject) => {
//     resolve({user : 'Subhash'})
//     reject('Sever is under Maintainance')
// })

// promise
//     .then((data) => {
//         const user = data
//         console.log(data.user)
//         return fetch('https://jsonplaceholder.typicode.com/todos/1')
//     })
//     .then((todos) => {
//         console.log(todos)
//     })
//     .catch((err) => {
//         console.log(err)
//     })

// const newpromise = new Promise((resolve, reject) => {
//     setTimeout(() => resolve('This is my data from a server'), 2000)
// })

// newpromise.then((res) => {
//     console.log(res)
// }) 

// fetch('https://jsonplaceholder.typicode.com/todos/1')
//     .then((data) => {
//         return data.json()
//     })
//     .then((jsonedData) => {
//         console.log(jsonedData)
//     })
//     .catch((err) => {
//         console.log('Oh no something went wrong !!!')
//     })
//     .finally(() => {
//         console.log('Everything is done !!!')
//     })

/* Async & Await */

// async function getTodos() {
//     try {
//         const response = await fetch('https://jsonplaceholder.typicode.com/todos/1')
//         const data = await response.json()
//         console.log(data)
//         console.log(2)
//     } catch (err) {
//         console.log('Something went wrong !!!')
//         console.log(err)
//     }
// }

// getTodos()

// function add(a, b) {
//     return a + b;
// }

// let sum = add;

// function average(a, b, fn) {
//     return fn(a, b) / 2;
// }

// let result = average(10, 20, sum);

// console.log(result);

/* Anonymous Function and immediately invoking function*/

// let person = {
//     name : 'Harsih',
//     status : 'committed'
// };

// (function () {
//     console.log(person.name + ' is ' + person.status)
// })(person);

// let pharma = function() {
//     console.log('Aditya Engineering College <==> Aditya Pharmacy College')
// };

// pharma();

// function add(x, y) {
//     return x + y;
// }

// console.log(add.length); // 2
// console.log(add.prototype); // Object{}


function getUsers(callback) {
    setTimeout(() => {
      callback([
        { username: 'john', email: 'john@test.com' },
        { username: 'jane', email: 'jane@test.com' },
      ]);
    }, 1000);
  }
  
  function findUser(username, callback) {
    getUsers((users) => {
      const user = users.find((user) => user.username === username);
      callback(user);
    });
  }
  
  findUser('john', console.log);
  