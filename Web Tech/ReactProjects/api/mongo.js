const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/contactForms')
.then( () => {
    console.log('connected to DB');
})
.catch( () => {
    console.log('Falied to connect DB');
})

const newSchema = new mongoose.Schema({
    firstName: {
        type: String,
        required: true
    },
    lastName: {
        type: String,
        required: true
    },
    email: {
        type: String,
        required: true
    },
    message: {
        type: String,
        required: true
    }
});

const ContactFormModel =  mongoose.model("ContactFormModel",newSchema);
module.exports = ContactFormModel;