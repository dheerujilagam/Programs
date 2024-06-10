const fsPromises = require('fs').promises;
const path = require('path');

const fileOps = async () => {
    try {
        const data = await fsPromises.readFile(path.join(__dirname, 'sample.txt'), 'utf8');
        console.log(data);
        // unlink to delete the file
        await fsPromises.writeFile(path.join(__dirname, 'promiseWrite.txt'), data);
        await fsPromises.appendFile(path.join(__dirname, 'promiseWrite.txt'), '\n\nNice to meet you...!');
        await fsPromises.rename(path.join(__dirname, 'promiseWrite.txt'), path.join(__dirname, 'promiseNew.txt'));
        const newData = await fsPromises.readFile(path.join(__dirname, 'promiseNew.txt'), 'utf8');
        console.log(newData );
    } catch (err) {
        console.error(err);
    }
}

fileOps();

// fs.readFile('./practice/sample.txt', 'utf8', (err, data) => {
//     if(err) throw err;
//     console.log(data);
// })

// fs.readFile(path.join(__dirname, 'sample.txt'), 'utf8', (err, data) => {
//     if(err) throw err;
//     console.log(data);
// })


// fs.writeFile(path.join(__dirname, 'reply.txt'), 'Nice to meet you ', (err) => {
//     if(err) throw err;
//     console.log('Write Completed...!');
     
//     fs.appendFile(path.join(__dirname, 'reply.txt'), '\nYes it is...!', (err) => {
//         if(err) throw err;
//         console.log('Append Completed...!');
         
//         fs.rename(path.join(__dirname, 'reply.txt'), path.join(__dirname, 'newReply.txt'), (err) => {
//             if(err) throw err;
//             console.log('Rename Completed...!');
//         })
//     })
// })


//exit for uncaught errors
process.on('uncaughtException', err => {
    console.log(`There was an uncaught error, ${err}`)
    process.exit(1);
}) 