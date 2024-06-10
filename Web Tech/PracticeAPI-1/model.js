const mongoose = require('mongoose');

const StudentDetailSchema = mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    roll: {
        type: Number,
        required: true,
    }
});

const StudentDetail = mongoose.model('StudentDetail', StudentDetailSchema);

module.exports = StudentDetail;