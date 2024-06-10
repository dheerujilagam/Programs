const express = require('express');
let ContactFormModel = require('./mongo');
const cors = require('cors')
const app = express();

app.use(express.json());
app.use(cors())

app.post('/', (req,res) => {
    const data = req.body;
    console.log(data)
    ContactFormModel.insertMany(data);
});

app.get('/', (req,res) => {
    ContactFormModel.find({}).then((data)=>{
        res.send(data)
    }).catch((err)=>{
        res.send('error')
    })
});

app.listen(8000, () => {
    console.log('Server Started');
});