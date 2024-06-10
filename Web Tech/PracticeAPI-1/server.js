const express = require('express');
const mongoose = require('mongoose');
const app = express();
const StudentDetail = require('./model');

app.use(express.json());

mongoose.connect('mongodb+srv://20A91A05F4:20A91A05F4@cluster0.he8wieh.mongodb.net/?retryWrites=true&w=majority', {
    useUnifiedTopology: true,
    useNewUrlParser: true
}).then(
    () => console.log('DB connected')
).catch(err => console.log(err));

app.post('/addStudent', async (req, res) => {
    const { name, roll } = req.body;
    try {
        const newStudent = new StudentDetail({
            name, roll
        });
        await newStudent.save();
        return res.json(newStudent);
    } catch (err) {
        console.log(err);
        return res.status(500).json({ error: 'Failed to create student detail' });
    }
});

app.get('/allData', async (req, res) => {
    try {
        const allData = await StudentDetail.find();
        return res.json(allData);
    } catch (err) {
        console.log(err);
    }
})

app.get('/allData/:roll', async (req, res) => {
    try {
      const roll = parseInt(req.params.roll);
      const allData = await StudentDetail.findOne({ roll: roll });
      return res.json(allData);
    } catch (err) {
      console.log(err);
    }
});
  
app.delete('/delete/:roll', async (req, res) => {
    try {
      const roll = parseInt(req.params.roll);
      const deletedData = await StudentDetail.findOneAndDelete({ roll: roll });
      return res.json(deletedData);
    } catch (err) {
      console.log(err);
    }
});

app.get('/', (req, res) => {
    res.send('Hello World...!!!');
});

app.listen(3000, () => console.log('Server running....!!!'));


// var monk = require('monk');
// var db = monk(`mongodb+srv://20A91A05F4:20A91A05F4@cluster0.he8wieh.mongodb.net/?retryWrites=true&w=majority/students`);
// db.then(() =>{
//   console.log("connection success");
// }).catch((e)=>{
//   console.log(e);
// })

// const det = db.get('details');
// app.get('/details',(res,rej)=>
// {
//     det.find({}).then((docs)=>
//     {
//         res.json(docs);
//     })
// })

// mongoose.connect("mongodb+srv://20A91A05F4:<password>@cluster0.he8wieh.mongodb.net/?retryWrites=true&w=majority",{
//  useUnifiedTopology : true,
//  useNewUrlParser : true
// })
// const db = mongoose.connection;

// db.once('open',function(){
//     console.log("connected");
// })