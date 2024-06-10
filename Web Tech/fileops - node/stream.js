const fs = require('fs');

const rs = fs.createReadStream('./practice/promiseNew.txt', {encoding: 'utf8'});

const ws = fs.createWriteStream('./practice/newFile.txt');

// pipe is more efficient
rs.pipe(ws);

// rs.on('data', (datachunk) => {
//     ws.write(datachunk);
// })


// mkdir & rmdir
if(!fs.existsSync('./practice/new.txt')) {
    fs.mkdir('./practice/new.txt', (err) => {
        if(err) throw err;
        console.log('Directory created')
    })
}

if(fs.existsSync('./practice/new.txt')) {
    fs.rmdir('./practice/new.txt', (err) => {
        if(err) throw err;
        console.log('Directory removed')
    })
}